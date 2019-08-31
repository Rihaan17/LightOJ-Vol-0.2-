using namespace std;

#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>

struct info
{
    int x,y;
};

queue<info>Q;

char place[501][501];
int row,col,val[501][501],dp[1001];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool validity(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col&&place[x][y]!='#'&&val[x][y]==0)
        return true;
    return false;
}


int main()
{
    int T,i,j,rx,ry,sx,sy,ans,Case=1,q,din[501][501];

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d%d%d",&row,&col,&q);

        for(i=0;i<row;i++)
        {
            scanf("%s",place[i]);
        }

        info run,temp;
        memset(dp,-1,sizeof(dp));
        memset(val,0,sizeof(val));

        printf("Case %d:\n",Case++);

        while(q--)
        {
            ans=0;


            while(!Q.empty())
                Q.pop();

            scanf("%d%d",&sx,&sy);
            sx--;
            sy--;

            int flag=1;

            if(val[sx][sy]==1)
            {
                ans=dp[din[sx][sy]];
                flag=0;
            }


            temp.x = sx;
            temp.y = sy;

            Q.push(temp);

            while(!Q.empty()&&flag)
            {
                run = Q.front();
                Q.pop();

                for(i=0;i<4;i++)
                {
                    rx = run.x+dx[i];
                    ry = run.y+dy[i];

                    if(validity(rx,ry))
                    {

                        din[rx][ry]=q;

                        temp.x=rx;
                        temp.y=ry;
                        val[rx][ry]=1;

                        if(place[rx][ry]=='C')
                        {
                           /* if(dp[rx][ry]!=-1)
                            {
                                ans=dp[rx][ry];
                                flag=0;
                                break;
                            }

                            else*/
                            ans++;
                        }


                        Q.push(temp);
                    }
                }
            }
           /* for(int s=0;s<row;s++)
                for(int t=0;t<col;t++)
                {
                    if(val[s][t]==1)
                        dp[s][t]=ans;
                }*/
            dp[q]=ans;
            printf("%d\n",ans);


        }


    }

    return 0;
}
