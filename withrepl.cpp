#include<stdio.h>
#include<stdlib.h>

int hash[10][2];

void insertion(int data);
void display();
void insertion(int data)
{
int key,i,j,a;


key=data%10;
    if(hash[key][0]==-1)
      {
          
	      hash[key][0]=data;
	      
		  hash[key][1]=-1;
	  }
      else
      {
      	i=key;
      	a=hash[i][0]%10;
      	if(a!=key)
      	{
      	 	j=hash[key][0];
      		hash[key][0]=data;
      		
			insertion(j);

		}
      	else
      	{
      		while(i<10)
      	   { 
      		
      		if(hash[i][0]==-1)
      		{
      			
      			hash[i][0]=data;
      			hash[key][1]=i;
      			break;
			}
			i++;
		   }
		}
      }
}
void display()
{
	int i;
	
	      for(i=0;i<10;i++)
	      {
	      	if(hash[i][0]==-1)
	      	{
			  printf("%d=NULL  NULL\n",i); 
			}
			else
			{
			printf("%d=%d",i,hash[i][0]);
			if(hash[i][1]==-1)
			{
				printf(" NULL");
			}
			else
			{
				printf(" %d",hash[i][1]);
			}
			printf("\n");
		  }
}
}
main()
{
	int i,choice,data;
	for(i=0;i<10;i++)
	{
		hash[i][0]=-1;
	    hash[i][1]=-1;
	}
	
	loop:
	printf("\nenter choice\n"
	        "\n(1).to insert"            
			"\n(2).to display\n");
	scanf("%d",&choice);
	if(choice==1)
	{
	   printf("\nenter data to be inserted\n");
	   scanf("%d",&data);
	   insertion(data);	
	   goto loop;
    }		
    else if(choice==2)
    {
    	printf("your hash table is \n");
    	display();
    	goto loop;
	}
	else
	{
	}
}
