#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <array>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <math.h>
#include<deque>
#include <iomanip>
#include "header.h"
#define COLS 60
#define LINES 20

using namespace std;

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void SetColor(int color = 7)
{
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}
void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void background()
{
	SetColor(242);
	int x=0,y=2;
	for(int i=0;i<60;i++)
	{
		gotoxy(x+i,y);//2;
		cout << "-";
		gotoxy(x+i,y+LINES-5);//17
		cout << "-";
	}
	SetColor(250);
}
void ship(int &x,int &y,int &z)//玩家操控的角色動作
{
	SetColor(240);
	char op;
	gotoxy(x,y);cout << " ";

	if(z%5==0){
		y++;
	}

	if(kbhit()){
		op = getch();
	}
	if(op==' '){
		y-=2;
	}

	if(y<=3){
		y=3;
	}else if(y>=16){
		y=16;
	}
    /*
	if(op == '='){	//測試用作弊
		y=1;
	}
    */
	gotoxy(x,y);cout << "*";

	z++;
	if(z>100){
        z=0;
	}
	SetColor(250);
}

void ob1(deque<pair<int,int>> &ob)//0 是up,1是down
{
	SetColor(250);
	int x=0,y[2]={3,16},z[2]={1,-1};
	int u1[5]={4,5,6,7,3},p1[5]={6,5,4,3,7};//障礙大小
	deque<pair<int,int>>::iterator it;

	it = ob.begin();

	for(int z=0;z<ob.size();z++){
		x = (*it).first;

		for(int i=0;i<=u1[(*it).second];i++){
		 	gotoxy(x,3+i);cout << "|";
			gotoxy(x+1,3+i);cout << " ";
			gotoxy(x+1,3+u1[(*it).second]);cout << "_";
			gotoxy(x+2,3+u1[(*it).second]);cout << " ";
			gotoxy(x+2,3+i);cout << "|";
			gotoxy(x+3,3+i);cout << " ";//清除前一個
		}
		for(int i=0;i<p1[(*it).second];i++){
		 	gotoxy(x,16-i);cout << "|";
			gotoxy(x+1,16-i);cout << " ";
			gotoxy(x+1,16-p1[(*it).second]);cout << "_";
			gotoxy(x+2,16-p1[(*it).second]);cout << " ";
			gotoxy(x+2,16-i);cout << "|";
			gotoxy(x+3,16-i);cout << " ";//清除前一個
		}
		//使結束的消失
		if((*it).first<=0){
			for(int i=0;i<=3;i++){
				for(int j=3;j<=16;j++){
					gotoxy(i,j);cout << " ";
				}
			}
			ob.pop_front();
		}
		(*it).first--;
		it++;
		if((*it).first==-1){
			break;
		}
	}
}





void word(char w,int x,int y,int color)
{
	gotoxy(x,y);
	SetColor(color);
	switch(w)
	{
		case'a':
			cout << "     \n";gotoxy(x,y+1);
			cout << "     \n";gotoxy(x,y+2);
			cout << "  _  \n";gotoxy(x,y+3);
			cout << " /_\\ \n";gotoxy(x,y+4);
			cout << "/   \\\n";
			break;
		case'b':
			cout << "     \n";gotoxy(x,y+1);
			cout << " __  \n";gotoxy(x,y+2);
			cout << "|  | \n";gotoxy(x,y+3);
			cout << "|---|\n";gotoxy(x,y+4);
			cout << "|___|\n";
			break;
		case'c':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "|    \n";gotoxy(x,y+3);
			cout << "|    \n";gotoxy(x,y+4);
			cout << "|___ \n";
			break;
		case'd':
			cout << "     \n";gotoxy(x,y+1);
			cout << " __  \n";gotoxy(x,y+2);
			cout << "|  \\ \n";gotoxy(x,y+3);
			cout << "|   ▏\n";gotoxy(x,y+4);
			cout << "|__/ \n";
			break;
		case'e':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "|    \n";gotoxy(x,y+3);
			cout << "|--- \n";gotoxy(x,y+4);
			cout << "|___ \n";
			break;
		case'f':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "|    \n";gotoxy(x,y+3);
			cout << "|--- \n";gotoxy(x,y+4);
			cout << "|    \n";
			break;
		case'g':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "|    \n";gotoxy(x,y+3);
			cout << "| --|\n";gotoxy(x,y+4);
			cout << "|___|\n";
			break;
		case'h':
			cout << "     \n";gotoxy(x,y+1);
			cout << "     \n";gotoxy(x,y+2);
			cout << "|   |\n";gotoxy(x,y+3);
			cout << "|---|\n";gotoxy(x,y+4);
			cout << "|   |\n";
			break;
		case'i':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "  |  \n";gotoxy(x,y+3);
			cout << "  |  \n";gotoxy(x,y+4);
			cout << " --- \n";
			break;
		case'j':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "  |  \n";gotoxy(x,y+3);
			cout << " ||  \n";gotoxy(x,y+4);
			cout << " ``  \n";
			break;
		case'k':
			cout << "     \n";gotoxy(x,y+1);
			cout << "| /  \n";gotoxy(x,y+2);
			cout << "|/   \n";gotoxy(x,y+3);
			cout << "|\\   \n";gotoxy(x,y+4);
			cout << "| \\  \n";
			break;
		case'l':
			cout << "     \n";gotoxy(x,y+1);
			cout << "|    \n";gotoxy(x,y+2);
			cout << "|    \n";gotoxy(x,y+3);
			cout << "|    \n";gotoxy(x,y+4);
			cout << "|__| \n";
			break;
		case'm':
			cout << "     \n";gotoxy(x,y+1);
			cout << "     \n";gotoxy(x,y+2);
			cout << " ___ \n";gotoxy(x,y+3);
			cout << "| | |\n";gotoxy(x,y+4);
			cout << "| | |\n";
			break;
		case'n':
			cout << "     \n";gotoxy(x,y+1);
			cout << "     \n";gotoxy(x,y+2);
			cout << "|\\  |\n";gotoxy(x,y+3);
			cout << "| \\ |\n";gotoxy(x,y+4);
			cout << "|  \\|\n";
			break;
		case'o':
			cout << "     \n";gotoxy(x,y+1);
			cout << "     \n";gotoxy(x,y+2);
			cout << " ___ \n";gotoxy(x,y+3);
			cout << "|   |\n";gotoxy(x,y+4);
			cout << "|___|\n";
			break;
		case'p':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "|   |\n";gotoxy(x,y+3);
			cout << "|--- \n";gotoxy(x,y+4);
			cout << "|    \n";
			break;
		case'q':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "|   |\n";gotoxy(x,y+3);
			cout << "|__\\|\n";gotoxy(x,y+4);
			cout << "    \\\n";
			break;
		case'r':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "|___|\n";gotoxy(x,y+3);
			cout << "|  \\ \n";gotoxy(x,y+4);
			cout << "|   \\\n";
			break;
		case's':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "|___ \n";gotoxy(x,y+3);
			cout << "    |\n";gotoxy(x,y+4);
			cout << "----  \n";
			break;
		case't':
			cout << "     \n";gotoxy(x,y+1);
			cout << "_____\n";gotoxy(x,y+2);
			cout << "  |  \n";gotoxy(x,y+3);
			cout << "  |  \n";gotoxy(x,y+4);
			cout << "  |  \n";
			break;
		case'u':
			cout << "     \n";gotoxy(x,y+1);
			cout << "     \n";gotoxy(x,y+2);
			cout << "|   |\n";gotoxy(x,y+3);
			cout << "|   |\n";gotoxy(x,y+4);
			cout << "|___|\n";
			break;
		case'v':
			cout << "     \n";gotoxy(x,y+1);
			cout << "     \n";gotoxy(x,y+2);
			cout << "\\   /\n";gotoxy(x,y+3);
			cout << " \\_/ \n";gotoxy(x,y+4);
			cout << "  .  \n";
			break;
		case'w':
			cout << "     \n";gotoxy(x,y+1);
			cout << "     \n";gotoxy(x,y+2);
			cout << "|   |\n";gotoxy(x,y+3);
			cout << "| _ |\n";gotoxy(x,y+4);
			cout << "|/ \\|\n";
			break;
		case'x':
			cout << "     \n";gotoxy(x,y+1);
			cout << " \\  /\n";gotoxy(x,y+2);
			cout << "  \\/ \n";gotoxy(x,y+3);
			cout << "  /\\ \n";gotoxy(x,y+4);
			cout << " /  \\\n";
			break;
		case'y':
			cout << "     \n";gotoxy(x,y+1);
			cout << "\\   /\n";gotoxy(x,y+2);
			cout << " \\ / \n";gotoxy(x,y+3);
			cout << "  |  \n";gotoxy(x,y+4);
			cout << "  |  \n";
			break;
		case'z':
			cout << "     \n";gotoxy(x,y+1);
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "   / \n";gotoxy(x,y+3);
			cout << "  /  \n";gotoxy(x,y+4);
			cout << " /__ \n";
			break;
		default:
			break;
	}
}

