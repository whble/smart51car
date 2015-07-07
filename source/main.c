/********************************************************************************************
**�ļ�˵��:		�������ļ�
**��Ȩ����:		EMO--E�ε���
**�� �� ��:		whble
**��    ��:		1.0V
**��	��:		http://taobao.xiangyunzone.com
**��    ̳:		http://www.honeygeek.org/
**��������:		2013-7-25
*********************************************************************************************
**�� �� ��:
**�޸�˵��:
**�޸İ汾:		
********************************************************************************************/

/*********************************����ͷ�ļ�************************************************/
#include "define.h"

/*********************************ȫ�ֱ���************************************************/
unsigned char code myname[] =     {" Hi,I'm WALL.E! "};
unsigned char code madeby[] =     {"Made By ZengYun!"};
unsigned char code begin[] =      {" OK,Let's Begin "};
unsigned char code selectmode[] = {"  Select  Mode  "};
unsigned char code clean[] =      {"                "};
unsigned char flag=0;
unsigned char date=0;
unsigned char pwm=0;
unsigned char wireless=0;
unsigned char IRCOM[7];
uchar uart1temp;
unsigned char b;

/********************************************************************************************
**��������:		uart()
**��������:		���ڳ�ʼ��������ΪwifiС���ṩ
**�������:		none
**�������:		none
**�� �� ֵ:		none
**�� �� ��:		whble
**��������:		2013-7-25
*********************************************************************************************
**�� �� ��:
**�޸�˵��:
********************************************************************************************/
// void uart()
// {
// 	TCLK=1;
// 	RCLK=1;
// 	
// 	TH2=0xFF;      //9600bps  11.0592MHz��ʱ��Ƶ��
// 	TL2=0xD9;	   //11.0592 TL2ΪDC  12MΪD9
// 	RCAP2H=0xFF;   //��ʽ1�ͷ�ʽ3�Ĳ����ʣ�fosc/(32-(65535-(RCAP2H,RCAP2L))
// 	RCAP2L=0xD9;
// 	
// 	//******************��������**************************************************//
// 	SCON=0x50;     //SM0  SM1  SM2  REN  TB8 RB8  TI RI
// 	PCON=0x00;     //TMOD=0; 
// 	TR2=1;
// 	ES=1;
// 	EA=1;
// 	ET2=1;
// }

/********************************************************************************************
**��������:		main()
**��������:		������
**�������:		none
**�������:		none
**�� �� ֵ:		none
**�� �� ��:		whble
**��������:		2013-7-25
*********************************************************************************************
**�� �� ��:
**�޸�˵��:
********************************************************************************************/
main()
{
/****************************************************************************************************************/
    IE = 0x81;                						//�������ж��ж�,ʹ�� INT0 �ⲿ�ж� ,ʹ�� INT1 �ⲿ�ж�
    TCON = 0x01;									// INT0 �ⲿ�ж� , INT1 �ⲿ�ж�,������ʽΪ���帺���ش���       
	TMOD=0x11;    									//��ʱ��T0/T1������ʽΪ	ģʽһ
	IP=0X01;         								//�ⲿ�ж�0Ϊ�߼����ȼ� 
	ET0=1; 											//������ʱ��0�ж�
    TH0=0xff; 										//���ó�ʼֵ
    TL0=0x9c; 										//��ʱ0.1mS 
	
    hight_votage=15;  								//����źų�ʼֵ��1.5ms���ݽ̶̳���Ƕ�Ϊ0 
	
	delay_20_us();                  				//I/O�ڳ�ʼ��
	
    delay1(10);                						//��ʱ
	
	//uart();										//wifi���ڳ�ʼ��
    lcd_init();										//1602Һ����ʼ��
    init_NRF24L01();								//��ʼ��NRF24L01 
	ReadDataLCD();									//Һ�������þ�������
	
	DisplayListChar(0, 0, clean);   				//�����Ļ                              
    DisplayListChar(0, 0, myname);					//��ʾ��Ʒ����
    DisplayListChar(0, 1, madeby);					//��ʾ��������
	delay1(1000);					
    DisplayListChar(0, 1, begin);					//������ɣ�����ϵͳ
	delay1(1000);
	DisplayListChar(0, 1, selectmode);				//��ʾѡ��ģʽ
	
/****************************************************************************************************************/
   while(1)											//��ѭ��
   { 
	   if(flag==1)									//ģʽѡ��
	   {
		Motor_Stop();
		delay1(200);
		DisplayListChar(0, 0, myname);
		DisplayListChar(0, 1, selectmode);
	   }
	   if(flag==2)									//ѭ��ģʽ
	   {
		//TR0=0;
		Motor_Stop();
		delay1(100);
		Tracking_mode();
	   }
	   if(flag==3)									//ң��ģʽ
	   {
	   // TR0=0;
		Motor_Stop();
		delay1(100);
		remote_control();
	   }
		if(flag==4)									//׷��ģʽ
	   {
	    // TR0=0;
		Motor_Stop();
		delay1(100);
		light_control();
	   }
		if(flag==5)									//������ģʽ
	   {
	    //	TR0=0;
		Motor_Stop();
		DisplayListChar(0, 0, "Ultrasonic  mode");
		DisplayListChar(0, 1, "WeiKongKeChuang!");
		delay1(100);
		Ultrasonic_mode();
	   }
		if(flag==6)									//�赸ģʽ
	   {
	    // TR0=0;
		Motor_Stop();
		delay1(100);
		Dance_mode();
	   }
/****************************************************************************************************************/
	   
		//�������	����ǰ�밴9�ż��������
		if(pwm==1)hight_votage=22;	 				//���
		if(pwm==2)hight_votage=8;	 				//�ұ�
		if(pwm==0)hight_votage=15;	 				//�м�
	    //����ģʽ������״̬
		if(wireless==1){
				DisplayListChar(0, 1, "  come in     ");
				receive();
			} 

   };//end while

}//end main


/********************************************************************************************
**��������:		void IR_IN(void) interrupt 0 
**��������:		�����ⲿ�жϷ�����
**�������:		none
**�������:		none
**�� �� ֵ:		none
**�� �� ��:		whble
**��������:		2013-7-25
*********************************************************************************************
**�� �� ��:
**�޸�˵��:
********************************************************************************************/


void IR_IN(void) interrupt 0 	 					//�ⲿ�жϷ������
{
  int m=0;
  unsigned char j,k,N=0;
     EX0 = 0;   
	 delay(15);
	 if (IRIN==1) 
     { EX0 =1;
	   return;
	  }                     						//ȷ��IR�źų���
  while (!IRIN)             						//��IR��Ϊ�ߵ�ƽ������9ms��ǰ���͵�ƽ�źš�
    {delay(1);}

  for (j=0;j<4;j++)         						//�ռ���������
  { 
   for (k=0;k<8;k++)        						//ÿ��������8λ
   {
   while (IRIN)             						//�� IR ��Ϊ�͵�ƽ������4.5ms��ǰ���ߵ�ƽ�źš�
     {delay(1);}
    while (!IRIN)           						//�� IR ��Ϊ�ߵ�ƽ
     {delay(1);}
     while (IRIN)           						//����IR�ߵ�ƽʱ��
      {
    delay(1);
    N++;           
    if (N>=30)
	 { EX0=1;
	 return;}                  						//0.14ms���������Զ��뿪��
      }                        						//�ߵ�ƽ�������                
     IRCOM[j]=IRCOM[j] >> 1;                  		//�������λ����0��
     if (N>=8) {IRCOM[j] = IRCOM[j] | 0x80;}  		//�������λ����1��
     N=0;
  }//end for k
 }//end for j
   
   if (IRCOM[2]!=~IRCOM[3])
   { EX0=1;
     return; }

   IRCOM[5]=IRCOM[2] & 0x0F;     					//ȡ����ĵ���λ
   IRCOM[6]=IRCOM[2] >> 4;       					//����4�Σ�����λ��Ϊ����λ

   if(IRCOM[5]>9)
    { IRCOM[5]=IRCOM[5]+0x37;}
   else
	  IRCOM[5]=IRCOM[5]+0x30;

   if(IRCOM[6]>9)
    { IRCOM[6]=IRCOM[6]+0x37;}
   else
	  IRCOM[6]=IRCOM[6]+0x30;


/*************����ң�����ݱ���********/	 
	 switch(IRCOM[2])
	 {
	 case 0x45: pwm=1;  break;
     case 0x46: pwm=0;  break;
	 case 0x47: pwm=2;  break;
	 
	 case 0x44: date=3;  break;	   					//������ת
	 case 0x40: date=4;  break;	   					//ǰ��
	 case 0x43: date=5;  break;	   					//������ת
	 
	 case 0x07: date=6;  break;	   					//��ת
	 case 0x15: date=7;  break;	   					//ֹͣ
	 case 0x09: date=8;  break;	   					//��ת
    
	 case 0x16: date=9; flag=1; break;
	 case 0x19: date=10; break;	   					//����
	 case 0x0d: wireless=11; break;					//����ģʽ���ؿ���

	 case 0x0c: date=12; flag=2; break;
	 case 0x18: date=13; flag=3;break;
	 case 0x5e: date=14; flag=4;break;

	 case 0x08: date=15; flag=5; break;
	 case 0x1c: date=16; flag=6;break;	 
     case 0x5a: date=17; break;

	 case 0x42: flag=7;wireless=0; break;
	 case 0x52: flag=7;wireless=1; break;
	 case 0x4a: date=20;TR0=!TR0; break;
	 
	 }

    EX0 = 1; 
} 


/********************************************************************************************
**��������:		void uartReceive_1(void) interrupt 4 
**��������:		���ڽ����жϷ�����������wifi����
**�������:		none
**�������:		none
**�� �� ֵ:		none
**�� �� ��:		whble
**��������:		2013-7-25
*********************************************************************************************
**�� �� ��:
**�޸�˵��:
********************************************************************************************/
// void uartReceive_1(void) interrupt 4   				//���ڽ����жϷ�����������wifi����
// {
// 	if(RI==1)
// 	{
// 		RI=0;
// 		uart1temp=SBUF;
// 		switch(uart1temp)
// 		{
// 			case 0x34:								//ǰ��
// 				IN1=1;IN2=0;IN3=1;IN4=0;
// 				break;
// 			case 0x32:								//����
// 				IN1=0;IN2=1;IN3=0;IN4=1;
// 				break;	
// 			case 0x31:								//��ת
// 				IN1=0;IN2=0;IN3=1;IN4=0;
// 				break;
// 			case 0x33:								//��ת
// 				IN1=1;IN2=0;IN3=0;IN4=0;
// 				break;
// 			case 0x30:								//ֹͣ
// 				IN1=0;IN2=0;IN3=0;IN4=0;
// 				break;		
// 		}		
// 	}
// 		
// }