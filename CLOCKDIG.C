#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void main()
{
int h,m,s;
clrscr();
printf("enter time hh:mm:ss");
scanf("%d%d%d",&h,&m,&s);
while(s<=60&&m<=60&&h<=24)
{
s=s+1;
if(s==60)
{
m=m+1;
s=0;
}
if(m==60)
{
h=h+1;
m=0;
}
if(h==24)
break;
printf("\n\n\n\t\t\tHH\t:\tMM\t:\tSS");
printf("\n\n\n\n\t\t\t%d\t:\t%d\t:\t%d\t",h,m,s);
delay(1000);
clrscr();
}
getch();
}