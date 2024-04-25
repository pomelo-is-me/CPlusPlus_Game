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
#include "header.h"

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
void game_table()
{
	int x,y;
	y = 5;
	SetColor(241);
	while(y<30)
	{
		gotoxy(0,y);
		for(int i=0;i<30;i++)
		{
			cout << "-";
		}
		y+=6;
	}
	y=0;
	x=5;
	while(x<30)
	{
		gotoxy(x,y);
		for(int i=0;i<30;i++)
		{
			gotoxy(x,y);
			cout << "|";
			y++;
		}
		y++;
		if(y>=30)
		{
			y=0;
		}
		x+=6;
	}
	return;
}
string answer()
{
	string an;
	ifstream dic;
	srand( time(NULL) );

	dic.open("dictionary.txt");

	if(dic.fail()){
        cout << "Error!!!\n";
        exit(0);
	}

	int ran,i=0;
	ran = rand()%661;//字數量
	while (i<=ran)
	{
		getline(dic, an);
		i++;
	}
	dic.close();
    return an;
}

void diction(vector<char> reply,string ans,int r,int *d)//word與ans比對，將結果存在d中
{
	for(int i=0;i<5;i++)
	{
		d[i] = 0;
	}
	for(int i=0;i<5;i++)//先判斷字母是否正確
	{
		for(int j=0;j<5;j++)
		{
			if(reply[i]==ans[j])
			{
				d[i] = 2;
			}
		}
	}
	for(int i=0;i<5;i++){//後判斷位置是否正確
        if(reply[i] == ans[i]){
            d[i] = 1;
        }
	}
}

void clear_line(int ly)
{
	int wx[5]={0,6,12,18,24};
	SetColor(7);
	for(int i=0;i<5;i++)
	{
		gotoxy(wx[4-i],ly);
		cout << "     ";gotoxy(wx[4-i],ly+1);
		cout << "     ";gotoxy(wx[4-i],ly+2);
		cout << "     ";gotoxy(wx[4-i],ly+3);
		cout << "     ";gotoxy(wx[4-i],ly+4);
		cout << "     ";
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
			cout << "|   |\n";gotoxy(x,y+4);
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
			cout << "| --┐\n";gotoxy(x,y+4);
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
			cout << "     \n";gotoxy(x,y+2);
			cout << "|    \n";gotoxy(x,y+3);
			cout << "|    \n";gotoxy(x,y+4);
			cout << "|__| \n";
			break;
		case'm':
			cout << "     \n";gotoxy(x,y+1);
			cout << "     \n";gotoxy(x,y+2);
			cout << " _ _ \n";gotoxy(x,y+3);
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
			cout << " ___ \n";gotoxy(x,y+2);
			cout << "|   |\n";gotoxy(x,y+3);
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
			cout << " ___|\n";gotoxy(x,y+4);
			cout << "     \n";
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

