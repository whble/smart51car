/********************************************************************************************
**�ļ�˵��:		����ң�������ļ�
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

/********************************************************************************************
**��������:		remote_control()
**��������:		����ң��ģʽ����
**�������:		none
**�������:		none
**�� �� ֵ:		none
**�� �� ��:		whble
**��������:		2013-7-25
*********************************************************************************************
**�� �� ��:
**�޸�˵��:
********************************************************************************************/
void remote_control()
{  
    TR0=1;  															//��ʱ��0 ����λ
	while(1)
	{
	DisplayListChar(0, 0, " remote control ");
	DisplayListChar(0, 1, "                ");
	if(flag!=3)break; 
    if(pwm==1)hight_votage=22;
	if(pwm==2)hight_votage=8;
	if(pwm==0)hight_votage=15;
	if(date == 3)	   													//��ת��
	{
		
		Motor_GoLeftFast();	
		DisplayListChar(0, 1, "   GoLeftFast   ");
	}
	else if(date == 4)	   												//ǰ��
	{	
		
		Motor_GoHead();
		DisplayListChar(0, 1, "     GoHead     ");	
	}
	else if(date == 5)	   												//�Ҽ�ת��
	{
		Motor_GoRightFast();
		DisplayListChar(0, 1, "  GoRightFast   ");	
	}
	else if(date == 6)	   												//��ת
	{
		
		Motor_GoLeft();
		DisplayListChar(0, 1, "     GoLeft     ");	
	}
	else if(date == 7)	   												//ͣ��
	{
	
		Motor_Stop();
		DisplayListChar(0, 1, "      Stop      ");	
	}
	else if(date == 8)	   												//��ת
	{
		Motor_GoRight();
		DisplayListChar(0, 1, "     GoRight    ");	
	}
	else if(date == 10)	   												//����
	{

		Motor_GoBack();	
		DisplayListChar(0, 1, "     GoBack     ");
	}   

    }
}
//end remote_control
