#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double INF=65535.0;

struct map{
	double graph[25][25];
	int v_number;
}Map;

int path[25];
double shortest[25];
int v0=20;
//起始点=567443 
void Dijkstra()
{
	int final[25];
	int v,i;
	for(v=1;v<=Map.v_number;v++)
	{
		final[v]=0;
		path[v]=0;
		shortest[v]=Map.graph[v0][v];
	}
	final[v0]=1;
	shortest[v0]=0;
	int k=1;
	int w;
	for(i=1;i<=Map.v_number;i++)
	{
		double min=INF;
		for(w=1;w<=Map.v_number;w++)
		{
			if(!final[w])
			{
				if(shortest[w]<min)
				{
					k=w;
					min=shortest[w];
				}
			}
		}
		final[k]=1;
		for(w=1;w<=Map.v_number;w++)
		{
			if(!final[w]&&(min+Map.graph[k][w]<shortest[w]))
			{
				shortest[w]=min+Map.graph[k][w];
				path[w]=k;
			}
		}
	}
}

int main()
{
	int i,j;
	int id[25];
	id[1]=33109;
	id[2]=565696;
	id[3]=566631;
	id[4]=566720;
	id[5]=566742;
	id[6]=566747;
	id[7]=566750;
	id[8]=566751;
	id[9]=566783;
	id[10]=566798;
	id[11]=566802;
	id[12]=566967;
	id[13]=566993;
	id[14]=566999;
	id[15]=567203;
	id[16]=567238;
	id[17]=567260;
	id[18]=567322;
	id[19]=567439;
	id[20]=567443;
	id[21]=567547;
	id[22]=568098;
	double temp;
	Map.v_number=22;
	for(i=1;i<=Map.v_number;i++)
	{
		for(j=1;j<=Map.v_number;j++)
		{
			Map.graph[i][j]=INF;
		}
	}
	FILE *fp=NULL;
	fp=fopen("mat22.csv","r");
	fseek(fp,3,SEEK_SET);
	for(i=1;i<=Map.v_number;i++)
	{
		for(j=1;j<=Map.v_number;j++)
		{
			
			fscanf(fp,"%lf",&temp);
			if(temp!=-1)
			    Map.graph[i][j]=temp;
			//printf("i=%d j=%d:%lf\n",i,j,Map.graph[i][j]);
			fseek(fp,1L,SEEK_CUR);
		}
	}
	Dijkstra();
	for(i=1;i<=Map.v_number;i++)
	{
		printf("%d：源点%d到id为%d的点的最短距离为：%lf\n",i,id[v0],id[i],shortest[i]);
	}
	return 0;
}
