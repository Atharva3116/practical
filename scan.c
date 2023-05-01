#include<stdio.h>
#include<stdlib.h>

int req[20],cyl,n,head,i,thm=0,j,k,min[20],max[20],temp;
char dir;
void accept()
{

	printf("\nEnter total number of cylinder = ");
	scanf("%d",&cyl);

	printf("\nEnter Current Head Position = ");
	scanf("%d",&head);

	printf("\nEnter Number of Request = ");
	scanf("%d",&n);

	printf("\nEnter Request in Sequence :");
	for(i=0;i<n;i++)
	{
		printf("\n%d=",i);
		scanf("%d",&req[i]);
	}
	printf("\nEnter direction :");
	scanf("%s",&dir);
}
void display()
{
	printf("\nTotal head movements:\n %d",thm);
}
void sort()
{
	int temp,mx,mn;
	for(int i=0;i<n;i++)
	{
		if(req[i]>head)
			max[j++]=req[i];
		else
			min[k++]=req[i];
	}
	printf("\n Minimum\n");
	for(int i=0;i<k;i++)
		printf("\t%d",min[i]);
	printf("\n Maximum\n");
	for(int i=0;i<j;i++)
		printf("\t%d",max[i]);	

	for(int i=0;i<k;i++)
	{
		for(int l=0;l<k-i-1;l++)
		{
			if(min[l]>min[l+1])
			{
				temp=min[l];
				min[l]=min[l+1];
				min[l+1]=temp;
			}
		}
	}
	printf("\n Minimum\n");
	for(int i=0;i<k;i++)
		printf("\t%d",min[i]);	

	for(int i=0;i<j;i++)
	{
		for(int l=0;l<j-i-1;l++)
		{
			if(max[l]>max[l+1])
			{
				temp=max[l];
				max[l]=max[l+1];
				max[l+1]=temp;
			}
		}
	}
	printf("\n Maximum\n");
	for(int i=0;i<j;i++)
		printf("\t%d",max[i]);	
} 

void thmcd()
{
	sort();
	if(dir=='l')
	{
		thm=thm+head;
		thm=thm+max[j-1];
	}
	else if(dir=='r')
	{
		thm=(cyl-1)-head;
		thm=thm+((cyl-1)-min[0]);
	}
	else
	printf("Invalid Input\n");
}
int main()
{
	accept();
	thmcd();
	display();
}

