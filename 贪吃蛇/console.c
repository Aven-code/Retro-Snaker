#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "console.h"
#include <time.h>
#include <stdlib.h>

/*
	系统函数的源代码
*/

/*光标定位*/
void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);	
	SetConsoleCursorPosition(GetStdHandle(STD_INPUT_HANDLE), pos);
}

/*获取光标*/
void getxy(int *x, int *y)
{
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &screen_buffer_info);
	*x = screen_buffer_info.dwCursorPosition.X;
	*y = screen_buffer_info.dwCursorPosition.Y;
}


/*光标隐藏*/
 void cursor_hide(void)
{
	CONSOLE_CURSOR_INFO cci;

	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}



// 获取按键
int get_key(void)
{
	if(_kbhit())	//如果有键按下
	{
		int ch=_getch();//保存一个值
		if(ch ==0x0 || ch==0xe0)//是否为两个值
		{
			ch=_getch();
			switch(ch)
			{
				case 0x48:
					return UP;
				case 0x50:
					return DOWN;
				case 0x4B:
					return LEFT;
				case 0x4D:
					return RIGHT;
				default:
					return NONE;
			}
		}else	//只有一个键值
		{
			switch(ch)
			{
				case 0x50:
					return P_UPPER;
				case 0x70:
					return P_LOWER;
				case 0x51:
					return Q_UPPER;	//按Q退出
				case 0x71:
					return Q_LOWER;
				case 0x20:
					return SPACE;
				case 0xd:
					return ENTER;
				default:
					return NONE;
			}
		}
	}
	return NONE;
}


/*
	功能：产生指定范围的随机数
	参数：最大值和最小值
	返回：一个随机数
*/
int random(int min,int max)
{
	int val;
	//srand((unsigned int)time(NULL));main函数中需要调用的
	val=rand()%(max-min+1)+min;
	return val;
}