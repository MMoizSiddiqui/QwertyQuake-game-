
/*NOTE : RUN THIS GAME ON WINDOWS 10 ONLY DUE TO GOTOXY ISSUE AS THERE ARE DIFFERENT CONSOLE DIMENSIONS IN OTHER WINDOWS*/
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<string.h>
#include<mmsystem.h>

//The SND_ASYNC flag plays the sound asynchronously, and SND_LOOP makes it loop continuously
// Function to play background music
// users : moiz   bob    alex  
//pass: 1234
void playBackgroundMusic() {
    //PlaySound(TEXT("C:\\Users\\Moiz Siddiqui\\Desktop\\QWERTY QUAKE (23k2080)\\music.wav"),NULL,SND_ASYNC);
    // note ** change path in line 14 for sound by copying path from your computer as every computer will have different path.

}

struct data
{
	char name[50];
	int score;			
}user[12], input,temp,disp;
void delay(float number_of_seconds) 
{ 
    float milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds); 
} 
void hidecursor()

{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}
void gotoxy(short x, short y)                                             
{
 COORD pos ={x,y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int menu()
{
int selection;
do
{
void box();
gotoxy(59,10);	
printf("1 - Play game");
gotoxy(59,13);
printf("2 - Display Highscores");
gotoxy(59,16);
printf("3 - Quit");
gotoxy(59,19);
printf("Enter a selection: ");
gotoxy(80,19);
scanf("%d",&selection);
} while ((selection < 1) || (selection > 4));
return selection;
}
void line()
{
	int l1,l2;
	gotoxy(0,20);
	for(l1=1;l1<=70;l1++)
	printf("^");
	for(l2=0;l2<=19;l2++)
	{
	gotoxy(70,l2);
	printf("<");
	}	
}
void box()
{
	int i,j,k,l;
gotoxy(43,5);
for(i=43;i<=70;i++)
{
printf("* ");
}
for(j=6;j<=30;j++)
{
	gotoxy(43,j);
	printf("*");
}
gotoxy(43,j);
for(k=43;k<=70;k++)
{
	printf("* ");
}
for(l=6;l<=30;l++)
{
	gotoxy(97,l);
	printf("*");
}

}

void letterpress1(int *score)
{
	system("COLOR F9");
	int c=0;
	int row,life,sflag,lflag,sp,rr2,rr3,rl1,rl2,rl3,sp1,sp2,sp3,ch1,ch2,ch3,r2,r3;
	srand(time(NULL));
	life=5;
	sflag=0;
	lflag=0;
	sp1=rand()%70;
	sp2=rand()%70;
	sp3=rand()%70;
	ch1='A'+ (rand()%26);
	ch2='A'+ (rand()%26);
	ch3='A'+ (rand()%26);
	r2=rand()%20;
	r3=rand()%20;
	for(rr2=1,rr3=1,rl1=1,rl2=1,rl3=1;;rl1++,rr2++,rr3++)
	{	
		if(kbhit())
	    c=getch();
		hidecursor();				
		for(row=1;row<rl1;row++){	
		printf("\n");}
		for(sp=1;sp<sp1;sp++)
	    printf(" ");
		printf("%c",ch1);
		gotoxy(0,0);
		if(rr2>=r2)
		{
			for(row=1;row<rl2;row++)
			printf("\n");
			for(sp=1;sp<sp2;sp++)
	    	printf(" ");
	    	printf("%c",ch2);
			if(rl2==20)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				lflag=1;
			}
			else if(c==ch2 || c==ch2+32)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				sflag=1;
			}
			rl2++;
			gotoxy(0,0);	
		}
		if(rr3>=r3)
		{
			
			for(row=1;row<rl3;row++)
			printf("\n");
			for(sp=1;sp<sp3;sp++)
	    	printf(" ");
	    	printf("%c",ch3);
			if(rl3==20)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				lflag=1;
			}
			else if(c==ch3 || c==ch3+32)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				sflag=1;
			}
			rl3++;
			gotoxy(0,0);	
		}
		if(rl1==20)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			lflag=1;
		}
		else if(c==ch1 || c==ch1+32)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			sflag=1;	
		}
		line();
		if(sflag==1)
		*score=*score+1;
		if(lflag==1)
		life=life-1;
		if(life<=0)
		{
			system("cls");
			box();
			gotoxy(59,13);
			printf("GAME OVER !");
			input.score=*score;
			gotoxy(59,16);
			printf("SCORE : %d",input.score);
			gotoxy(59,19);
			printf("Press any key to exit...");
			getch();
			system("cls");
			return;
		}
		gotoxy(72,5);
		printf("score %d",*score);
		gotoxy(72,8);
		printf("life %d",life);
		gotoxy(72,11);
		printf("Beginner");
		delay(0.2);
		system("cls");
		c=0;
		sflag=0;
		lflag=0;
	}
}
void letterpress2(int *score)
{
	system("COLOR F2");
	int c=0;
	int row,life,sflag,lflag,sp,rr2,rr3,rr4,rl1,rl2,rl3,rl4,sp1,sp2,sp3,sp4,ch1,ch2,ch3,ch4,r2,r3,r4;
	srand(time(NULL));
	life=5;
	sflag=0;
	lflag=0;
	sp1=rand()%70;
	sp2=rand()%70;
	sp3=rand()%70;
	sp4=rand()%70;
	ch1='A'+ (rand()%26);
	ch2='A'+ (rand()%26);
	ch3='A'+ (rand()%26);
	ch4='A'+ (rand()%26);
	r2=rand()%20;
	r3=rand()%20;
	r4=rand()%20;
	for(rr2=1,rr3=1,rr4=1,rl1=1,rl2=1,rl3=1,rl4=1;;rl1++,rr2++,rr3++,rr4++)
	{	
		if(kbhit())
	    c=getch();
		hidecursor();				
		for(row=1;row<rl1;row++){	
		printf("\n");}
		for(sp=1;sp<sp1;sp++)
	    printf(" ");
		printf("%c",ch1);
		gotoxy(0,0);
		if(rr2>=r2)
		{
			for(row=1;row<rl2;row++)
			printf("\n");
			for(sp=1;sp<sp2;sp++)
	    	printf(" ");
	    	printf("%c",ch2);
			if(rl2==20)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				lflag=1;
			}
			else if(c==ch2 || c==ch2+32)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				sflag=1;
			}
			rl2++;
			gotoxy(0,0);	
		}
		if(rr3>=r3)
		{
			
			for(row=1;row<rl3;row++)
			printf("\n");
			for(sp=1;sp<sp3;sp++)
	    	printf(" ");
	    	printf("%c",ch3);
			if(rl3==20)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				lflag=1;
			}
			else if(c==ch3 || c==ch3+32)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				sflag=1;
			}
			rl3++;
			gotoxy(0,0);	
		}
		if(rr4>=r4)
		{
			
			for(row=1;row<rl4;row++)
			printf("\n");
			for(sp=1;sp<sp4;sp++)
	    	printf(" ");
	    	printf("%c",ch4);
			if(rl4==20)
			{
				rr4=1;
				ch4='A'+ (rand()%26);
				sp4=rand()%70;
				rl4=1;
				lflag=1;
			}
			else if(c==ch4 || c==ch4+32)
			{
				rr4=1;
				ch4='A'+ (rand()%26);
				sp4=rand()%70;
				rl4=1;
				sflag=1;
			}
			rl4++;
			gotoxy(0,0);	
		}
		if(rl1==20)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			lflag=1;
		}
		else if(c==ch1 || c==ch1+32)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			sflag=1;	
		}
		line();
		if(sflag==1)
		*score=*score+2;
		if(lflag==1)
		life=life-1;
		if(life<=0)
		{
			system("cls");
			box();
			gotoxy(59,13);
			printf("GAME OVER !");
			input.score=*score;
			gotoxy(59,16);
			printf("SCORE : %d",input.score);
			gotoxy(59,19);
			printf("Press any key to exit...");
			getch();
			system("cls");
			return;
		}
		gotoxy(72,5);
		printf("score %d",*score);
		gotoxy(72,8);
		printf("life %d",life);
		gotoxy(72,11);
		printf("Easy");
		delay(0.2);
		system("cls");
		c=0;
		sflag=0;
		lflag=0;
	}
}
void letterpress3(int *score)
{
	system("COLOR F6");
	int c=0;
	int row,life,sflag,lflag,sp,rr2,rr3,rr4,rr5,rl1,rl2,rl3,rl4,rl5,sp1,sp2,sp3,sp4,sp5,ch1,ch2,ch3,ch4,ch5,r2,r3,r4,r5;
	srand(time(NULL));
	life=5;
	sflag=0;
	lflag=0;
	sp1=rand()%70;
	sp2=rand()%70;
	sp3=rand()%70;
	sp4=rand()%70;
	sp5=rand()%70;
	ch1='A'+ (rand()%26);
	ch2='A'+ (rand()%26);
	ch3='A'+ (rand()%26);
	ch4='A'+ (rand()%26);
	ch5='A'+ (rand()%26);
	r2=rand()%20;
	r3=rand()%20;
	r4=rand()%20;
	r5=rand()%20;
	for(rr2=1,rr3=1,rr4=1,rr5=1,rl1=1,rl2=1,rl3=1,rl4=1,rl5=1;;rl1++,rr2++,rr3++,rr4++,rr5++)
	{	
		if(kbhit())
	    c=getch();
		hidecursor();				
		for(row=1;row<rl1;row++){	
		printf("\n");}
		for(sp=1;sp<sp1;sp++)
	    printf(" ");
		printf("%c",ch1);
		gotoxy(0,0);
		if(rr2>=r2)
		{
			for(row=1;row<rl2;row++)
			printf("\n");
			for(sp=1;sp<sp2;sp++)
	    	printf(" ");
	    	printf("%c",ch2);
			if(rl2==20)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				lflag=1;
			}
			else if(c==ch2 || c==ch2+32)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				sflag=1;
			}
			rl2++;
			gotoxy(0,0);	
		}
		if(rr3>=r3)
		{
			
			for(row=1;row<rl3;row++)
			printf("\n");
			for(sp=1;sp<sp3;sp++)
	    	printf(" ");
	    	printf("%c",ch3);
			if(rl3==20)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				lflag=1;
			}
			else if(c==ch3 || c==ch3+32)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				sflag=1;
			}
			rl3++;
			gotoxy(0,0);	
		}
		if(rr4>=r4)
		{
			
			for(row=1;row<rl4;row++)
			printf("\n");
			for(sp=1;sp<sp4;sp++)
	    	printf(" ");
	    	printf("%c",ch4);
			if(rl4==20)
			{
				rr4=1;
				ch4='A'+ (rand()%26);
				sp4=rand()%70;
				rl4=1;
				lflag=1;
			}
			else if(c==ch4 || c==ch4+32)
			{
				rr4=1;
				ch4='A'+ (rand()%26);
				sp4=rand()%70;
				rl4=1;
				sflag=1;
			}
			rl4++;
			gotoxy(0,0);	
		}
		if(rr5>=r5)
		{
			
			for(row=1;row<rl5;row++)
			printf("\n");
			for(sp=1;sp<sp5;sp++)
	    	printf(" ");
	    	printf("%c",ch5);
			if(rl5==20)
			{
				rr5=1;
				ch5='A'+ (rand()%26);
				sp5=rand()%70;
				rl5=1;
				lflag=1;
			}
			else if(c==ch5 || c==ch5+32)
			{
				rr5=1;
				ch5='A'+ (rand()%26);
				sp5=rand()%70;
				rl5=1;
				sflag=1;	
			}
			rl5++;
			gotoxy(0,0);	
		}
		if(rl1==20)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			lflag=1;
		}
		else if(c==ch1 || c==ch1+32)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			sflag=1;	
		}
		line();
		if(sflag==1)
		*score=*score+3;
		if(lflag==1)
		life=life-1;
		if(life<=0)
		{
			system("cls");
			box();
			gotoxy(59,13);
			printf("GAME OVER !");
			input.score=*score;
			gotoxy(59,16);
			printf("SCORE : %d",input.score);
			gotoxy(59,19);
			printf("Press any key to exit...");
			getch();
			system("cls");
			return;
		}
		gotoxy(72,5);
		printf("score %d",*score);
		gotoxy(72,8);
		printf("life %d",life);
		gotoxy(72,11);
		printf("Medium");
		delay(0.2);
		system("cls");
		c=0;
		sflag=0;
		lflag=0;
	}
}
void letterpress4(int *score)
{
	system("COLOR FC");
	int c=0;
	int row,life,sflag,lflag,sp,rr2,rr3,rr4,rr5,rr6,rl1,rl2,rl3,rl4,rl5,rl6,sp1,sp2,sp3,sp4,sp5,sp6,ch1,ch2,ch3,ch4,ch5,ch6,r2,r3,r4,r5,r6;
	srand(time(NULL));
	life=5;
	sflag=0;
	lflag=0;
	sp1=rand()%70;
	sp2=rand()%70;
	sp3=rand()%70;
	sp4=rand()%70;
	sp5=rand()%70;
	sp6=rand()%70;
	ch1='A'+ (rand()%26);
	ch2='A'+ (rand()%26);
	ch3='A'+ (rand()%26);
	ch4='A'+ (rand()%26);
	ch5='A'+ (rand()%26);
	ch6='A'+ (rand()%26);
	r2=rand()%20;
	r3=rand()%20;
	r4=rand()%20;
	r5=rand()%20;
	r6=rand()%20;
	for(rr2=1,rr3=1,rr4=1,rr5=1,rr6=1,rl1=1,rl2=1,rl3=1,rl4=1,rl5=1,rl6=1;;rl1++,rr2++,rr3++,rr4++,rr5++,rr6++)
	{	
		if(kbhit())
	    c=getch();
		hidecursor();				
		for(row=1;row<rl1;row++){	
		printf("\n");}
		for(sp=1;sp<sp1;sp++)
	    printf(" ");
		printf("%c",ch1);
		gotoxy(0,0);
		if(rr2>=r2)
		{
			for(row=1;row<rl2;row++)
			printf("\n");
			for(sp=1;sp<sp2;sp++)
	    	printf(" ");
	    	printf("%c",ch2);
			if(rl2==20)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				lflag=1;
			}
			else if(c==ch2 || c==ch2+32)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				sflag=1;
			}
			rl2++;
			gotoxy(0,0);	
		}
		if(rr3>=r3)
		{
			
			for(row=1;row<rl3;row++)
			printf("\n");
			for(sp=1;sp<sp3;sp++)
	    	printf(" ");
	    	printf("%c",ch3);
			if(rl3==20)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				lflag=1;
			}
			else if(c==ch3 || c==ch3+32)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				sflag=1;
			}
			rl3++;
			gotoxy(0,0);	
		}
		if(rr4>=r4)
		{
			
			for(row=1;row<rl4;row++)
			printf("\n");
			for(sp=1;sp<sp4;sp++)
	    	printf(" ");
	    	printf("%c",ch4);
			if(rl4==20)
			{
				rr4=1;
				ch4='A'+ (rand()%26);
				sp4=rand()%70;
				rl4=1;
				lflag=1;
			}
			else if(c==ch4 || c==ch4+32)
			{
				rr4=1;
				ch4='A'+ (rand()%26);
				sp4=rand()%70;
				rl4=1;
				sflag=1;
			}
			rl4++;
			gotoxy(0,0);	
		}
		if(rr5>=r5)
		{
			
			for(row=1;row<rl5;row++)
			printf("\n");
			for(sp=1;sp<sp5;sp++)
	    	printf(" ");
	    	printf("%c",ch5);
			if(rl5==20)
			{
				rr5=1;
				ch5='A'+ (rand()%26);
				sp5=rand()%70;
				rl5=1;
				lflag=1;
			}
			else if(c==ch5 || c==ch5+32)
			{
				rr5=1;
				ch5='A'+ (rand()%26);
				sp5=rand()%70;
				rl5=1;
				sflag=1;	
			}
			rl5++;
			gotoxy(0,0);	
		}
		if(rr6>=r6)
		{
			
			for(row=1;row<rl6;row++)
			printf("\n");
			for(sp=1;sp<sp6;sp++)
	    	printf(" ");
	    	printf("%c",ch6);
			if(rl6==20)
			{
				rr6=1;
				ch6='A'+ (rand()%26);
				sp6=rand()%70;
				rl6=1;
				lflag=1;
			}
			else if(c==ch6 || c==ch6+32)
			{
				rr6=1;
				ch6='A'+ (rand()%26);
				sp6=rand()%70;
				rl6=1;
				sflag=1;
			}
			rl6++;
			gotoxy(0,0);	
		}
		if(rl1==20)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			lflag=1;
		}
		else if(c==ch1 || c==ch1+32)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			sflag=1;	
		}
		line();
		if(sflag==1)
		*score=*score+4;
		if(lflag==1)
		life=life-1;
		if(life<=0)
		{
			system("cls");
			box();
			gotoxy(59,13);
			printf("GAME OVER !");
			input.score=*score;
			gotoxy(59,16);
			printf("SCORE : %d",input.score);
			gotoxy(59,19);
			printf("Press any key to exit...");
			getch();
			system("cls");
			return;
		}
		gotoxy(72,5);
		printf("score %d",*score);
		gotoxy(72,8);
		printf("life %d",life);
		gotoxy(72,11);
		printf("Hard");
		delay(0.15);
		system("cls");
		c=0;
		sflag=0;
		lflag=0;
	}
}
void letterpress5(int *score)
{
	system("COLOR F4");
	int c=0;
	int row,life,sflag,lflag,sp,rr2,rr3,rr4,rr5,rr6,rl1,rl2,rl3,rl4,rl5,rl6,sp1,sp2,sp3,sp4,sp5,sp6,ch1,ch2,ch3,ch4,ch5,ch6,r2,r3,r4,r5,r6;
	srand(time(NULL));
	life=5;
	sflag=0;
	lflag=0;
	sp1=rand()%70;
	sp2=rand()%70;
	sp3=rand()%70;
	sp4=rand()%70;
	sp5=rand()%70;
	sp6=rand()%70;
	ch1='A'+ (rand()%26);
	ch2='A'+ (rand()%26);
	ch3='A'+ (rand()%26);
	ch4='A'+ (rand()%26);
	ch5='A'+ (rand()%26);
	ch6='A'+ (rand()%26);
	r2=rand()%20;
	r3=rand()%20;
	r4=rand()%20;
	r5=rand()%20;
	r6=rand()%20;
	for(rr2=1,rr3=1,rr4=1,rr5=1,rr6=1,rl1=1,rl2=1,rl3=1,rl4=1,rl5=1,rl6=1;;rl1++,rr2++,rr3++,rr4++,rr5++,rr6++)
	{	
		if(kbhit())
	    c=getch();
		hidecursor();				
		for(row=1;row<rl1;row++){	
		printf("\n");}
		for(sp=1;sp<sp1;sp++)
	    printf(" ");
		printf("%c",ch1);
		gotoxy(0,0);
		if(rr2>=r2)
		{
			for(row=1;row<rl2;row++)
			printf("\n");
			for(sp=1;sp<sp2;sp++)
	    	printf(" ");
	    	printf("%c",ch2);
			if(rl2==20)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				lflag=1;
			}
			else if(c==ch2 || c==ch2+32)
			{
				rr2=1;
				ch2='A'+ (rand()%26);
				sp2=rand()%70;
				rl2=1;
				sflag=1;
			}
			rl2++;
			gotoxy(0,0);	
		}
		if(rr3>=r3)
		{
			
			for(row=1;row<rl3;row++)
			printf("\n");
			for(sp=1;sp<sp3;sp++)
	    	printf(" ");
	    	printf("%c",ch3);
			if(rl3==20)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				lflag=1;
			}
			else if(c==ch3 || c==ch3+32)
			{
				rr3=1;
				ch3='A'+ (rand()%26);
				sp3=rand()%70;
				rl3=1;
				sflag=1;
			}
			rl3++;
			gotoxy(0,0);	
		}
		if(rr4>=r4)
		{
			
			for(row=1;row<rl4;row++)
			printf("\n");
			for(sp=1;sp<sp4;sp++)
	    	printf(" ");
	    	printf("%c",ch4);
			if(rl4==20)
			{
				rr4=1;
				ch4='A'+ (rand()%26);
				sp4=rand()%70;
				rl4=1;
				lflag=1;
			}
			else if(c==ch4 || c==ch4+32)
			{
				rr4=1;
				ch4='A'+ (rand()%26);
				sp4=rand()%70;
				rl4=1;
				sflag=1;
			}
			rl4++;
			gotoxy(0,0);	
		}
		if(rr5>=r5)
		{
			
			for(row=1;row<rl5;row++)
			printf("\n");
			for(sp=1;sp<sp5;sp++)
	    	printf(" ");
	    	printf("%c",ch5);
			if(rl5==20)
			{
				rr5=1;
				ch5='A'+ (rand()%26);
				sp5=rand()%70;
				rl5=1;
				lflag=1;
			}
			else if(c==ch5 || c==ch5+32)
			{
				rr5=1;
				ch5='A'+ (rand()%26);
				sp5=rand()%70;
				rl5=1;
				sflag=1;	
			}
			rl5++;
			gotoxy(0,0);	
		}
		if(rr6>=r6)
		{
			
			for(row=1;row<rl6;row++)
			printf("\n");
			for(sp=1;sp<sp6;sp++)
	    	printf(" ");
	    	printf("%c",ch6);
			if(rl6==20)
			{
				rr6=1;
				ch6='A'+ (rand()%26);
				sp6=rand()%70;
				rl6=1;
				lflag=1;
			}
			else if(c==ch6 || c==ch6+32)
			{
				rr6=1;
				ch6='A'+ (rand()%26);
				sp6=rand()%70;
				rl6=1;
				sflag=1;
			}
			rl6++;
			gotoxy(0,0);	
		}
		if(rl1==20)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			lflag=1;
		}
		else if(c==ch1 || c==ch1+32)
		{
			ch1='A'+ (rand()%26);	
			sp1=rand()%70;
			rl1=1;
			sflag=1;	
		}
		line();
		if(sflag==1)
		*score=*score+5;
		if(lflag==1)
		life=life-1;
		if(life<=0)
		{
			system("cls");
			box();
			gotoxy(59,13);
			printf("GAME OVER !");
			input.score=*score;
			gotoxy(59,16);
			printf("SCORE : %d",input.score);
			gotoxy(59,19);
			printf("Press any key to exit...");
			getch();
			system("cls");
			return;
		}
		gotoxy(72,5);
		printf("score %d",*score);
		gotoxy(72,8);
		printf("life %d",life);
		gotoxy(72,11);
		printf("Professional");
		delay(0.1);
		system("cls");
		c=0;
		sflag=0;
		lflag=0;
	}
}
void filing()
{
	FILE *fp;
	fp=fopen("highscores.txt","a+");
	if (fp==NULL)
	puts("cant open file");
	else
	{
		fwrite(&input,sizeof(input),1,fp);
	}
	fclose(fp);
}
void sort()
{
	FILE *old,*update;
	old=fopen("highscores.txt", "r");
	update=fopen("h1.txt","w");
	if (old==NULL||update==NULL)
	puts("cant open file");
	else
	{
		int i=0;
		while(fread(&user[i],sizeof(user[i]),1,old)>0)
		{
			if(i>10)
			break;
			i++;
		}
		int j;
		for(i=0;i<11;i++)
		{
			for(j=i+1;j<11;j++)
			{
				if(user[i].score<user[j].score)
				{
					temp=user[i];
					user[i]=user[j];
					user[j]=temp;
				}
			}
		}
		fclose(old);
		for(i=0;i<10;i++)
		{
			fwrite(&user[i],sizeof(user[i]),1,update);
		}
		fclose(update);
		remove("highscores.txt");
		rename("h1.txt","highscores.txt");
	}
}
void display()
{
	int i=0;
	FILE *fp;
	fp=fopen("highscores.txt","r");
	if(fp==NULL)
	puts("cant open file");
	else
	{   int l=10,k=10,m=10;
		box();
		gotoxy(65,7);
		printf("SCORE CARD");
		gotoxy(60,9);
		printf("SR#");
		gotoxy(65,9);
		printf("NAME");
		gotoxy(73,9);
		printf("SCORE");
		while(fread(&user[i],sizeof(user[i]),1,fp)>0)
		{
		gotoxy(60,m);
	    printf("%d",i+1);
	    m++;
		gotoxy(65,l);
		printf("%s",user[i].name);
		l++;
		gotoxy(75,k);
		printf("%d",user[i].score);
		k++;
			if(i>9)
			break;
			i++;
		}
	}
	fclose(fp);
}
int level()
{
int selection=0;
do
{
	box();
gotoxy(59,10);	
printf("1 - Beginner");
gotoxy(59,13);
printf("2 - Easy");
gotoxy(59,16);
printf("3 - Medium");
gotoxy(59,19);
printf("4 - Hard");
gotoxy(59,22);
printf("5 - Professional");
gotoxy(59,25);
printf("Enter a selection: ");
scanf("%d",&selection);
} while ((selection < 1) || (selection > 5));
return selection;
}
void login()
{
	int i;
	char user[100];
	char c;
	char y[4];
	box();
	gotoxy(59,15);
	printf("ENTER USERNAME : ");
	scanf("%s",user);
	gotoxy(59,17);
	printf("ENTER 4 DIGIT PIN CODE : ");
	for(i=0;i<4;i++)
	{
		c=getch();
		y[i]=c;
		printf("*");	
	}
	if((strcmp(y,"1234"))==0 && (strcmp(user,"moiz")==0||strcmp(user,"alex")==0||strcmp(user,"bob")==0))
	{
	gotoxy(59,19);
	printf("PASSWORD CORRECT\tLOADING");
	delay(1);
	system("cls");
	return;
	}
	else
	{    
	system("cls");
	box();
	gotoxy(60,15);
	printf("INCORRECT USERNAME/PASSWORD");
	delay(1);
	system("cls");
	box();
	login();
}
}
int main()
{
    int i;
    int horizontalTabs = 5;
    int verticalNewlines = 10;
    for ( i = 0; i < horizontalTabs; ++i) {
        printf("\t");
    }
    for ( i = 0; i < verticalNewlines; ++i) {
        printf("\n");
    }

    printf("\t\t\t\t\t\tWELCOME TO THE GAME ");
    sleep(3);
    printf("\n\n\n\t\t\t\t    {--------------QWERTY QUAKE--------------}");
    sleep(5);
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLOADING");
    for (i=0;i<10;i++){
    	printf(". ");
    	sleep(1);
	}
///////
	playBackgroundMusic();
	system("cls");
	login();
	int choice,lvl,score=0;
	int A;
	A:
	choice=menu();
	system("cls");
	if(choice==1)
	{    box();
		gotoxy(59,15);	
		printf("ENTER NAME : ");
		scanf("%s",input.name);
		system("cls");	
		lvl=level();
		system("cls");
		switch(lvl)
		{
			case 1:
			{
			letterpress1(&score);
			system("COLOR 06");
			filing();
			sort();
			score=0;
			goto A;
			}
			case 2:
			{
			letterpress2(&score);
			system("COLOR 06");
			filing();
			sort();
			score=0;
			goto A;	
			}
			case 3:
			{
			letterpress3(&score);
			system("COLOR 06");
			filing();
			sort();
			score=0;
			goto A;	
			}
			case 4:
			{
			letterpress4(&score);
			system("COLOR 06");
			filing();
			sort();
			score=0;
			goto A;	
			}
			case 5:
			{
			letterpress5(&score);
			system("COLOR 06");
			filing();
			sort();
			score=0;
			goto A;	
			}
			
		}
	}
	else if(choice==2)
	{
		display();
		box();
		gotoxy(58,25);
		printf("press any key to go to menu");
		getch();
		system("cls");
		goto A;
	}
	else if(choice==3)
	{
		return 0;
	}
}

