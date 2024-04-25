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
#include <string>
#include <fstream>
#include <math.h>
#include<deque>
#include <iomanip>
#ifndef HEADER_H
#define HEADER_H

using namespace std;

void background();
void HideCursor();
void SetColor(int color);
void gotoxy(int xpos, int ypos);
void game_table();
void word(char w,int x,int y,int color);
void ob1(deque<pair<int,int>> &ob);
void ship(int &x,int &y,int &z);

#endif
