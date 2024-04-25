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

int main(int argc, char** argv)
{
	system("mode con cols=60 lines=20");
	system("color F0");
	HideCursor();
	srand(time(NULL));
	deque<pair<int,int>> ob;
	ob.push_back(make_pair(57,2));
	int op,r,score=0;
	int color_01 = 250;
	int x=5,y=10,z=0,m=15,k=5;
	double time=30,speed;
	int u1[5]={4,5,6,7,3},p1[5]={6,5,4,3,7};//障礙大小

	char test;
	while(1){
		ob.clear();
		ob.push_back(make_pair(57,2));

		word('f',15,3,color_01);
		word('l',21,3,color_01);gotoxy(22,4);cout << " ";gotoxy(25,7);cout << "_";
		word('a',26,3,color_01);
		word('p',32,3,color_01);
		word('p',37,3,color_01);
		word('y',42,3,color_01);gotoxy(43,4);cout << " ";gotoxy(47,4);cout << " ";
		word('s',17,8,color_01);
		word('t',23,8,color_01);
		word('a',29,8,color_01);
		word('r',35,8,color_01);
		gotoxy(19,16);cout << "Start...click[SPACE]";

		op = '1';
		while(1){
			if(kbhit()){
				op = getch();
			}
			if(op==' '){
				system("cls");
				break;
			}
		}
		//遊戲開始
		background();
		score=0;
		speed=1;
		time=30;
		m=15;
		while(1){
			SetColor(240);
			gotoxy(0,0);cout  << "              ";//清空之前的數值
			gotoxy(0,0);cout  << "speed: " << speed;
			gotoxy(50,0);cout << "score:" << score;
			SetColor(250);
			ob1(ob);
            /*
			if(y<3){ //測試用作弊
				score+=10;
			}
            */
			if(score%10==0 && score!=0){//讓間格隨分數與時間變小
				time-=5;
				if(time<0){
					time = 0;
				}
				speed+=0.25;
				if(speed>2.5){
					speed = 2.5;
				}
				m--;
				if(m<10){
                    m=10;
				}
				score++;
			}

			if(57-ob[ob.size()-1].first>m){
				ob.push_back(make_pair(57,rand()%k));//推入障礙座標
			}

			if(ob.size()==0){
				break;
			}
			ship(x,y,z);

			for(int i=0;i<ob.size();i++){
				if(ob[i].first<=x && x<=ob[i].first+2){//判斷是否撞到
					if( (2<y && y<=2+u1[ob[i].second]+1) || (y<17 && y>=17-p1[ob[i].second]) ){
						Sleep(1000);
						system("cls");
						goto end;
					}
					if(x==ob[i].first){
                        score++;
					}

				}
			}

			Sleep(time);//遊戲更新時間，畫面速度
		}
		//結束
		end:
		system("cls");
		int x1=rand()%40+10,y1=rand()%15+3;
		gotoxy(x1,y1);cout << "You lose\n";
		gotoxy(x1,y1+1);cout << "score:" << score;
		Sleep(1000);
		system("cls");
	}
}
