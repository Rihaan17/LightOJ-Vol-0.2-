using namespace std;

#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<ctype.h>

struct info
{
    int x,y,cost;
};

queue<info>Q;

char place[22][22];
int row,col,val[22][22];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool validity(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col&&place[x][y]!='#'&&place[x][y]!='m'&&val[x][y]==0)
        return true;
    return false;
}

int maximum(int a,int b,int c)
{
    if(a>=b&&a>=c)
        return a;
    else if(b>=a&&b>=c)
        return b;
    return c;
}


int main()
{
    int T,i,j,rx,ry,sx,sy,ans,Case=1,desx,desy,m,anss[3],flag;
    scanf("%d",&T);

    while(T--)
    {
        ans=0;
        scanf("%d%d",&row,&col);
        for(i=0;i<row;i++)
        {
            scanf("%s",place[i]);
        }

        info run,temp;

        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(place[i][j]=='h')
                {
                    desx=i;
                    desy=j;
                }
            }
        }

        for(m=0;m<3;m++)
        {
            while(!Q.empty())
            Q.pop();
            char rsor='a'+m;
            memset(val,0,sizeof(val));


            for(i=0;i<row;i++)
            {
                for(j=0;j<col;j++)
                {
                    if(place[i][j]==rsor)
                    {
                        sx=i;
                        sy=j;
                    }
                }
            }


            temp.x = sx;
            temp.y = sy;
            temp.cost=1;

            Q.push(temp);
            flag=0;

            while(!Q.empty()&&flag==0)
            {
                run = Q.front();
                Q.pop();

                for(i=0;i<4;i++)
                {
                    rx = run.x+dx[i];
                    ry = run.y+dy[i];



                    if(rx==desx&&ry==desy)
                    {
                        anss[m]=run.cost;
                        flag=1;
                        break;
                    }

                    if(validity(rx,ry))
                    {
                        temp.x=rx;
                        temp.y=ry;
                        val[rx][ry]=1;

                        temp.cost=run.cost+1;

                        Q.push(temp);
                    }
                }
            }
        }

        ans=maximum(anss[0],anss[1],anss[2]);
        printf("Case %d: %d\n",Case++,ans);

    }

    return 0;
}


