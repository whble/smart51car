/********************************************************************************************
**�ļ�˵��:		׷�������ļ�
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
#include "define.h"


/********************************************************************************************
**��������:		light_control()
**��������:		׷�⺯��
**�������:		none
**�������:		none
**�� �� ֵ:		none
**�� �� ��:		whble
**��������:		2013-7-25
*********************************************************************************************
**�� �� ��:
**�޸�˵��:
********************************************************************************************/
 void light_control()
  {
	while(1)
	{
	DisplayListChar(0, 0, " light  control ");
	DisplayListChar(0, 1, "                ");

	if(flag!=4)break;                      							//�ж��Ƿ�����׷�����
	if(pwm==1)hight_votage=22;
	if(pwm==2)hight_votage=8;
	if(pwm==0)hight_votage=15;
	if(light_left==0&&light_right==0)      							//׷��ǰ��	  
	{
	Motor_GoHead();	
	DisplayListChar(0, 1, "  light gohead  ");	
	}
	if(light_left==1&&light_right==0)	   							//׷����ת
	{
	Motor_GoRightFast();	
	DisplayListChar(0, 1, "  light goright ");	   
	}
	if(light_left==0&&light_right==1)	   							//׷����ת
	{
	Motor_GoLeftFast();	
	DisplayListChar(0, 1, "  light goleft  ");	   
	}
	if(light_left==1&&light_right==1)     							//׷��ֹͣ	  
	{
	Motor_Stop();	
	DisplayListChar(0, 1, "  light  stop   ");	
	}	
   }
}//end light_control