#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define NULL 0
struct node
{
int info;
struct node*next;
};
typedef struct node*NODEPTR;
NODEPTR getnode();
NODEPTR f,r,s,k;
void addfront(int);
void addmid(int,int);
void addend(int);
void print(void);
int count=0;
main()
{
int a,b,d,item,pos;
char c='y';
while(c=='y')
{
clrscr();
printf("\t\t            INSERTION");
printf("\n\t\t          ----------");
printf("\n\n1>FRONT INSERTION\t\t2>MIDDLE INSERTION");
printf("\n3>END INSERTION\t\t\t4>PRINT\n5>EXIT");
printf("\n\n\t\tENTER YOUR CHOICE:");
scanf("%d",&a);
clrscr();
switch(a)
{
case 1: printf("\t\tFRONT INSERTION");
	printf("\n\t\t-------------------------------------");
	printf("\n\n\tENTER THE ELEMENT");
	scanf("%d",&item);
	addfront(item);
	break;
case 2: printf("\t\t MIDDLE INSERTION");
	printf("\n\t\t--------------------------------------");
	if(count==0)
		printf("\n\n****VOID INSERTION****");
	else
		{
		printf("\nENTER THE ELEMENT:");
		scanf("%d",&item);
		printf("\nENTER THE POSITION:");
		scanf("%d",&pos);
		addmid(item,pos);
		}
	break;
case 3: printf("\t\t END INSERTION");
	printf("\n\t\t----------------------------------------");
	if(count==0)
		printf("\n\n****VOID INSERTION****");
	else
		{
		printf("\n\nENTER THE ELEMENT:");
		scanf("%d",&item);
		addend(item);
		}
	break;
case 4: print();
	break;
case 5: return(0);
}
printf("\n\n\tDO YOU WANT TO CONTINUE(y/n)");
fflush(stdin);
scanf("%c",&c);
}
return 0;
}
NODEPTR getnode()
{
NODEPTR p;
p=(NODEPTR)malloc(sizeof(struct node));
return(p);
}
void addfront(int item)
{
NODEPTR p;
p=getnode();
if(count!=NULL)
	{
	p->next=f;
	p->info=item;
	f=p;
	print();
	count++;
	}
else
	{
	f=p;
	p->next=NULL;
	p->info=item;
	r=p;
	count++;
	print();
	}
}
void addmid(int item,int pos)
{
int i;
NODEPTR p,k;
if(pos==1)
	{
	p=getnode();
	p->next=f;
	p->info=item;
	f=p;
	print();
	count++;
	}
else
	{
	k=getnode();
	p=f;
	for(i=1;i<=pos-2;i++)
	p=p->next;
	k->next=p->next;
	p->next=k;
	k->info=item;
	k=p;
	print();
	count++;
	}
}
void addend(int item)
{
NODEPTR p;
p=getnode();
r->next=p;
p->next=NULL;
p->info=item;
r=p;
print();
count++;
}
void print()
{
NODEPTR p;
if(count==0)
	printf("\n\n\t\t*****THE LIST DOES NOT EXIST*****");
else
	{
	printf("\n\n\t\t\t****THE LIST IS****\n\n");
	p=f;
	while(p!=NULL)
		{
		printf("|%3d|",p->info);
		p=p->next;
		}
	}
}


