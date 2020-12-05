#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 651


int m[MAX][MAX];
void knapsack(int v[],int w[],int c,int n)
{
	n++;
	int jMax=(w[n]-1>c)?c:(w[n]-1);
	int i,j;
	for(j=0;j<=jMax;j++)
		m[n][j]=0;
	for(j=w[n-1];j<=c;j++)
	    m[n][j]=v[n];
	for(i=n-1;i>1;i--)
	{
		jMax=(w[i]-1>c)?c:(w[i]-1);
		for(j=0;j<=jMax;j++)
		    m[i][j]=m[i+1][j];
		for(j=w[i];j<=c;j++)
		    m[i][j]=(m[i+1][j]>(m[i+1][j-w[i]]+v[i]))?m[i+1][j]:(m[i+1][j-w[i]]+v[i]);
	}
	m[1][c]=m[2][c];
	if(c>=w[1])
	    m[1][c]=(m[1][c]>(m[2][c-w[1]]+v[1]))?m[1][c]:(m[2][c-w[1]]+v[1]);
}

void traceback(int w[],int c,int x[],int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		if(m[i][c]==m[i+1][c])
		    x[i]=0;
		else
		{
			x[i]=1;
			c=c-w[i];
		}
	}
	x[n] = (m[n][c]>0)?1:0;
}

int main()
{
	FILE *fp;
	fp=fopen("data6.txt","r");
	int n1=51,n2=101,i=0;
	int w1[55],w2[105],v1[55],v2[105],x1[55],x2[105];
	int c1,c2;
	fscanf(fp,"%d",&c1);
	//printf("%d\n",c1);
	//printf("\n");
	for(i=1;i<=n1;i++)
	{
		fscanf(fp,"%d",&w1[i]);
		//printf("%d\n",w1[i]);
	}
	//printf("\n");
	for(i=1;i<=n1;i++)
	{
		fscanf(fp,"%d",&v1[i]);
		//printf("%d\n",v1[i]);
	}
	//printf("\n\n");
	fscanf(fp,"%d",&c2);
	//printf("%d\n",c2);
	//printf("\n");
	for(i=1;i<=n2;i++)
	{
		fscanf(fp,"%d",&w2[i]);
		//printf("%d\n",w2[i]);
	}
	//printf("\n");
	for(i=1;i<=n2;i++)
	{
		fscanf(fp,"%d",&v2[i]);
		//printf("%d\n",v2[i]);
	}
	    
	
	knapsack(v1,w1,c1,n1);
	traceback(w1,c1,x1,n1);
	printf("The best value of the pack A is %d\n",m[1][c1]);
	printf("The items are:\n");
	int weight=0,value=0;
	for(i=1;i<=n1;i++)
	{
		if(x1[i]==1)
		{
			printf("Item:%d Weight:%d Value:%d\n",i,w1[i],v1[i]);
			weight=weight+w1[i];
			value=value+v1[i];
		}
	}
	printf("The total weight is %d ,the total value is %d\n\n",weight,value);
	//printf("%d\n",c2);
	knapsack(v2,w2,c2,n2);
	traceback(w2,c2,x2,n2);
	printf("The best value of the pack A is %d\n",m[1][c2]);
	printf("The items are:\n");
	weight=0;
	value=0;
	for(i=1;i<=n2;i++)
	{
		if(x2[i]==1)
		{
			printf("Item:%d Weight:%d Value:%d\n",i,w2[i],v2[i]);
			weight=weight+w2[i];
			value=value+v2[i];
		}
	}
	printf("The total weight is %d ,the total value is %d\n",weight,value);
	return 0;
}
