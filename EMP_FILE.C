//                          PASSWORD IS heybuddy in small
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
void menu();
void createemp();
void displayall();
void modify();
void deletespc();
struct emp
{
int empno;
char empname[20];
int basicpay;
}e;
FILE *fp;
void main()
{
char password[20];
int choice;
clrscr();
printf("\n\n\n\n\n\t\tENTER THE PASSWORD TO ACCESS DATABASE ");
scanf("%s",password);
if(strcmp(password,"heybuddy")==0)
{
clrscr();
do
{
fp=fopen("recordemp.c","a+");
menu();
printf("\n\n\n\t\tenter your choice   ");
fflush(stdin);
scanf("%d",&choice);
fflush(stdin);
if(choice==1)
{
clrscr();
createemp();
fflush(stdin);
}
else if(choice==2)
{
clrscr();
displayall();
fflush(stdin);
}
else if(choice==3)
{
clrscr();
deletespc();
remove("recordemp.c");
rename("temp.c","recordemp.c");
fflush(stdin);
}
else if(choice==4)
{
clrscr();
modify();
fflush(stdin);
}
}while(choice!=5);
getch();
}
else
{
clrscr();
printf("\n\n\n\t\t\twrong password\n\n\t\trun the progam again and enter correct password");
getch();
}
}
void menu()
{
clrscr();
printf("\n\n\t\t\t1. add a employee to database\n\t\t\t2. display all\n\t\t\t3. delete an employee data\n\t\t\t4. modify a employee's data\n\t\t\t5. exit");
}
void createemp()
{
printf("\n\n\tenter employee no.  ");
scanf("%d",&e.empno);
fflush(stdin);
printf("\n\n\tenter employee name   ");
gets(e.empname);
printf("\n\n\tenter basic salary  ");
scanf("%d",&e.basicpay);
fwrite(&e,sizeof(e),1,fp);
clrscr();
printf("\n\n\n\n\n\n\t\tEMPLOYEE ADDED TO DATABASE");
getch();
fclose(fp);
}
void displayall()
{
int i=0;
printf("\n\tS.no\t\tempno.\t\tempname\t\t\tbasic salary");
rewind(fp);
fread(&e,sizeof(e),1,fp);
while(!feof(fp))
{
i=i+1;
printf("\n\n\t%d\t\t%d\t\t%s",i,e.empno,e.empname);
printf("\t\t\t%d",e.basicpay);
fread(&e,sizeof(e),1,fp);
}
getch();
fclose(fp);
}

void deletespc()
{
FILE *fr;
int no,k=0;
fr=fopen("temp.c","a+");
printf("\n\n\n\tenter the empno whose data to be deleted    ");
scanf("%d",&no);
rewind(fp);
fread(&e,sizeof(e),1,fp);
while(!feof(fp))
{
if(e.empno==no)
{
printf("\n\n\n\t\temployee data erased");
fread(&e,sizeof(e),1,fp);
k=1;
}
else
{
fwrite(&e,sizeof(e),1,fr);
fread(&e,sizeof(e),1,fp);
}
}
fclose(fr);
fclose(fp);
if(k==0)
{
printf("\n\n\n\t\temployee not found");
}
getch();
}
void modify()
{
int no,k=0;
int chc;
char b='y';
fread(&e,sizeof(e),1,fp);
printf("\n\n\n\t\tenter empno whose details to be modified    ");
scanf("%d",&no);
rewind(fp);
while(!feof(fp)&&k==0)
{
if(e.empno==no)
{
k=1;
while(b=='y')
{
clrscr();
printf("\n\n\n\t\t1. empno.\n\t\t2. name\n\t\t3.basic pay");
printf("\n\nenter yor choice what to modify    ");
scanf("%d",&chc);
if(chc==1)
{
clrscr();
printf("\n\n\n\t\tenter new empno  ");
scanf("%d",&e.empno);
printf("\n\n\nmore thing to modify in this employees record (y or n)  ");
scanf("%c",&b);
}
else if(chc==2)
{
clrscr();
printf("\n\n\n\t\tenter new emp name   ");
gets(e.empname);
fflush(stdin);
printf("\n\n\nmore thing to modify in this employees record (y or n)  ");
scanf("%c",&b);
}
else if(chc==3)
{
clrscr();
printf("\n\n\n\t\tenter new basic pay  ");
scanf("%d",&e.basicpay);
printf("\n\n\nmore thing to modify in this employees record (y or n)  ");
scanf("%c",&b);
}
}
fseek(fp,-sizeof(e),SEEK_CUR);
fwrite(&e,sizeof(e),1,fp);
}
fread(&e,sizeof(e),1,fp);
}
if(k==0)
printf("\n\n\n\t\temployee not found ");
getch();
fclose(fp);
}