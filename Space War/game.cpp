#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "game.h"

using namespace std;

void moved(int &dc,int &ac,int &we)
{
	dc++;
	reappear(dc,ac);
	we=0;
}

void movea(int &dc,int &ac,int &we)
{
	ac++;
	reappear(dc,ac);
	we=0;
}

void weapon(int &dc,int &ac,int &we,char weuse)
{
	we++;
	if(weuse!='9'){
		for(int j=0;j<3;j++){//子彈持續
			system("cls");
			puts("");
			for(int i=0;i<dc-ac;i++){
				cout << " ";
			}
			for(int i=0;i<13;i++){
				cout << " " << weuse << endl;
				for(int i=0;i<dc-ac;i++){
					cout << " ";
				}
			}
		}
		puts("");
		reappear(dc,ac);
		system("cls");
	}else{//柚型武器
		for(int j=0;j<3;j++){//子彈持續
			system("cls");
			puts("");
			for(int i=0;i<dc-ac;i++){
				cout << " ";
			}
			for(int i=0;i<13;i++){
				cout << "柚" << endl;
				for(int i=0;i<dc-ac;i++){
					cout << " ";
				}
			}
		}
		puts("");
		reappear(dc,ac);
		system("cls");
	}
}

void reappear(int &dc,int &ac)
{
	linechange(14);
	for(int i=0;i<dc-ac;i++){
		cout << " ";
	}
	cout << "|^|";
}

void space(int s)
{
	for(int i=0;i<s;i++){
		cout << " ";
	}
}

void linechange(int n)
{
	for(int i=0;i<n;i++){
		puts("");
	}
}

