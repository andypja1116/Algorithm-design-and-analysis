#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXBIT 100
#define MAXVALUE 10000
#define MAXLEAF 30
#define MAXNODE MAXLEAF*2-1

typedef struct{
	int bit[MAXBIT];
	int start;
	int len;
}HCodeType;

typedef struct{
	int weight;
	int parent;
	int lchild;
	int rchild;
}HNodeType;

void HuffmanTree(HNodeType HuffNode[MAXNODE],int n)
{
	int i,j,m1,m2,x1,x2;
	for(i=0;i<n-1;i++)
	{
		m1=m2=MAXVALUE;
		x1=x2=0;
		for(j=0;j<n+i;j++)
		{
			if(HuffNode[j].weight<m1&&HuffNode[j].parent==-1)
			{
				m2=m1;
				x2=x1;
				m1=HuffNode[j].weight;
				x1=j;
			}
			else if(HuffNode[j].weight<m2&&HuffNode[j].parent==-1)
			{
				m2=HuffNode[j].weight;
				x2=j;
			}
		}
		HuffNode[x1].parent=n+i;
		HuffNode[x2].parent=n+i;
		HuffNode[n+i].weight=HuffNode[x1].weight+HuffNode[x2].weight;
		HuffNode[n+i].lchild=x1;
		HuffNode[n+i].rchild=x2;
	}
}

int main()
{
	FILE *fp;
	int len=27;
	int sum=0;
	int use=0;
	HNodeType HuffNode[MAXNODE];
	HCodeType HuffCode[MAXLEAF],cd;
	char ch;
	int i,j,c,p;
	for(i=0;i<2*len-1;i++)
	{
		HuffNode[i].weight=0;
		HuffNode[i].parent=-1;
		HuffNode[i].lchild=-1;
		HuffNode[i].rchild=-1;
	}
	fp=fopen("huffman.txt","r");
	do{
		fscanf(fp,"%c",&ch);
		
		if(ch>='A'&&ch<='Z')
		{
			ch=ch+32;
		}
		if(ch<='z'&&ch>='a')
		{
			HuffNode[ch-'a'].weight++;
		}
		else
		    HuffNode[26].weight++;
	}while(ch!='$');
	HuffmanTree(HuffNode,len);
	for(i=0;i<len;i++)
	{
		cd.start=len-1;
		c=i;
		p=HuffNode[c].parent;
		while(p!=-1)
		{
			if(HuffNode[p].lchild==c)
			    cd.bit[cd.start]=0;
			else
			    cd.bit[cd.start]=1;
			cd.start--;
			c=p;
			p=HuffNode[c].parent;
		}
		for(j=cd.start+1;j<len;j++)
		{
			HuffCode[i].bit[j]=cd.bit[j];
			HuffCode[i].start=cd.start;
		}
	}
	ch='a';
	for(i=0;i<len-1;i++)
	{
		printf("%c:\nÆµÂÊ:%d       ¹þ·òÂü±àÂë:",ch+i,HuffNode[i].weight);
		HuffCode[i].len=0;
		for(j=HuffCode[i].start+1;j<=len-1;j++)
		{
			printf("%d",HuffCode[i].bit[j]);
			HuffCode[i].len++;
		}
		printf("\n");
	}
	printf("%c:\nÆµÂÊ:%d       ¹þ·òÂü±àÂë:",'#',HuffNode[i].weight);
	HuffCode[i].len=0;
	for(j=HuffCode[i].start+1;j<=len-1;j++)
	{
		printf("%d",HuffCode[i].bit[j]);
		HuffCode[i].len++;
	}
	printf("\n");
	for(i=0;i<len;i++)
	{
		sum=sum+HuffCode[i].len*HuffNode[i].weight;
		use=use+HuffNode[i].weight;
	}
	printf("¹þ·òÂü±àÂëµÄ´æ´¢±ÈÌØÊý£º%d\n",sum);
	printf("¶¨³¤±àÂëµÄ´æ´¢±ÈÌØÊý£º%d\n",use*5);
	return 0;
}
