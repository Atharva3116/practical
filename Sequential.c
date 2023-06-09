#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void show_bitvector();
int search(char *);
void show_directory();
void create_file();
void delete_file();

struct FAT
{
	char fname[20];
	int ib;
	int nob;
	struct FAT *next;
}*head=NULL;

int *bitvector,total_block;
int main()
{
	int i,ch;
	printf("\nEnter No of Blocks\n");
	scanf("%d",&total_block);

	bitvector=(int *)malloc(total_block*(sizeof(int)));
	for(i=0;i<total_block;i++)
	{
		bitvector[i]=0;
	}

	while(1)
	{
		printf("\n*********************MENU***********************\n1:Show Bit Vector\n2:Create New File\n3:Show Directory\n4:Delete File\n5:Exit \n");
                printf("Enter Your Choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				show_bitvector();
			        break;
			        
                        case 2:
			       create_file();
			       break;
			       
			case 3:
			       show_directory();
			       break;
			       
			case 4:
			       delete_file();
			       break;
			       
			case 5:
			       	 exit(0);
				 break;

		        default:printf("\nWrong Choice...\n");
		}
	}
}

void show_bitvector()
{
	int i;
	for(i=0;i<total_block;i++)
	{
		printf("%d\t",bitvector[i]);
	}
}

int search(char f[20])
{
	int c=1;
	struct FAT*temp;
	for(temp=head;temp!=NULL;temp=temp->next,c++)
	{
		if(strcmp(f,temp->fname)==0)
		{
			return c;
		}
	}
	return -1;
}

void create_file()
{
	struct FAT*temp,*NN;
	char f[20];
	int size,x,i,j,k,free=0;
	printf("\nEnter File Name do You Want to Create\n");
	scanf("%s",f);
	printf("\nEnter Size of File\n");
	scanf("%d",&size);

	x=search(f);
	if(x!=-1)
	{
            printf("\nFile Already Exits ..!!\n");
	    return;
	}

	for(i=0;i<total_block;i++)
	{
		free=0;
		for(j=i;j<total_block;j++)
		{
			if(bitvector[j]==1)
			{
				break;
			}
			free++;
		}

		if(free>=size)
		{
			break;
		}
	}

	if(i==total_block)
	{
		printf("\nInsufficient Memory to Add File\n");
		return;

	}

	for(k=i;k<size+i;k++)
	{
		bitvector[k]=1;
	}

	NN=(struct FAT*)malloc(sizeof(struct FAT));
	strcpy(NN->fname,f);
	NN->nob=size;
	NN->ib=i;
	NN->next=NULL;

	if(head==NULL)
	{
		head=NN;
	}

	else
	{
		for(temp=head;temp->next!=NULL;temp=temp->next);
		temp->next=NN;
		
	}
	printf("File Created Successfully !!\n");
	show_bitvector();
}

void show_directory()
{
	struct FAT*temp;
	printf("\n***************** file allocation  table *****************\n");
	printf("\n File Name \t Initial Block \t No Of Block Allocation\n");
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		if(temp==NULL)
		{
			printf("Directory is Empty..!\n");
			return;
		}
		printf("\n%s\t\t %d \t\t %d\n",temp->fname,temp->ib,temp->nob);
	}
}

void delete_file()
{
	struct FAT*temp,*prev;
	char f[20];
	printf("Enter File Name to be Deleted\n");
	scanf("%s",f);
	int x,i,size,initial;
	x=search(f);
	if(x==-1)
	{
		printf("File Not Found..!\n");
		return;
	}

	if(x==1)
	{
		size=head->nob;
		initial=head->ib;
		temp=head;
		head=head->next;
		temp->next=NULL;
		free(temp);
	}
	
	else
	{
		for(prev=head,i=1;i<x-1;i++,prev=prev->next);
		temp=prev->next;
		prev->next=temp->next;
		temp->next=NULL;
		size=temp->nob;
		initial=temp->ib;
		free(temp);
	}

	for(i=initial;i<size+initial;i++)
	{
		bitvector[i]=0;
	}
	printf("\nFile Delected Successfully..!!\n");
	show_bitvector();
}
