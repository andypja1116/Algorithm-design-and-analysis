#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double INF=65535.0;
int id[45];
double cost=0.0;
struct map{
	double graph[45][45];
	int v_number;
}Map;

struct node{
	int data;
	double lowestcost;
};
struct node closedge[45];
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
	id[1]=565675;
    id[2]=565621;
    id[3]=565667;
    id[4]=567510;
    id[5]=565801;
    id[6]=566010;
    id[7]=567891;
    id[8]=565492;
    id[9]=565558;
    id[10]=565627;
    id[11]=565572;
    id[12]=565610;
    id[13]=565859;
    id[14]=565630;
    id[15]=565559;
    id[16]=565845;
    id[17]=565527;
    id[18]=565633;
    id[19]=565496;
    id[20]=565865;
    id[21]=565773;
    id[22]=567531;
    id[23]=565516;
    id[24]=565393;
    id[25]=565753;
    id[26]=33566;
    id[27]=566074;
    id[28]=565648;
    id[29]=567526;
    id[30]=565551;
    id[31]=565631;
    id[32]=565608;
    id[33]=567500;
    id[34]=565531;
    id[35]=565562;
    id[36]=32788;
    id[37]=567497;
    id[38]=566316;
    id[39]=568056;
    id[40]=565964;
    id[41]=567618;
    id[42]=565898;
	double temp;
	Map.v_number=42;
	for(i=1;i<=Map.v_number;i++)
	{
		for(j=1;j<=Map.v_number;j++)
		{
			Map.graph[i][j]=INF;
		}
	}
	FILE *fp=NULL;
	fp=fopen("mat42.csv","r");
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
