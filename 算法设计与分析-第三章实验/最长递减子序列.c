#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c[1000][1000];
int b[1000][1000];
int a[1000];
int d[1000];
void sort(int length)
{
	int i,j;
	int temp;
	for(i=0;i<length-1;i++)
	{
		for(j=i+1;j<length;j++)
		{
			if(a[i]<a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}

void LCSLength(int m,int n)
{
	int i,j;
	for(i=1;i<=m;i++) c[i][0]=0;
	for(i=1;i<=n;i++) c[0][i]=0;
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(a[i]==d[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
	}
}
void LCS(int i,int j)
{
	if(i==0||j==0)
	    return;
	if(b[i][j]==1)
	{
		LCS(i-1,j-1);
		printf("%d ",a[i]);
	}
	else if(b[i][j]==2)
	{
		LCS(i-1,j);
	}
	else
	{
		LCS(i,j-1);
	}
}
void init()
{
	int i,j;
	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			c[i][j]=-1;
			b[i][j]=-1;
		}
	}
}
int main()
{
	FILE *fp;
	fp=fopen("data3.txt","r");
	int i=0;
	int count=0; 
	int number;
	do{
		fscanf(fp,"%d",&number);
		if(number==-51)
		    break;
		a[i]=number;
		d[i]=number;
		i++;
		count++;
	}while(1);
	sort(count);
	/*for(i=0;i<count;i++)
	{
		printf("%d ",d[i]);
	}*/
	init();
	LCSLength(count-2,count-2);
	LCS(count-2,count-2);
} 
