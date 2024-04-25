#include <iostream>
#ifndef GAME_H
#define GAME_H

void moved(int &dc,int &ac,int &we); //右移
void movea(int &dc,int &ac,int &we); //左移
void weapon(int &dc,int &ac,int &we,char weuse); //武器
void reappear(int &peard,int &peara); //重現
void space(int s); //印空格
void linechange(int n);  //換行

#endif

