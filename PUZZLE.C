#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
int a[4][4]={
	    {5,1,13,4},
	    {8,12,10,2},
	    {3,14,15,6},
	    {7,9,11,0},
	    };
int b[4][4]={
	    {1,2,3,4},
	    {5,6,7,8},
	    {9,10,11,12},
	    {13,14,15,0},
	    };
int r,c,move=0;
void loading()
{
int x;
c=30;
r=10;
clrscr();
gotoxy(c,r);
textcolor(BLUE+BLINK);
cprintf("LOADING.............%c",2);
r=19;
textcolor(GREEN);
for(c=15;c<=75;c++)
{
gotoxy(c,r);
cprintf("\xcd");
}
r=21;
for(c=15;c<=75;c++)
{
gotoxy(c,r);
cprintf("\xcd");
}
gotoxy(15,19);
cprintf("\xc9");
gotoxy(15,21);
cprintf("\xc8");
gotoxy(75,19);
cprintf("\xbb");
gotoxy(75,21);
cprintf("\xbc");
gotoxy(15,20);
cprintf("%c",186);
gotoxy(75,20);
cprintf("%c",186);
textcolor(RED);
r=20;
for(c=16;c<=74;c++)
{
gotoxy(c,r);
cprintf("\xdb");
delay(100);
}
clrscr();
while(x!=13)
{
textcolor(WHITE);
cprintf("\n\n\n\n\n\n\n\n\n                          PRESS <ENTER> TO CONTINUE");
x=getch();
}
}
void box()
{
int i,j;
clrscr();
textcolor(2);
for(r=8;r<=16;r=r+2)
{
for(c=30;c<=42;c++)
{
gotoxy(c,r);
cprintf("%c",196);
}
}
for(c=30;c<=42;c=c+3)
{
for(r=8;r<=16;r++)
{
gotoxy(c,r);
cprintf("%c",179);
}
}
for(r=10;r<=14;r=r+2)
{
for(c=33;c<=39;c=c+3)
{
gotoxy(c,r);
cprintf("%c",197);
}
}
for(c=33;c<=39;c=c+3)
{
gotoxy(c,8);
cprintf("%c",194);
}
for(c=33;c<=39;c=c+3)
{
gotoxy(c,16);
cprintf("%c",193);
}
gotoxy(30,8);
cprintf("%c",218);
gotoxy(42,8);
cprintf("%c",191);

gotoxy(30,16);
cprintf("%c",192);

gotoxy(42,16);
cprintf("%c",217);

gotoxy(30,10);
cprintf("%c",195);
gotoxy(42,10);
cprintf("%c",180);
gotoxy(30,12);
cprintf("%c",195);
gotoxy(42,12);
cprintf("%c",180);
gotoxy(30,14);
cprintf("%c",195);
gotoxy(42,14);
cprintf("%c",180);
textcolor(WHITE);
i=0;
for(r=9;r<=15;r+=2)
{
j=0;
for(c=31;c<=40;c+=3)
{
gotoxy(c,r);
if(a[i][j]==0)
{
cprintf("  ");
}
else
{
cprintf("%d",a[i][j]);
}
j=j+1;
}
i=i+1;
}
}
void moves()
{
textcolor(YELLOW);
gotoxy(30,25);
cprintf("total no of moves used=%d",move);
}
int checkwin()
{
int count=0,i,j;
for(i=0;i<=3;i++)
{
for(j=0;j<=3;j++)
{
if(a[i][j]==b[i][j])
count=count+1;
}
}
if(count==16)
return(1);
else
return(0);
}
void main()
{
int x,y,temp,i=3,j=3,k=0;
_setcursortype(_NOCURSOR);
clrscr();
loading();
clrscr();
while(y!=13)
{
textcolor(RED);
cprintf("\n\n                                INSTRUCTIONS ");
textcolor(GREEN);
cprintf("\r\n\nTHIS GAME IS PUZZLE TYPE GAME IN WHICH TO WIN YOU HAVE TO ARRANGE ALL THE NUMBER  GIVEN IN THE BOX IN AN INCREASING ORDER..............");
cprintf("\r\n\nTO MOVE THE EMPTY BLOCK YOU CAN USE THE ARROW KEYS .........");
textcolor(WHITE);
cprintf("\r\n\n\n                         PRESS <ENTER> TO CONTINUE");
y=getch();
}
box();
while(x!=13)
{
clrscr();
box();
moves();
textcolor(YELLOW);
gotoxy(25,1);
cprintf("PRESS <ENTER> TO QUIT ......");
x=getch();
if(x==72)
{
i=i-1;
if(i>=0)
{
temp=a[i+1][j];
a[i+1][j]=a[i][j];
a[i][j]=temp;
++move;
moves();
}
else
{
++i;
gotoxy(25,5);
printf("WRONG CHOICE cant go more upwards");
delay(1000);
clrscr();
}
k=checkwin();
if(k==1)
{
clrscr();
printf("\n\n\t\t\tCONGRATULATIONS!!!!!!!!!\n\n\n\n\t\t\tYOU WIN!\n\n\n\t\tYOU COMPLETED THE PUZZLES IN %d MOVES",moves);
break ;
}
}
else if(x==80)
{
i=i+1;
if(i<=3)
{
temp=a[i-1][j];
a[i-1][j]=a[i][j];
a[i][j]=temp;
++move;
moves();
}
else
{
--i;
gotoxy(25,18);
printf("WRONG CHOICE cant go more downwards");
delay(1000);
clrscr();
}
k=checkwin();
if(k==1)
{
clrscr();
printf("\n\n\t\t\tCONGRATULATIONS!!!!!!!!!\n\n\n\n\t\t\tYOU WIN!\n\n\n\t\tYOU COMPLETED THE PUZZLES IN %d MOVES",moves);
break ;
}
}
else if(x==77)
{
j=j+1;
if(j<=3)
{
temp=a[i][j-1];
a[i][j-1]=a[i][j];
a[i][j]=temp;
++move;
moves();
}
else
{
--j;
gotoxy(45,13);
printf("WRONG CHOICE cant go more right");
delay(1000);
clrscr();
}
k=checkwin();
if(k==1)
{
clrscr();
printf("\n\n\t\t\tCONGRATULATIONS!!!!!!!!!\n\n\n\n\t\t\tYOU WIN!\n\n\n\t\tYOU COMPLETED THE PUZZLES IN %d MOVES",moves);
break ;
}
}
else if(x==75)
{
j=j-1;
if(j>=0)
{
temp=a[i][j+1];
a[i][j+1]=a[i][j];
a[i][j]=temp;
++move;
moves();
}
else
{
++j;
gotoxy(2,13);
printf("WRONG CHOICE cant go left");
delay(1000);
clrscr();
}
k=checkwin();
if(k==1)
{
clrscr();
printf("\n\n\t\t\tCONGRATULATIONS!!!!!!!!!\n\n\n\n\t\t\t  YOU WIN!\n\n\n\t\tYOU COMPLETED THE PUZZLES IN %d MOVES",move);
break ;
}
}
}
}
