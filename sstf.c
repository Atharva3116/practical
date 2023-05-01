#include<stdio.h>
#include<stdlib.h>

int req[20],n,head,cyl,i,flag[10]={0},thm=0;
void accept()
{
	printf("Enter Number of Cylinder:");
	scanf("%d",&cyl);
	printf("Enter the current head position:");
	scanf("%d",&head);
	printf("Enter Number of Requests:");
	scanf("%d",&n);
		
	printf("\nEnter Request in Sequence :");
	for(i=1;i<n+1;i++)
	{
		printf("[%d]=",i);
		scanf("%d",&req[i]);
	}
}
void display()
{
	printf("Total Number of head movements is:%d",thm);
}

int sstf()
{
	int i,index,m;
	for(i=0;i<n;i++)
	{
		index=diff(head);
		if(head>req[index])
		{
			m=head-req[index];
			thm=thm+m;
		}
		else
		{
			m=req[index]-head;
			thm=thm+m;
		}
		head=req[index];
		flag[index]=1;
	}
	
}

int diff()
{
	int i,d[20]={-1},min=32565,index,indexd,cnt=0;
	for(i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			if(req[i]>head)
				d[i]=req[i]-head;
			
		}
	}
	for(i=0;i<n;i++)
	{
		if(d[i]<min && flag[i]==0)
		{
			min=d[i];
			index=i;
		}
	}
	for(i=0;i<n;i++)
	{
		if(d[i]==min)
		{
			cnt++;
			indexd=i;
		}
	}
	if(cnt==1)
		return index;
	else
	{
		if(req[index]>req[indexd])
			return index;

		else 
			return indexd;
	}
}

void main()
{
	accept();
	sstf();
	display();
}


