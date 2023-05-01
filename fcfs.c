#include<stdio.h>
#include<stdlib.h>
int head,n,req[20],thm,cyl;
void accept();
void display();

void accept()
{
	printf("Enter Number of Cylinder:");
	scanf("%d",&cyl);
	printf("Enter Number of Requests:");
	scanf("%d",&n);
	printf("Enter the current head position:");
	scanf("%d",&head);
	for(int i=0;i<n;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&req[i]);
	} 
}
 void display()
{
	printf("Total Number of head movements is:%d",thm);
}
 void fcfs()
{
	int m,i;
	for(int i=0;i<n;i++)
	{
		if(head<req[i])
		{
			m=req[i]-head;
			thm=thm+m;
			head=req[i];
		}
		else
		{
			m=head-req[i];
			thm=thm+m;
			head=req[i];
		}
	}
}
void main()
{
	accept();
	fcfs();
	display();
}
