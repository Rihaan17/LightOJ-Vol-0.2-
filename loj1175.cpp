using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>


#define inf 3000

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

char place[210][210];
bool visited[210][201];
int row,col,cost[210][210];

bool valid(int x,int y)
{
    if(x>=0&&x<row&&y>=0&&y<col&&visited[x][y]==false&&place[x][y]!='#')
        return true;
    return false;
}

bool valid2(int x,int y,int fff)
{
    if(x>=0&&x<row&&y>=0&&y<col&&place[x][y]!='#'&&visited[x][y]==false&&cost[x][y]>fff)
        return true;
    return false;
}

struct str
{
    int x,y,cost;
}node[40010];


int main()
{
    int t,i,j,m,n,count,x1,y1,crcost,Case=1,r1,r2,flag,ans;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&row,&col);

        for(i=0;i<row;i++)
        {
            scanf("%s",place[i]);
        }
        count=0;
         str crnt,start,src;
         //cout<<"enter"<<endl;

        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                if(place[i][j]=='J')
                {
                    src.x=i;
                    src.y=j;
                }
                else if(place[i][j]=='F')
                {
                    node[count].x=i;
                    node[count].y=j;
                    count++;
                }

                cost[i][j]=inf;
            }
        }

        for(i=0;i<count;i++)
        {

            for(m=0;m<row;m++)
            {
                for(n=0;n<col;n++)
                    visited[m][n]=false;
            }
            start.x=node[i].x;
            start.y=node[i].y;
            start.cost=0;

            cost[start.x][start.y]=start.cost;

            queue<str>Q;

           // Q.empty();
            Q.push(start);

            while(!Q.empty())
            {
                //cout<<"enter"<<endl;
                crnt=Q.front();
                Q.pop();

                x1=crnt.x;
                y1=crnt.y;
                crcost=crnt.cost;
                visited[x1][y1]=true;

                for(m=0;m<4;m++)
                {
                    int r1=x1+dx[m];
                    int r2=y1+dy[m];


                    if(valid(r1,r2)&&cost[r1][r2]>start.cost)
                    {
                        start.x=r1;
                        start.y=r2;
                        start.cost=crcost+1;


                        cost[r1][r2]=start.cost;
                        Q.push(start);
                        visited[r1][r2]=true;


                    }
                }

            }

        }

        queue<str>Q;

        src.cost=0;
        Q.push(src);

        for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
                visited[i][j]=false;
        }

        flag=1;

        while((!Q.empty())&&flag)
        {
            //cout<<"enter"<<endl;
            crnt=Q.front();
            Q.pop();
            crcost=crnt.cost;
            x1=crnt.x;
            y1=crnt.y;

            if(x1==0||x1==row-1||y1==0||y1==col-1)
            {
                flag=0;
                ans=crcost+1;
            }
            visited[x1][y1]=true;

            for(i=0;i<4;i++)
            {
                r1=x1+dx[i];
                r2=y1+dy[i];

                if(valid2(r1,r2,crcost+1))
                {
                    //cout<<r1<<" "<<r2<<endl;
                    start.x=r1;
                    start.y=r2;
                    start.cost=crcost+1;

                    if((r1==0||r1==row-1)||(r2==0||r2==col-1))
                    {
                        flag=0;
                        ans=start.cost+1;
                    }
                    Q.push(start);
                    visited[r1][r2]=true;
                }
            }
        }

        if(flag)
        {
            printf("Case %d: IMPOSSIBLE\n",Case++);
        }
        else
        {
            printf("Case %d: %d\n",Case++,ans);
        }


    }

    return 0;
}


  /*for(i=0;i<row;i++)
        {
            for(j=0;j<col;j++)
                cout<<cost[i][j]<<"   ";
            cout<<endl;
        }*/
