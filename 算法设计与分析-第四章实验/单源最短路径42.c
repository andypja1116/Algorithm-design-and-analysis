#include<stdio.h>
#include<stdlib.h>
#include<string.h>
double INF=65535.0;

struct map{
	double graph[45][45];
	int v_number;
}Map;

int path[45];
double shortest[45];
int v0=16;
//起始点=565845 
void Dijkstra()
{
	int final[45];
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
	int id[45];
	double temp;
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
	Dijkstra();
	for(i=1;i<=Map.v_number;i++)
	{
		printf("%d：源点%d到id为%d的点的最短距离为：%lf\n",i,id[v0],id[i],shortest[i]);
	}
	return 0;
}
