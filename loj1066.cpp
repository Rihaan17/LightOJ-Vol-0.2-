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

char place[15][15];
int n,val[15][15];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

bool validity(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<n&&place[x][y]=='.'&&val[x][y]==0)
        return true;
    return false;
}


int main()
{
    int T,i,j,rx,ry,sx,sy,ans,Case=1,desx,desy,m,count;
    //char c[30];
    scanf("%d",&T);

    while(T--)
    {
        ans=count=0;
        scanf("%d",&n);
        //char des = 'A'+n-1;

        for(i=0;i<n;i++)
        {
            scanf("%s",place[i]);
        }

        info run,temp;

        for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(isupper(place[i][j]))
                    {
                        //c[count]=place[i][j];
                        count++;
                    }
                }
            }

        int flag=1;
        //cout<<count<<endl;


        for(m=0;m<count-1&&flag==1;m++)
        {
            while(!Q.empty())
            Q.pop();
            char rsor='A'+m;
            char rdes='A'+m+1;
            memset(val,0,sizeof(val));



            //cout<<rsor<<" "<<rdes<<endl;
            //cout<<place[0][0]<<" "<<place[1][0]<<" "<<place[2][0]<<endl;

            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(place[i][j]==rsor)
                    {
                        sx=i;
                        sy=j;
                    }
                    if(place[i][j]==rdes)
                    {
                        desx=i;
                        desy=j;
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
                        ans+=run.cost;
                        flag=1;
                        place[sx][sy]='.';
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


        if(flag)
            printf("Case %d: %d\n",Case++,ans);
        else
            printf("Case %d: Impossible\n",Case++);
    }

    return 0;
}

