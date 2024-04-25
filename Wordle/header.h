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

#ifndef HEADER_H
#define HEADER_H

using namespace std;

void HideCursor();
void SetColor(int color);
void gotoxy(int xpos, int ypos);
void game_table();
void word(char w,int x,int y,int color);
void diction(vector<char> word,string ans,int r,int *d);
void clear_line(int ly);//清除整排
string answer();
#endif
