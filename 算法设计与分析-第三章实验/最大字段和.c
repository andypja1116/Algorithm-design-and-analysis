#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int pos;
int MaxSum(int n,int *a)
{
	int sum=0;
	int b=0;
	int i;
	for(i=1;i<=n;i++)
	{
		if(b>0)
		    b=b+a[i];
		else
		    b=a[i];
		if(b>sum)
		{
			sum=b;
			pos=i;
		}
	}
	return sum;
 } 
int main()
{
	FILE *fp;
	fp=fopen("data3.txt","r");
	int i=0;
	int sum=0; 
	int use;
	int count=0; 
	int a[1000];
	int number;
	do{
		fscanf(fp,"%d",&number);
		if(number==-51)
		    break;
		i++;
		a[i]=number;
		count++;
	}while(1);
	sum=MaxSum(count,a);
	use=sum;
	i=pos;
	while(use!=0)
	{
		use=use-a[i];
		i--;
	}
	i++;
	printf("最大子段区间：%d-%d\n",i,pos);
	printf("最大子段和：%d",sum);
	return 0;
}
