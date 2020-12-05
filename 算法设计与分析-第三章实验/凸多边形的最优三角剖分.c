#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define RADIUM 6378.137
#define PI acos(-1)

struct baseData{
	int enodebid;
	double longitude,latitude;
};

int flag[30][30];
double t[30][30];
int s[30][30];
void init()
{
	int i,j;
	for(i=0;i<30;i++)
	{
		for(j=0;j<30;j++)
		{
			flag[i][j]=-1;
		}
	}
}

struct baseData point[30];

double dist(struct baseData a,struct baseData b){
	return RADIUM*acos(cos(a.latitude*PI / 180)*cos(b.latitude*PI / 180)*cos(a.longitude*PI / 180 - b.longitude*PI / 180)+sin(a.latitude*PI / 180)*sin(b.latitude*PI / 180));
}

double w(int a,int b,int c)
{
	double sum=0;
	if(flag[a][b]==-1){
		sum=sum+dist(point[a],point[b]);
	}
	if(flag[a][c]==-1){
		sum=sum+dist(point[a],point[c]);
	}
	if(flag[b][c]==-1){
		sum=sum+dist(point[b],point[c]);
	}
	return sum;
}

void minWeightTriangulation(int n){
	int i,j,r,k;
	for(i=0;i<=n;i++)
	{
		t[i][i]=0;
	}
	for(r=2;r<=n;r++)
	{
		for(i=1;i<=n-r+1;i++)
		{
			j=i+r-1;
			t[i][j]=t[i+1][j]+w(i-1,i,j);
			s[i][j]=i;
			for(k=i;k<i+r-1;k++)
			{
				double u=t[i][k]+t[k+1][j]+w(i-1,k,j);
				if(u<t[i][j])
				{
					t[i][j]=u;
					s[i][j]=k;
					/*flag[i-1][k]=1;
					flag[k][j]=1;
					flag[i-1][j]=1;*/
				} 
			}
			flag[i-1][s[i][j]]=1;
			flag[s[i][j]][j]=1;
			flag[i-1][j]=1;
		}
	}
}
int main()
{
	FILE *fp=NULL;
	fp=fopen("data5.csv","r");
	fseek(fp,0,SEEK_SET);
	int len=29;
	double x[30];
	double y[30];
	printf("点个数:%d\n",len);
	printf("各点:\n");
	int i;
	for(i=0;i<len;i++)
	{
		fscanf(fp,"%lf",&x[i]);
		fseek(fp,1L,SEEK_CUR);
		fscanf(fp,"%lf",&y[i]);
		fseek(fp,1L,SEEK_CUR);
		point[i].latitude=y[i]/100000;
		point[i].longitude=x[i]/100000;
		printf("longitude=%lf,latitude=%lf\n",point[i].longitude,point[i].latitude);
	}
	init();
	minWeightTriangulation(len-1);
	printf("%lf\n",t[1][len-1]);
 } 

