// Hash table with binary tree ... time complexity.. O(1)*O(logn);

#include<stdio.h>
#include<stdlib.h>

struct hash{
	int data;
	struct hash *lptr;
	struct hash *rptr;
};
typedef struct hash node;

node *root[10],new;

// function declaration...
void insertion_hash(node *);
void  display_hash(node *);
void search_hash(node *);
int d;

main()
{
	int n,x;
	int key;
	n:
	printf("1 - Insertion\n");
	printf("2 - Display\n");
	printf("3 - Search\n");
	printf("4 - Exit\n");
	scanf("%d",&x);
	switch(x)
	{
		case 1:
			printf("Enter Data: ");
	 		scanf("%d",&d);
	 		key=d%10;
	 		
	 		//make new node ...
	 		
	 		new=(node *)malloc(sizeof(node));
			new->data=d;
			new->lptr=NULL;
			new->rptr=NULL;
	 		
			insertion_hash(root[key]);
			break;
		case 2:
			display_hash();
			break;
		case 3:
			printf("Enter Data: ");
	 		scanf("%d",&d);
	 		key=d%10;
			search_hash(root[key]);
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

void insertion_hash(node *temp)
{
	
	node *save,*pre;
	 
		if(root[key]==NULL)
		{
			root[key]=(node *)malloc(sizeof(node));
			root[key]->data=d;
			root[key]->lptr=NULL;
			root[key]->rptr=NULL;
			}	
		else
		{
			if(new->data < temp->data)
			{
				//pre=temp;
				if(temp->lptr!=NULL)
				insertion_hash(temp->lptr);
			}
			
			
			else if(new->data > temp->data)
			{
				//pre=temp;
				if(temp->rptr!=NULL)
				insertion_hash(temp->rptr);
			}
			
			
		
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
		if(root[i]==NULL)
		printf("index %d = NULL\n",i);
		else{
			save=root[i];	
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

	node *save;
	 
	int i=1;
	
	if(root[key]->data==d)
		printf("Your data Found at key : %d pos : 1\n",key);		
	else
	{
		save=root[key];
		
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
