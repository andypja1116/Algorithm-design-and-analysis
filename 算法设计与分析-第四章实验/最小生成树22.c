#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double INF=65535.0;
int id[25];
double cost=0.0;
struct map{
	double graph[25][25];
	int v_number;
}Map;

struct node{
	int data;
	double lowestcost;
};
struct node closedge[25];
int min()
{
	double min=INF;
	int index=-1;
	int i;
	for(i=1;i<=Map.v_number;i++)
	{
		if(closedge[i].lowestcost<min&&closedge[i].lowestcost!=0)
		{
			min=closedge[i].lowestcost;
			index=i;
		}
	}
	return index;
}

void Prim(int s)
{
	int i;
	for(i=1;i<=Map.v_number;i++)
	{
		closedge[i].lowestcost=INF;
	}
	closedge[s].lowestcost=0;
	closedge[s].data=s;
	for(i=1;i<Map.v_number;i++)
	{
		if(i!=s)
		{
			closedge[i].data=s;
			closedge[i].lowestcost=Map.graph[s][i];
		}
	}
	int e,k;
	for(e=1;e<=Map.v_number-1;e++)
	{
		k=min();
		cost=cost+Map.graph[closedge[k].data][k];
		printf("%d--%d\n",id[closedge[k].data],id[k]); 
		closedge[k].lowestcost=0;
		for(i=1;i<=Map.v_number;i++)
		{
			if(Map.graph[k][i]<closedge[i].lowestcost)
			{
				closedge[i].data=k;
				closedge[i].lowestcost=Map.graph[k][i];
			}
		}
	}
}

int main()
{
	int i,j;
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
	Prim(1);
	printf("cost=%lf",cost);
}
