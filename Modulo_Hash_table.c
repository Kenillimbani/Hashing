// Hash table with Linked_list ... time complexity.. O(1)*O(n);
#include<stdio.h>
#include<stdlib.h>

struct hash{
	int data;
	struct hash *next;
};
typedef struct hash node;

node *head[10];

// function declaration...
void insertion_hash();
void  display_hash();
void search_hash();



main()
{
	int n,x;
	n:
	printf("1 - Insertion\n");
	printf("2 - Display\n");
	printf("3 - Search\n");
	printf("4 - Exit\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			insertion_hash();
			break;
		case 2:
			display_hash();
			break;
		case 3:
			search_hash();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Entered wrong choice\n");
			break;
	}
	goto n;
}

void insertion_hash()
{
	int d,key;
	node *new,*save;
	 printf("Enter Data: ");
	 scanf("%d",&d);
	
	key=d%10;
		
		if(head[key]==NULL)
		{
			head[key]=(node *)malloc(sizeof(node));
			head[key]->data=d;
			head[key]->next=NULL;
			}	
		else
		{
			new=(node *)malloc(sizeof(node));
			new->data=d;
			new->next=NULL;
			
			save=head[key];
			
			while(save->next!=NULL)
			save=save->next;
			
			save->next=new;
			//printf("node added\n");
		}
	
}

void display_hash()
{
	node *save;
	int i;
	printf("\n");
	for(i=0;i<10;i++)
	{
		if(head[i]==NULL)
		printf("index %d = NULL\n",i);
		else{
			save=head[i];	
			printf("index %d = ",i);
			
			while(save->next!=NULL)
			{
			printf("%d-->",save->data);
			save=save->next;
			}
			
			printf("%d\n",save->data);
		}
	}
	printf("\n");
}

void search_hash()
{
	int d,key;
	node *save;
	 printf("Enter Data: ");
	 scanf("%d",&d);
	
	key=d%10;
	int i=1;
	
	if(head[key]->data==d)
		printf("Your data Found at key : %d pos : 1\n",key);		
	else
	{
		save=head[key];
		
		while(save->next!=NULL && save->data!=d)
		{
		save=save->next;
		i++;
		}
		if(save->data!=d)
		printf("Data not found\n");
		else
		printf("Your data Found at key : %d pos : %d\n",key,i);
	}
}







