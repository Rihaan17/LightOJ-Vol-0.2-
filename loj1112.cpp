using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int M[3000000],arr[100000+10],ans;

void built_tree(int node, int u, int v)
{
        if(u==v)
        {
                M[node]=arr[u];
        }
        else
        {
                built_tree(node*2, u, (u+v)/2);
                built_tree(node*2+1,(u+v)/2+1,v);

                M[node] = M[node*2]+M[node*2+1];
        }
}

void update(int node, int left, int right, int u,int value, int check)
{
        if(u<left||right<u)
                return;



        if(u>=left&&u<=right)
        {
                if(check==1)
                {
                        M[node]-=value;
                }
                else if(check==2)
                {
                        M[node]+=value;
                }

                if(u==left&&u==right)
                        return;
                else{
                        update(node*2, left, (left+right)/2, u, value, check);
                        update(node*2+1, (left+right)/2+1, right, u, value, check);
                }
        }

       /* if(u==left&&u==right)
                ans=M[u];*/
}

int query(int node, int left, int right, int u, int v)
{
        if(left>v||right<u)
                return 0;

        if(left>=u&&right<=v)
                return M[node];
        int p1=0,p2=0;

        p1 += query(node*2, left, (left+right)/2, u, v);
        p2 += query(node*2+1, (left+right)/2+1, right, u, v);

        return p1+p2;
}

int main()
{
        int t,n,q,u,v,x,i,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&q);

                for(i=0;i<n;i++)
                        scanf("%d",&arr[i]);

                built_tree(1,0,n-1);

                printf("Case %d:\n",Case++);

                while(q--)
                {
                        scanf("%d",&x);
                        if(x==1)
                        {
                                //cout<<"enter1"<<endl;
                                scanf("%d",&u);
                                printf("%d\n",arr[u]);
                                update(1,0,n-1,u,arr[u],1);
                                //cout<<"enter2"<<endl;
                                arr[u]=0;
                        }
                        else if(x==2)
                        {
                                scanf("%d%d",&u,&v);
                                update(1,0,n-1,u,v,2);
                                arr[u]+=v;
                        }
                        else
                        {
                                scanf("%d%d",&u,&v);
                                printf("%d\n",query(1,0,n-1,u,v));
                        }
                }
        }

        return 0;
}


/*
1
5 6
3 2 1 4 5
1 4
2 3 4
3 0 3
1 2
3 0 4
1 1
*/
