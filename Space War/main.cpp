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
	int destroy=0,record[15],rh=0,de=0,shop[10],shop_help[10],ene_amt_i;//shop �ϥ� , shop_help ����
	int money=1000000;//��
	int money_chec[3] = {150 , 250 , 500};
	string ene_amt_s;
	string weapon_text[3] = {"�ʶR0���Z��$150(��1):" , "�ʶR-���Z��$250(��2):" , "�ʶR�c���Z��$500(��3):"};
	char we_ap[3] = {'0' , '-' , '9'};

	char m,start,name,gm='n'/*�Ҧ�*/,back,we_use='|',buy,fname[80];
	FILE *file;
	for(int i=0;i<10;i++){
		shop[i]=0;
	}
	for(int i=0;i<10;i++){
		shop_help[i]=0;
	}

gamestart:
	while(1){//�C���D�e��
		system("cls");
		puts("");
		puts("");
		cout << "      �w�w  �z�w�w    ^     �z-�w--  �z�w�w";
		puts("");
		cout << "     �x    �x  �x  / \\    �x      �x";
		puts("");
		cout << "      �w�w  �x�w�w  /___\\   �x        �w�w";
		puts("");
		cout << "        �x �x   /     \\  �x      �x";
		puts("");
		cout << "      �w�w  �x  /       \\ �|-�w--  �|�w�w";
		puts("");
		cout << "                                        ^     �w�w";
		puts("");
		cout << "                         \\    /\\   /   / \\   �x  �x";
		puts("");
		cout << "                          \\  /  \\ /   /---\\   �w�w";
		puts("");
		cout << "                           \\/    \\   /     \\ �x   \\";
		puts("");
		space(7);
		cout << "���U1�}�l: \n";
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
		cout << "�p�ɼҦ�:	��1   �̰�����:" << highscore;
		puts("");
		space(18);
		cout << "�m�߼Ҧ�:	��p";
		puts("");
		space(18);
		cout << "�о�:		��t";
		puts("");
		space(18);
		cout << "�ө�:		��o";
		puts("");
		space(18);
		cout << "�x�s�C������:	��s";
		puts("");
		space(18);
		cout << "Ū���W���i��:	��r";
		puts("");
		space(18);
		cout << "��^:		��b";
		if(kbhit){
			start = getch();
			switch(start){
				case'1': //�p�ɼҦ�
					goto time;
					break;
				case'p': //�m�߼Ҧ�
					goto train;
					break;
				case't': //�о�
					system("cls");
					linechange(6);
					space(15);
					cout << "����>>	a:�� d:�k" << endl;
					space(15);
					cout << "����>>	space:�ϥΪZ��";
					linechange(5);
					system("pause");
					system("cls");
					break;
				case'o': //�ө�
					while(1){
						system("cls");
						linechange(3);
						space(17);
						cout << "money:" << money;
						linechange(2);
						space(15);
						for(int i=0;i<3;i++){
                            if(i==0){
                                cout << "�ʶR0���Z��$150(��1):" ;
                            }else if(i==1){
                                cout << "�ʶR-���Z��$250(��2):" ;
                            }else if(i==2){
                                cout << "�ʶR�c���Z��$500(��3):" ;
                            }

                            if(shop_help[i]==0){
                                cout << "������";
                            }else if(shop_help[i]==1){
                                cout << "�w����(��" << i+1 << "�ϥ�)";
                            }
                            if(shop[i]==1){
                                cout << "�w�ϥ�";
                                we_use = we_ap[i];
                            }

                            puts("");
                            space(15);
						}
						cout << "���^�쥻�Z��(��0):" ;


						if(buy=='0'){
							system("cls");
							linechange(3);
							space(17);
							cout << "money:" << money;
							linechange(2);
							space(15);
							cout << "�ʶR0���Z��$150(��1):" ;
							puts("");
							space(15);
							cout << "�ʶR-���Z��$250(��2):" ;
							puts("");
							space(15);
							cout << "�ʶR�c���Z��$500(��3):" ;
							puts("");
							space(15);
							cout << "���^�쥻�Z��(��0):" ;
							cout << "�w���^�쥻�Z��!";
							we_use = '|';
						}
						linechange(2);
						space(15);
						cout << "��b�H��^";

						buy = getch(); //��J

                        int sel = buy - '0' - 1; // 0-base
                        if( (sel<0 || 2<sel) && (buy!='b' && buy!='0') ){
                            continue;
                        }

                        if(0<=sel && sel<=2){//�Y��ܪZ��
                            if(money>=money_chec[sel] && shop_help[sel]!=1){//�������B�|������
                                shop_help[sel] = 1;
                                money-=money_chec[sel];
                                we_use = we_ap[sel];
                            }
                            if(shop_help[sel] == 1){//�ϥο�ܪZ��
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
				case's': //�s��
					system("cls");
					linechange(6);
					space(22);
					cout << "�п�J�W�r:";
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
					cout << "�s�ɧ���!!!\n";
					fclose(file);
					puts("");
					space(22);
					system("pause");
					system("cls");
					goto modeslc;
				case'r': //Ū��
					system("cls");
					linechange(6);
					space(22);
					cout << "�п�J�W�r:";
					cin >> fname;
					file = fopen(fname,"r");
					if(file==NULL){
                        puts("");
						space(22);
						cout << "�䤣��W�r!!\n";
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
					cout << "Ū�ɧ���!!!\n";
					fclose(file);
					puts("");
					space(22);
					system("pause");
					system("cls");

					goto modeslc;
					break;
				case'b': //��^
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
	cout << "�n��ܴX�ӥؼЩO?(�̦h20��)(�i�J�C������U'b'�i�h�X):";
	cin >> ene_amt_s; //��J�ؼмƶq
	for(int i=0;i<ene_amt_s.size();i++){
        if(!isdigit(ene_amt_s[i])){
            system("cls");
            linechange(7);
            space(21);
            cout << "�п�J�Ʀr!!";
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

		cout << "�п�J�p�@�I���Ʀr!!";
		linechange(5);
		system("pause");
		goto enterenemy;
	}
	if(ene_amt_i<=0){
		system("cls");
		linechange(7);
		space(19);

		cout << "�п�J�j�@�I���Ʀr!!";cout << ene_amt_i;
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
                    for(int i=1;i<=ene_amt_i;i++){//��X�ؼ�
                        cout << " ";
                        cout << "+";
                        cs+=2;
                    }
                    space(50-cs);//��score�X�{�b���T�a��
                    cout << "score=" << score;
                    cs=0;
				}
				moved(dc,ac,we);//�V�k
				break;
			case'a':
				system("cls");
				if(ene>0){
					for(int i=1;i<=ene_amt_i;i++){
						cout << " ";
						cout << "+";
						cs+=2;
					}
					space(50-cs);//��score�X�{�b���T�a��
					cout << "score=" << score;
					cs=0;
				}
				movea(dc,ac,we);//�V��
				break;
			case' ':
				weapon(dc,ac,we,we_use);//��X�Z��

				for(int i=1;i<=ene_amt_i;i++){
					cout << " ";
					cs+=2;
					cout <<"+";
					if((i*2)==(dc-ac+2)){ //�Y�����ؼ�
						cout << "\b ";
						score++;
					}
				}
				space(50-cs);//��score�X�{�b���T�a��
				cout << "score=" << score;
				reappear(dc,ac);//���s��X���a
				cs=0;
				break;
			case'b':
				system("cls");
				goto modeslc;
				break;
		}
		if(ac>dc){//�קK�W�X�ù��̥���
			ac=0;
			dc=0;
		}
		if(dc-ac>45){//�קK�W�X�ù��̥k��
            ac=0;
            dc=45;
        }
	}
time:
	clock_t begin, end;
	double cost=0;
	int chec=0;
	int ene_ct=8;//(0~7)�@8�ӥؼ�
	dc=0;
	ac=0;
	score=0;
	destroy=0;
	system("cls");

	linechange(7);
	space(16);
	cout << "�b30�����ѳ̦h���ĤH�a!!!";
	linechange(5);
	system("pause");

	begin = clock();//30��p�ɶ}�l
    while(1){
        for(int i=0;i<ene_ct;i++){
            x[i] = rand() % 3 + 2; //�H���ť�(2~4)
            ene[i]=x[i]+1; //�ؼ�(�ĤH)��m
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
                        if(record[i] == 1){ //�Y�ؼФw�Q����
                            cout << "\b ";
                        }
                    }

                    space(50-ene[ene_ct-1]);//��score�X�{�b���T�a��
                    cout << "score=" << score;
                    moved(dc,ac,we);//�V�k
                    break;
                case'a':
                    system("cls");

                    for(int i=0;i<ene_ct;i++){
                        space(x[i]);
                        cout << "+";
                        if(record[i] == 1){ //�Y�ؼФw�Q����
                            cout << "\b ";
                        }
                    }

                    space(50-ene[ene_ct-1]);//��score�X�{�b���T�a��
                    cout << "score=" << score;
                    movea(dc,ac,we);//�V��
                    break;
                case' ':
                    weapon(dc,ac,we,we_use);//��X�Z��

                    for(int i=0;i<ene_ct;i++){
                        space(x[i]);
                        cout << "+";
                        if(ene[i]==(dc-ac+2) && record[i]!=1){ //���������ؼ�
                            destroy++;
                            score++;
                            record[i]=1;
                            de=1;
                        }
                        if(record[i] == 1){
                            cout << "\b ";
                        }
                    }

                    space(50-ene[ene_ct-1]);//��score�X�{�b���T�a��
                    cout << "score=" << score;
                    reappear(dc,ac);//���s��X���a
                    break;
            }
            if(ac>dc){//�קK�W�X�ù��̥���
                ac=0;
                dc=0;
            }
            if(dc-ac>45){//�קK�W�X�ù��̥k��
                ac=0;
                dc=45;
            }
            if(destroy==ene_ct){//�Y�ؼЬҳQ����
                destroy=0;
                break;
            }
            end = clock();
            cost = (double)(end - begin)/CLOCKS_PER_SEC;
            cout << " " << cost;
            if(cost>30){ //�C������
                chec=1;
                break;
            }
        }
        if(chec == 1){//�C������
            break;
        }
    }
//�C������
	while(1){
		system("cls");
		linechange(6);
		space(20);
		cout << "�ɶ���!!!";
		puts("");
		space(20);
		cout << "�z���o��:" << score;
		puts("");
		space(20);
		cout << "�o��F" <<  2*score << "��!!!";
		money+=2*score;
		if(score>highscore){
			highscore=score;
		}
		linechange(2);
		space(20);
		cout << "��Jb�H��^:";
		cin >> back;
		if(back=='b'){
			system("cls");
			break;
		}
	}
	goto modeslc;

	return 0;
}
