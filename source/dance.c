/********************************************************************************************
**�ļ�˵��:		�赸ģʽ�����ļ�
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
unsigned char hight_votage;
/********************************************************************************************
**��������:		void Dance_mode()
**��������:		�赸ģʽ����
**�������:		none
**�������:		none
**�� �� ֵ:		none
**�� �� ��:		whble
**��������:		2013-7-25
*********************************************************************************************
**�� �� ��:
**�޸�˵��:
********************************************************************************************/
void Dance_mode()
{
	 
  DisplayListChar(0, 0, "  Dance   mode  ");
  DisplayListChar(0, 1, "  Lalalala....  "); 
  Motor_Stop();
  delay_ms(500);
  TR0=1;
  hight_votage=15;
  while(1)				
  {

   if(flag!=6) break;													//�ж�ģʽ�Ƿ������Ӻ���

/**************************************************�����赸����*************************************/	  
   //��������
 	Motor_GoHead();
	send();
	hight_votage=20;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=10;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=20;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=10;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	//�赸��ʼ

 	Motor_GoLeft();
	send();
	delay_ms(600);
	Motor_GoRight();
	send();
	delay_ms(600);
 	Motor_GoLeftFast();
	send();
 	delay_ms(600);
 	Motor_GoRightFast();
	send();
	delay_ms(600);

	//�赸����

	Motor_GoHead();
	send();
	hight_votage=20;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=10;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=20;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);

	Motor_GoHead();
	send();
	hight_votage=10;
	delay_ms(1000);

 	Motor_GoBack();
	send();
	hight_votage=15;
	delay_ms(1000);
   }
}