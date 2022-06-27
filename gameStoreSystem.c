#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct game
{
char name[50];
char platform[20];
int year;
char condition[10];
int stock;

};

void append(); void searchn(); void displayAll(); void del(); void searchp();void modify();
int main()
{
int ch;

while(1)
{

printf("************Videogame stock system************\n\n");

printf("1. Add a videogame\n\n");
printf("2. Delete from stock\n\n");
printf("3. Modify an entry\n\n");
printf("4. Search by platform\n\n");
printf("5. Search by name\n\n");
printf("6. Display all stock\n\n");
printf("0. Exit\n\n");

printf("**********************************************\n\n");

printf("\nEnter your choice: ");
scanf("%d",&ch);

switch(ch)
{
case 1: append();
break;

case 2: del();
break;

case 3: modify();
break;
case 4: searchp();
break;

case 5: searchn();
break;

case 6: displayAll();
break;

case 0: exit(0);
}
}

return 0;
}

void append()
{
FILE *fp;
struct game t1;

fp=fopen("games.txt","a");
printf("\nEnter name: ");
scanf("%s",t1.name);
printf("\nEnter platform: ");
scanf("%s",t1.platform);
printf("\nEnter year: ");
scanf("%d",&t1.year);
printf("\nEnter condition: ");
scanf("%s",t1.condition);
printf("\nEnter stock nr: ");
scanf("%d",&t1.stock);
fprintf(fp, "%s %s %d %s %d\n",t1.name, t1.platform, t1.year, t1.condition, t1.stock);

fclose(fp);
printf("\n");
}

void del()
{

FILE *fp,*fp1;
struct game t, t1;
int found=0;
char name[30];
fp=fopen("games.txt","r");
fp1=fopen("temp.txt","w");
printf("\nEnter the game you want to delete from stock: ");
scanf("%s",name);
while(1)
{ if(fp==0) break;
fscanf(fp,"%s %s %d %s %d\n",t.name,t.platform, &t.year, t.condition, &t.stock);
if(strcmp(t.name,name)==0)
{
found++;
}
else
{
fprintf(fp1, "%s %s %d %s %d\n",t.name, t.platform, t.year, t.condition, t.stock);
}
if(feof(fp)) break;
}
fclose(fp);fclose(fp1);

if(found==0)
{
printf("\nSorry, no records found\n\n");
}
else
{
fp=fopen("games.txt","w");
fp1=fopen("temp.txt","r");
while(1)
{
fscanf(fp1, "%s %s %d %s %d\n",t1.name,t1.platform, &t1.year, t1.condition, &t1.stock);
fprintf(fp, "%s %s %d %s %d\n",t1.name, t1.platform, t1.year, t1.condition, t1.stock);
if(feof(fp1)) break;
}}
fclose(fp);fclose(fp1);
if(found>0) printf("\nSuccesfully deleted the entry from stock\n\n");}
void modify()
{
FILE *fp,*fp1;
struct game t, t1;
int found=0;
char name[30];
fp=fopen("games.txt","r");
fp1=fopen("temp.txt","w");
printf("\nEnter the name of the game you want to modify: ");
scanf("%s",name);
while(1)
{ if(fp==0) break;
fscanf(fp,"%s %s %d %s %d\n",t.name,t.platform, &t.year, t.condition, &t.stock);
if(strcmp(t.name,name)==0)
{
found++;
printf("\nEnter a new name: ");
scanf("%s", t.name);
printf("\nEnter a platform: ");
scanf("%s", t.platform);
printf("\nEnter year: ");
scanf("%d", &t.year);
printf("\nEnter condition: ");
scanf("%s", t.condition);
printf("\nEnter stock: ");
scanf("%d", &t.stock);
fprintf(fp1, "%s %s %d %s %d\n",t.name, t.platform, t.year, t.condition, t.stock);
}
else
    fprintf(fp1, "%s %s %d %s %d\n",t.name, t.platform, t.year, t.condition, t.stock);
if(feof(fp)) break;
}
fclose(fp);fclose(fp1);

if(found==0)
{
printf("\nSorry, no records to modify found\n\n");
}
else
{
fp=fopen("games.txt","w");
fp1=fopen("temp.txt","r");
while(1)
{
fscanf(fp1, "%s %s %d %s %d\n",t1.name,t1.platform, &t1.year, t1.condition, &t1.stock);
fprintf(fp, "%s %s %d %s %d\n",t1.name, t1.platform, t1.year, t1.condition, t1.stock);
if(feof(fp1)) break;
} fclose(fp);fclose(fp1);}
if(found>0) printf("\nSuccesfully modified the entry\n\n");}

void searchn()
{
FILE *fp;
struct game t;
int found=0;
char name[40];

fp=fopen("games.txt","r");

printf("\nEnter the name of the game: ");
scanf("%s", name);
printf("\n**********************************************\n\n");
while(1)
{ if(fp==0) break;
fscanf(fp,"%s %s %d %s %d\n",t.name,t.platform, &t.year, t.condition, &t.stock);

if(strcmp(name,t.name)==0)
{ found=1;

printf("Platform  Year  Condition  Stock\n");
printf("%s\t  ",t.platform);
printf("%d\t",t.year);
printf("%s\t   ",t.condition);
printf("%d\n\n",t.stock);
}

if(feof(fp))
break;


}
if(found==0)
{
printf("\n\t\tSorry, no games Found\n\n");
}
fclose(fp);
printf("\n**********************************************\n\n");
}

void searchp()
{
FILE *fp;
struct game t;
int found=0;
char platform[20];

fp=fopen("games.txt","r");

printf("\nEnter the platform: ");
scanf("%s", platform);
printf("\n**********************************************\n\n");
printf("\tGames on the platform %s\n\n", platform);

while(1)
{ if(fp==0) break;
fscanf(fp,"%s %s %d %s %d\n",t.name,t.platform, &t.year, t.condition, &t.stock);

if(strcmp(platform,t.platform)==0)
{ found=1;
printf("%s\t",t.name);
printf("%d\t",t.year);
printf("%s\t",t.condition);
printf("%d\n",t.stock);

}
if(feof(fp))
break;
}
if(found==0)
{
printf("\n\t\tSorry, no games Found\n");
}
printf("\n**********************************************\n\n");
fclose(fp);
}
void displayAll()
{ int k=0;
FILE *fp;
struct game t;
fp=fopen("games.txt","r");
printf("\n\n**********************************************\n");
printf("\n\t\t All games\n\n");
while(1)
{ if(fp==0) break;
fscanf(fp,"%s %s %d %s %d\n",t.name,t.platform, &t.year, t.condition, &t.stock);
printf("%s\t",t.name);
printf("%s\t",t.platform);
printf("%d\t",t.year);
printf("%s\t",t.condition);
printf("%d\n\n",t.stock);
k=1;
if(feof(fp)) break;
}
fclose(fp);
if(k==0)
    printf("Sorry, no records found\n\n");
printf("**********************************************\n\n");}
