#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
void board();
int winner();
int e,f,i=-1;
char player1[10],player2[10];
char s[9]={'1','2','3','4','5','6','7','8','9'},choice,mark;
void main()
{
int player=0;
clrscr();
printf("\t enter name of player 1 ");
scanf("%s",&player1);
printf("\n\n\t enter name player 2 ");
scanf("%s",&player2);
do
{

board();
player=player+1;
player=(player%2==1)?1:2;
mark=(player==1)?'O':'X';
if(player==1)
{
printf("\n\nenter your choice %s(O)",player1);
scanf("%c",&choice);
}
else
{
printf("\n\nenter your choice %s(X)",player2);
scanf("%c",&choice);
}
if(choice=='1'&&s[0]=='1')
{
s[0]=mark;

}
else if(choice=='2'&&s[1]=='2')
{
s[1]=mark;
}
else if(choice=='3'&&s[2]=='3')
{
s[2]=mark;
}
else if(choice=='4'&&s[3]=='4')
{
s[3]=mark;
}
else if(choice=='5'&&s[4]=='5')
{
s[4]=mark;
}
else if(choice=='6'&&s[5]=='6')
{
s[5]=mark;
}
else if(choice=='7'&&s[6]=='7')
{
s[6]=mark;
}
else if(choice=='8'&&s[7]=='8')
{
s[7]=mark;
}
else if(choice=='9'&&s[8]=='9')
{
s[8]=mark;
}
else
{
printf("wrong choice");
player=player-2;
}
i=winner();
clrscr();
}while(i==-1);
if(i==1)
{
if(player==1)
printf("\n\n\t %s wins",player1);
else
printf("\n\n\t %s wins",player2);
}
else
printf("\n\n\tgame draw");
getch();
}
void board()
{
int k,l,n=0;
for(k=35;k<=45;k+=10)
{
for(l=11;l<=21;l++)
{
gotoxy(k,l);
printf("|");
}
}
for(k=14;k<=18;k+=4)
{
for(l=28;l<=52;l++)
{
gotoxy(l,k);
printf("-");
}
}
for(e=13;e<=19;e+=3)
{
for(f=32;f<=48;f+=8)
{
gotoxy(f,e);
printf("%c",s[n]);
n=n+1;
}
}
}
int winner()
{
if(s[0]==s[1]&&s[1]==s[2])
return(1);
else if(s[3]==s[4]&&s[4]==s[5])
return(1);
else if(s[6]==s[7]&&s[7]==s[8])
return(1);
else if(s[0]==s[3]&&s[3]==s[6])
return(1);
else if(s[1]==s[4]&&s[4]==s[7])
return(1);
else if(s[2]==s[5]&&s[5]==s[8])
return(1);
else if(s[0]==s[4]&&s[4]==s[8])
return(1);
else if(s[6]==s[4]&&s[4]==s[2])
return(1);
else if(s[0]=='1'||s[1]=='2'||s[2]=='3'||s[3]=='4'||s[4]=='5'||s[5]=='6'||s[6]=='7'||s[7]=='8'||s[8]=='9')
return(-1);
else
return(0);
}