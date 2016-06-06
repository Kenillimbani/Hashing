// Chaining without Replacement...	

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data,link;
	
};
main()
{   
    struct node a[10];
	int t,v=1,i,index,s,sq,j,sqr,sum=0,temp;
	
	float k;
	printf("enter value\n1 : for division hase function\n 2 : for mid square\n 3 : for digit folding\n 4 : for multiplicative");
	scanf("%d",&s);
	
	for(i=0;i<10;i++)
	{
		a[i].data='\0';
		a[i].link=-1;	
	}
	
	do
	{
		printf("Enter value :");
	 	scanf("%d",&t);
	 	
	 	switch(s)
	    {
		case 1:
			//printf("nn");
		    index=t%10;
			break;
		case 2:
			sq=t*t;
			sqr=sq;
			for(i=0;sq!=0;i++)
			{ sq=sq/10;
			}
			for(j=1;j<=(i/2)+1;j++)
			{
			  index=sqr%10;
			  sqr=sqr/10;	
			}
				
			break;
		case 3:
		    sum=0;
		    sq=t;
			for(i=0;sq!=0;i++)
			{ 
			  sum=sum+(sq%10);
			  sq=sq/10;
			}
			index=sum%10;
	       printf("%d",index);
		case 4:
			//printf("xx");
			k=t*0.4;
			index=10*(k-(int)k);
			break;
			
        }
		if(a[index].data=='\0')
	 	{   printf("\nfirst time\n");
		 	a[index].data=t;
	    }
	    else
	    {   
	      	temp=index;
	      //	printf("before temp=%d",temp);
	      	while(a[temp].data!='\0')
	    	{
	    		temp=temp+1;
	    	//	printf("incresing temp=%d",temp);
			}
		//	printf("after temp=%d",temp);
	    	if(temp>9)
			{
				printf("...OVERFLOW...");
			}	
			else
			{
			    a[index].link=temp;
				a[temp].data=t;
			}	
	    }
		printf("\n if u still want to insert then press 1 otherwise 0 : ");
	 	scanf("%d",&v);
	    
	}while(v==1);
	
	
	
	
	for(i=0;i<10;i++)
    {   
        printf("\n%d...",i);
        if(a[i].data!='\0')
		{
			printf("%d  | %d",a[i].data,a[i].link);
		}
	}
	 
}
