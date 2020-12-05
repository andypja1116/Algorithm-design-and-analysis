#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c[10000][10000];
int b[10000][10000];

void init()
{
	int i,j;
	for(i=0;i<10000;i++)
	{
		for(j=0;j<10000;j++)
		{
			c[i][j]=-1;
			b[i][j]=-1;
		}
	}
}
void LCSLength(int m,int n,char *x,char *y)
{
	int i,j;
	for(i=1;i<=m;i++) c[i][0]=0;
	for(i=1;i<=n;i++) c[0][i]=0;
	
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==y[j])
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
void LCS(int i,int j,char *x)
{
	if(i==0||j==0)
	    return;
	if(b[i][j]==1)
	{
		LCS(i-1,j-1,x);
		printf("%c",x[i]);
	}
	else if(b[i][j]==2)
	{
		LCS(i-1,j,x);
	}
	else
	{
		LCS(i,j-1,x);
	}
}
int main()
{
	FILE *fp;
	fp=fopen("data1.txt","r");
	int i=0;
	int count=-1;
	char A[10000];
	char B[10000];
	char C[10000];
	char D[10000];
	char a[10000];
	char c;
	do{
		fscanf(fp,"%c",&c);
		if(c==' ')
		    break;
		if(c=='\n'||c=='A'||c=='B'||c=='C'||c=='D')
		    continue;
		if(c==':')
		{
			count++;
			i=0;
			continue;
		}
		if(count==0)
		{
			A[i]=c;
			i++;
		}
		else if(count==1)
		{
			B[i]=c;
			i++;
		}
		else if(count==2)
		{
			C[i]=c;
			i++;
		}
		else if(count==3)
		{
			D[i]=c;
			i++;
		}
	}while(1);
	init();
	LCSLength(strlen(C),strlen(B),C,B);
	LCS(strlen(C),strlen(B),C); 
 } 
