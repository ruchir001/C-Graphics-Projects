#include<stdio.h>
#include<conio.h>
void main()
{
int r,c;
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


getch();
}