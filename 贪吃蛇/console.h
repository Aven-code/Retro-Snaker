#ifndef CONSOLE_H_
#define CONSOLE_H_
#include <Windows.h>

// 光标移到指定位置
void gotoxy(int x, int y);

//获取光标位置
void getxy(int *x, int *y);

//隐藏光标
 void cursor_hide(void);


 // 获取按键
int get_key(void);

// 程序中用到的按键枚举值
enum key
{
	NONE    = 0x0000,  // 没有键按下
	P_UPPER = 0x0050,  // 大写字母 P
	P_LOWER = 0x0070,  // 小写字母 p
	Q_UPPER = 0x0051,  // 大写字母 Q
	Q_LOWER = 0x0071,  // 小写字母 q
	UP      = 0xE048,  // 上箭头
	DOWN    = 0xE050,  // 下箭头
	LEFT    = 0xE04B,  // 左箭头
	RIGHT   = 0xE04D,  // 右箭头
	SPACE	= 0x0020,   //空格键
	ENTER	= 0x00d  //回车
};


/*
	功能：产生指定范围的随机数
	参数：最大值和最小值
	返回：一个随机数
*/
int random(int min,int max);
#endif