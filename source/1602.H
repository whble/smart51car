/********************************************************************************************
**�ļ�˵��:		1602����ͷ�ļ�
**��Ȩ����:		EMO--E�ε���
**�� �� ��:		whble
**��    ��:		1.0V
**��    վ:		http://taobao.xiangyunzone.com
**��������:		2013-7-25
*********************************************************************************************
**�� �� ��:
**�޸�˵��:
**�޸İ汾:
********************************************************************************************/
#ifndef _1602_H
#define _1602_H

/*********************************��������**************************************************/
extern void lcd_init();
extern void DisplayOneChar(unsigned char X, unsigned char Y, unsigned char DData);
extern void DisplayListChar(unsigned char X, unsigned char Y, unsigned char code *DData);
extern void WriteCommandLCD(unsigned char WCLCD,BuysC);
extern unsigned char ReadDataLCD(void);
extern unsigned char ReadStatusLCD(void);
extern void WriteDataLCD(unsigned char WDLCD);
#endif