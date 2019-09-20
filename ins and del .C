#include<stdio.h>
#include<conio.h>
struct node
{int data;
struct node *next;
};

typedef struct node nd;

void binsert(nd * head)
{ nd *new;
  new=(nd *)malloc(sizeof(nd));
  if(new==NULL)
	printf("INSERTION NOT POSSIBLE\n");
  else
  {
	printf("Enter number to insert\n");
	scanf("%d",&new->data);
	new->next=head->next;
	head->next=new;
  }
}
void einsert(nd *head)
{       nd *ptr=head,*new;
	new=(nd *)malloc(sizeof(nd));
	if(new==NULL)
		printf("INSERTION NOT POSSIBLE\n");
	else
	{
		while(ptr->next!=NULL)
			ptr=ptr->next;
		printf("Enter element to insert\n");
		scanf("%d",&new->data);
		ptr->next=new;
		new->next=NULL;
	}
}
int minsert(nd * head,int num)
{       nd* ptr=head,*new;
	new=(nd *)malloc(sizeof(nd));
	if(new==NULL)
		printf("INSERTION NOT POSSIBLE");
	else
	{
		while(ptr->data!=num&&ptr!=NULL)
		{
			ptr=ptr->next;
		}
		if(ptr==NULL)
		  {printf("Element not found\n");
		   return 0;}

		else
		{       printf("Enter number to insert\n");
			scanf("%d",&new->data);
			new->next=ptr->next;
			ptr->next=new;

		}


	}
	return 0;
}


void display(nd *n)
{       n=n->next;
	printf("\n The Linked list ** \n");
	while(n!=NULL)
		{printf("%d ",n->data);
		 n=n->next;
		 }
}
void bdelet(nd *head)
{       nd *ptr;
	if(head->next==NULL)
		printf("NO ELEMENT IN LIST\n");
	else
	{  ptr=head->next;
	   printf("Deleted element is %d \n",ptr->data);
	   head->next=ptr->next;
	   free(ptr);
	}
}
int mdelet(nd *head,int num)
{
	nd *ptr,*ptr1;
	if(head->next==NULL)
		printf("NO ELEMENT IN LIST");
	else
	{
			while(ptr->data!=num&&ptr!=NULL)
		{       ptr1=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL)
		 {	printf("Element not found\n");
			 return 0;
			 }

		else{ printf("Deleted element is %d\n",ptr->data);
		 ptr1->next=ptr->next;
		 free(ptr);}

	}
	return 0;
}
void edelet(nd *head)
{ nd *ptr=head,*ptr1;
	while(ptr->next!=NULL)
	      {ptr1=ptr;
	      ptr=ptr->next;}
	printf("Deleted number is %d\n",ptr->data);
	ptr1->next=NULL;
	free(ptr);

}
void main()
{
	nd * head;
	int n,num;
	clrscr();
	head=(nd *)malloc(sizeof(nd));
	head->data=NULL;
	head->next=NULL;
	while(1)
	{
		printf("\n\nMAIN MENU:\n\n1.INSERT ELEMENT\n2.DELETE\n3.DISPLAY\n4.EXIT\n\nENTER YOUR CHOICE:\n");
		scanf("%d",&n);
		switch(n)
		{	case 1:{ printf("\t1.INSERT AT BEGINING\n\t2.INSERT AFTER A NUMBER\n\t3.INSERT AT END\n\tENTER YOUR CHOICE\n");
				 scanf("%d",&n);
				 switch(n)
					{ case 1: {binsert(head);
						  display(head);
						  break;}
					  case 2: {printf("\tEnter number after which insertion to be done\n");
						   scanf("%d",&num);
						  minsert(head,num);
						  display(head);
						  break;  }
					  case 3:{einsert(head);
						  display(head);
						  break;}



					} break;
				}
			case 2:{printf("\t1.DELETE AT BEGINING\n\t2.DELETE A NUMBER\n\t3.DELETE END NUMBER\n\tENTER YOUR CHOICE\n");
				 scanf("%d",&n);
				 switch(n)
					{ case 1: {bdelet(head);
						  display(head);
						  break;}
					  case 2: {printf("\tEnter number to be deleted\n");
						   scanf("%d",&num);
						  mdelet(head,num);
						  display(head);
						  break;  }
					  case 3:{edelet(head);
						  display(head);
						  break;}



					} break;

				}
			case 3:   { display(head);
					break;}

			case 4:    exit(0);

			default: {  printf("INCORRECT INPUT\n");
					break; }

}
}}