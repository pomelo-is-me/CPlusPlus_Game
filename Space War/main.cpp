#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "game.h"
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include <fstream>
#include <windows.h>

using namespace std;


void HideCursor()
{ CONSOLE_CURSOR_INFO cursor_info = {1, 0};
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

int main(int argc, char** argv)
{
	HideCursor();
	system("mode con cols=60 lines=15");
	int dc=0, ac=0, ene[100],score=0,ed=0,we=0,cs,x[15],mn=2,mx=4,highscore=0;
	int destroy=0,record[15],rh=0,de=0,shop[10],shop_help[10],ene_amt_i;//shop 使用 , shop_help 解鎖
	int money=1000000;//錢
	int money_chec[3] = {150 , 250 , 500};
	string ene_amt_s;
	string weapon_text[3] = {"購買0型武器$150(按1):" , "購買-型武器$250(按2):" , "購買柚型武器$500(按3):"};
	char we_ap[3] = {'0' , '-' , '9'};

	char m,start,name,gm='n'/*模式*/,back,we_use='|',buy,fname[80];
	FILE *file;
	for(int i=0;i<10;i++){
		shop[i]=0;
	}
	for(int i=0;i<10;i++){
		shop_help[i]=0;
	}

gamestart:
	while(1){//遊戲主畫面
		system("cls");
		puts("");
		puts("");
		cout << "      ──  ┌──    ^     ┌-─--  ┌──";
		puts("");
		cout << "     │    │  │  / \\    │      │";
		puts("");
		cout << "      ──  │──  /___\\   │        ──";
		puts("");
		cout << "        │ │   /     \\  │      │";
		puts("");
		cout << "      ──  │  /       \\ └-─--  └──";
		puts("");
		cout << "                                        ^     ──";
		puts("");
		cout << "                         \\    /\\   /   / \\   │  │";
		puts("");
		cout << "                          \\  /  \\ /   /---\\   ──";
		puts("");
		cout << "                           \\/    \\   /     \\ │   \\";
		puts("");
		space(7);
		cout << "按下1開始: \n";
		if(kbhit()){
			start = getch();
			if(start=='1'){
				break;
			}
		}
	}
	system("cls");
modeslc:
	while(1){
		linechange(4);
		space(18);
		cout << "計時模式:	按1   最高分數:" << highscore;
		puts("");
		space(18);
		cout << "練習模式:	按p";
		puts("");
		space(18);
		cout << "教學:		按t";
		puts("");
		space(18);
		cout << "商店:		按o";
		puts("");
		space(18);
		cout << "儲存遊戲紀錄:	按s";
		puts("");
		space(18);
		cout << "讀取上次進度:	按r";
		puts("");
		space(18);
		cout << "返回:		按b";
		if(kbhit){
			start = getch();
			switch(start){
				case'1': //計時模式
					goto time;
					break;
				case'p': //練習模式
					goto train;
					break;
				case't': //教學
					system("cls");
					linechange(6);
					space(15);
					cout << "移動>>	a:左 d:右" << endl;
					space(15);
					cout << "攻擊>>	space:使用武器";
					linechange(5);
					system("pause");
					system("cls");
					break;
				case'o': //商店
					while(1){
						system("cls");
						linechange(3);
						space(17);
						cout << "money:" << money;
						linechange(2);
						space(15);
						for(int i=0;i<3;i++){
                            if(i==0){
                                cout << "購買0型武器$150(按1):" ;
                            }else if(i==1){
                                cout << "購買-型武器$250(按2):" ;
                            }else if(i==2){
                                cout << "購買柚型武器$500(按3):" ;
                            }

                            if(shop_help[i]==0){
                                cout << "未解鎖";
                            }else if(shop_help[i]==1){
                                cout << "已解鎖(按" << i+1 << "使用)";
                            }
                            if(shop[i]==1){
                                cout << "已使用";
                                we_use = we_ap[i];
                            }

                            puts("");
                            space(15);
						}
						cout << "換回原本武器(按0):" ;


						if(buy=='0'){
							system("cls");
							linechange(3);
							space(17);
							cout << "money:" << money;
							linechange(2);
							space(15);
							cout << "購買0型武器$150(按1):" ;
							puts("");
							space(15);
							cout << "購買-型武器$250(按2):" ;
							puts("");
							space(15);
							cout << "購買柚型武器$500(按3):" ;
							puts("");
							space(15);
							cout << "換回原本武器(按0):" ;
							cout << "已換回原本武器!";
							we_use = '|';
						}
						linechange(2);
						space(15);
						cout << "按b以返回";

						buy = getch(); //輸入

                        int sel = buy - '0' - 1; // 0-base
                        if( (sel<0 || 2<sel) && (buy!='b' && buy!='0') ){
                            continue;
                        }

                        if(0<=sel && sel<=2){//若選擇武器
                            if(money>=money_chec[sel] && shop_help[sel]!=1){//錢足夠且尚未解鎖
                                shop_help[sel] = 1;
                                money-=money_chec[sel];
                                we_use = we_ap[sel];
                            }
                            if(shop_help[sel] == 1){//使用選擇武器
                                shop[sel] = 1;
                                for(int i=0;i<3;i++){
                                    if(i!=sel){
                                        shop[i] = 0;
                                    }
                                }
                            }
                        }

						if(buy=='b'){
							system("cls");
							break;
						}
					}
					goto modeslc;
					break;
				case's': //存檔
					system("cls");
					linechange(6);
					space(22);
					cout << "請輸入名字:";
					cin >> fname;
					file = fopen(fname,"w");
					fprintf(file,"%d ",highscore);
					fprintf(file,"%d \n",money);
					for(int i=0;i<3;i++){
						fprintf(file,"%d	",shop[i]);
						fprintf(file,"%d\n",shop_help[i]);
					}
					puts("");
					space(22);
					cout << "存檔完成!!!\n";
					fclose(file);
					puts("");
					space(22);
					system("pause");
					system("cls");
					goto modeslc;
				case'r': //讀檔
					system("cls");
					linechange(6);
					space(22);
					cout << "請輸入名字:";
					cin >> fname;
					file = fopen(fname,"r");
					if(file==NULL){
                        puts("");
						space(22);
						cout << "找不到名字!!\n";
						puts("");
                        space(22);
						system("pause");
						system("cls");
						goto modeslc;
					}
					fscanf(file,"%d",&highscore);
					fscanf(file,"%d",&money);
					for(int i=0;i<3;i++){
						fscanf(file,"%d %d",&shop[i],&shop_help[i]);
					}
					puts("");
					space(22);
					cout << "讀檔完成!!!\n";
					fclose(file);
					puts("");
					space(22);
					system("pause");
					system("cls");

					goto modeslc;
					break;
				case'b': //返回
					goto gamestart;
					break;
			}
		system("cls");
		}
	}
train:
enterenemy:
    dc=0;
	ac=0;
	score=0;
	system("cls");
	linechange(7);
	space(3);
	cout << "要選擇幾個目標呢?(最多20個)(進入遊戲後按下'b'可退出):";
	cin >> ene_amt_s; //輸入目標數量
	for(int i=0;i<ene_amt_s.size();i++){
        if(!isdigit(ene_amt_s[i])){
            system("cls");
            linechange(7);
            space(21);
            cout << "請輸入數字!!";
            linechange(5);
            system("pause");
            goto enterenemy;
        }
	}

	ene_amt_i = stoi(ene_amt_s);

	if(ene_amt_i>20){
		system("cls");
		linechange(7);
		space(19);

		cout << "請輸入小一點的數字!!";
		linechange(5);
		system("pause");
		goto enterenemy;
	}
	if(ene_amt_i<=0){
		system("cls");
		linechange(7);
		space(19);

		cout << "請輸入大一點的數字!!";cout << ene_amt_i;
		linechange(5);
		system("pause");
		goto enterenemy;
	}
	puts("");
	linechange(14);
	cout << "|^|";
	while(1){
		m = getch();
		switch(m){
			case'd':
                system("cls");
                if(ene>0){
                    for(int i=1;i<=ene_amt_i;i++){//輸出目標
                        cout << " ";
                        cout << "+";
                        cs+=2;
                    }
                    space(50-cs);//讓score出現在正確地方
                    cout << "score=" << score;
                    cs=0;
				}
				moved(dc,ac,we);//向右
				break;
			case'a':
				system("cls");
				if(ene>0){
					for(int i=1;i<=ene_amt_i;i++){
						cout << " ";
						cout << "+";
						cs+=2;
					}
					space(50-cs);//讓score出現在正確地方
					cout << "score=" << score;
					cs=0;
				}
				movea(dc,ac,we);//向左
				break;
			case' ':
				weapon(dc,ac,we,we_use);//輸出武器

				for(int i=1;i<=ene_amt_i;i++){
					cout << " ";
					cs+=2;
					cout <<"+";
					if((i*2)==(dc-ac+2)){ //若擊中目標
						cout << "\b ";
						score++;
					}
				}
				space(50-cs);//讓score出現在正確地方
				cout << "score=" << score;
				reappear(dc,ac);//重新輸出玩家
				cs=0;
				break;
			case'b':
				system("cls");
				goto modeslc;
				break;
		}
		if(ac>dc){//避免超出螢幕最左方
			ac=0;
			dc=0;
		}
		if(dc-ac>45){//避免超出螢幕最右方
            ac=0;
            dc=45;
        }
	}
time:
	clock_t begin, end;
	double cost=0;
	int chec=0;
	int ene_ct=8;//(0~7)共8個目標
	dc=0;
	ac=0;
	score=0;
	destroy=0;
	system("cls");

	linechange(7);
	space(16);
	cout << "在30秒內打敗最多的敵人吧!!!";
	linechange(5);
	system("pause");

	begin = clock();//30秒計時開始
    while(1){
        for(int i=0;i<ene_ct;i++){
            x[i] = rand() % 3 + 2; //隨機空白(2~4)
            ene[i]=x[i]+1; //目標(敵人)位置
            if(i>0){
                ene[i] += ene[i-1];
            }
            record[i] = 0;
        }

        while(1){
            m = getch();
            switch(m){
                case'd':
                    system("cls");

                    for(int i=0;i<ene_ct;i++){
                        space(x[i]);
                        cout << "+";
                        if(record[i] == 1){ //若目標已被擊中
                            cout << "\b ";
                        }
                    }

                    space(50-ene[ene_ct-1]);//讓score出現在正確地方
                    cout << "score=" << score;
                    moved(dc,ac,we);//向右
                    break;
                case'a':
                    system("cls");

                    for(int i=0;i<ene_ct;i++){
                        space(x[i]);
                        cout << "+";
                        if(record[i] == 1){ //若目標已被擊中
                            cout << "\b ";
                        }
                    }

                    space(50-ene[ene_ct-1]);//讓score出現在正確地方
                    cout << "score=" << score;
                    movea(dc,ac,we);//向左
                    break;
                case' ':
                    weapon(dc,ac,we,we_use);//輸出武器

                    for(int i=0;i<ene_ct;i++){
                        space(x[i]);
                        cout << "+";
                        if(ene[i]==(dc-ac+2) && record[i]!=1){ //首次擊中目標
                            destroy++;
                            score++;
                            record[i]=1;
                            de=1;
                        }
                        if(record[i] == 1){
                            cout << "\b ";
                        }
                    }

                    space(50-ene[ene_ct-1]);//讓score出現在正確地方
                    cout << "score=" << score;
                    reappear(dc,ac);//重新輸出玩家
                    break;
            }
            if(ac>dc){//避免超出螢幕最左方
                ac=0;
                dc=0;
            }
            if(dc-ac>45){//避免超出螢幕最右方
                ac=0;
                dc=45;
            }
            if(destroy==ene_ct){//若目標皆被擊中
                destroy=0;
                break;
            }
            end = clock();
            cost = (double)(end - begin)/CLOCKS_PER_SEC;
            cout << " " << cost;
            if(cost>30){ //遊戲結束
                chec=1;
                break;
            }
        }
        if(chec == 1){//遊戲結束
            break;
        }
    }
//遊戲結束
	while(1){
		system("cls");
		linechange(6);
		space(20);
		cout << "時間到!!!";
		puts("");
		space(20);
		cout << "您的得分:" << score;
		puts("");
		space(20);
		cout << "得到了" <<  2*score << "元!!!";
		money+=2*score;
		if(score>highscore){
			highscore=score;
		}
		linechange(2);
		space(20);
		cout << "輸入b以返回:";
		cin >> back;
		if(back=='b'){
			system("cls");
			break;
		}
	}
	goto modeslc;

	return 0;
}
