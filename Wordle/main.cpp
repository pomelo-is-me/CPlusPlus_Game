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
#include <string>
#include <list>
#include <fstream>
#include "header.h"

using namespace std;

int main(int argc, char** argv)
{
	HideCursor();
	int gt_pos[5]={0,6,12,18,24};
	int x,y,r=-1,sx[3]={31,34,28},sy[3]={9,11,13},ss=0;
	char enter,select,select1;
	vector<char> reply;
	string ans,check;
	int win=0,win_ct=0;
	int *comp;
	comp = new int[5]();
start:
	system("mode con cols=60 lines=20");
	system("color F8");
	while(1)
	{
	    //遊戲主畫面
		word('w',15,0,240);
		word('o',20,0,240);
		word('r',25,0,240);
		word('d',30,0,240);
		word('l',35,0,240);
		word('e',40,0,240);
		SetColor(241);gotoxy(17,7);cout << "select mode:";
		SetColor(241);gotoxy(20,9);cout << "normal mode";
		SetColor(241);gotoxy(20,11);cout << "customize mode";
		SetColor(241);gotoxy(20,13);cout << "tutorial";
		SetColor(241);gotoxy(20,15);cout << "...select[↑↓]";
		SetColor(241);gotoxy(20,17);cout << "...click[SPACE]";
		select = getch();
		if( (0<=select && select<=127) && select != ' ') //判別箭頭間鍵或空白
		{
            continue;
		}

		if(sx[ss]==31 && sy[ss]==9 && select==' ')
		{
			goto normal;
		}
		else if(sx[ss]==34 && sy[ss]==11 && select==' ')
		{
			goto cus;
		}
		else if(sx[ss]==28 && sy[ss]==13 && select==' ')
		{
			goto tutorial;
		}
		if(select1=getch())
		{
			switch(select1)
			{
				case 80:
					gotoxy(sx[ss],sy[ss]);
					cout << " ";
					if(ss+1<3)
						ss++;
					gotoxy(sx[ss],sy[ss]);
					cout << "<";
					break;
				case 72:
					gotoxy(sx[ss],sy[ss]);
					cout << " ";
					if(ss-1>=0)
						ss--;
					gotoxy(sx[ss],sy[ss]);
					cout << "<";
					break;
				default:
					break;
			}
		}
	}

//開始遊戲
normal:
	system("mode con cols=30 lines=30");
	ans = answer();
	system("color F8");
	x=0;
	y=0;
	game_table();
	//cout <<ans << endl; 輸出答案
	while(1)
	{
		enter = getch();

		if(y>4)//結束遊戲
		{
			break;
		}

		if (enter =='\b' && x>0) //刪除輸入
		{
			SetColor(240);
			gotoxy(gt_pos[x-1],gt_pos[y]);
			cout << "     ";gotoxy(gt_pos[x-1],gt_pos[y]+1);
			cout << "     ";gotoxy(gt_pos[x-1],gt_pos[y]+2);
			cout << "     ";gotoxy(gt_pos[x-1],gt_pos[y]+3);
			cout << "     ";gotoxy(gt_pos[x-1],gt_pos[y]+4);
			cout << "     ";
			if(x-1>=0)
				x--;
			if(r-1>=0)
				r--;
			reply.pop_back();
			continue;
		}

		if(x==5&&enter==' ')
		{
			diction(reply,ans,r,comp);//比對輸入與答案
			clear_line(gt_pos[y]);
			win_ct=0;
			for(int i=0;i<5;i++)//輸出不同顏色提示玩家
			{

				if(comp[i]==0)
				{
					word(reply[i],gt_pos[i],gt_pos[y],240);
				}
				else if(comp[i]==1)
				{
					word(reply[i],gt_pos[i],gt_pos[y],161);
					win_ct++;
				}
				else if(comp[i]==2)
				{
					word(reply[i],gt_pos[i],gt_pos[y],224);
				}
			}

			x=0;
			y++;

			if(win_ct == 5){ //若提前答對則結束遊戲
                Sleep(1000);
                system("cls");
                system("color F8");
                SetColor(240);
                gotoxy(10,14);
                cout << "恭喜答對!!!";
                gotoxy(5,16);
                system("pause");
                reply.clear();
                break;
			}
			reply.clear();
			continue;
		}

		if( (enter<65 || enter>122) || (91<=enter && enter<=96) ) //只能輸入英文字母
		{
			continue;
		}


		if(x<=4)
		{
			reply.push_back(enter);
			r++;
		}else if(x>4)
		{
			x=5;
			continue;
		}
		word(enter,gt_pos[x],gt_pos[y],240);
		x++;
	}


end:
	system("cls");
	gotoxy(6,14);
	system("color F8");
	SetColor(240);
	cout << "answer is : " << ans << endl;
	gotoxy(6,20);
	system("pause");
	goto start;
tutorial:
	system("mode con cols=50 lines=30");
	system("cls");
	gotoxy(12,6);cout << "這是一個猜英文單字的遊戲";
	gotoxy(5,9);cout << "猜對那個字母但在錯誤位子的話會顯示黃色";
	gotoxy(12,12);cout << "如果在對的位置就會是綠色";
	gotoxy(12,15);cout << "想辦法在有限次數猜出來吧!";
	gotoxy(12,18);cout << "遊戲中按下[space]是輸入!按下[Backspace]是刪除!";
	gotoxy(12,21);system("pause");
	goto start;
cus:
	system("mode con cols=50 lines=30");
	system("cls");
	gotoxy(16,12);cout << "還未開放!!";
	gotoxy(12,22);system("pause");
	goto start;
}

