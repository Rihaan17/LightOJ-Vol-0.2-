using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

#define size 100000+10

struct info{
        int div_1,div_2,div_3;
}M[5*size];

int lazy[5*size],ans;

void swap3(int &a,int &b,int &c){
    int tmp = a;
    a = c;
    c = b;
    b = tmp;
}


void built_segment_tree(int node, int u, int v)
{
        lazy[node] = 0;
        if(u==v){
                M[node].div_1=0;
                M[node].div_2=0;
                M[node].div_3=1;
        }
        else{
                int mid = (u+v)/2;
                built_segment_tree(2*node,u,mid);
                built_segment_tree(node*2+1,mid+1,v);
                M[node].div_1=0;
                M[node].div_2=0;
                M[node].div_3=M[node*2].div_3+M[node*2+1].div_3;
        }
}

void lazy_propagation(int node)
{
                for(int i=0;i<lazy[node];i++)
                {
                                int temp = M[node].div_1;
                                M[node].div_1=M[node].div_3;

                                int temp2=M[node].div_2;
                                M[node].div_2=temp;

                                M[node].div_3=temp2;
                                /*swap3(M[node*2].div_1,M[node*2].div_2,M[node*2].div_3);
                                swap3(M[1+node*2].div_1,M[1+node*2].div_2,M[1+node*2].div_3);*/
                }

                lazy[node*2] = (lazy[node*2]+lazy[node])%3;
                lazy[node*2+1] = (lazy[node*2+1]+lazy[node])%3;
                //lazy[node*2]%=3; lazy[1+node*2]%=3;

                lazy[node] = 0;
}

void update(int node, int left, int right, int u, int v)
{
        if(left>v||right<u)
                return;

        if(left>=u&&right<=v)
        {
                lazy[node]=(lazy[node]+1)%3;
                lazy_propagation(node);
                /*int temp = M[node].div_1;
                M[node].div_1=M[node].div_3;   // 1<=3

                int temp2=M[node].div_2;
                M[node].div_2=temp;   //2 <= 1

                M[node].div_3=temp2;    // 3<=2

                lazy[node*2]+=1;  lazy[node*2]%=3;
                lazy[1+node*2]+=1; lazy[1+node*2]%=3;*/

               //swap3(M[node].div_1,M[node].div_2,M[node].div_3);

        }
        else
        {
                if(lazy[node])  lazy_propagation(node);

                int mid = (left+right)/2;
                if(u<=mid)
                        update(node*2,left,mid,u,v);
                if(v>mid)
                        update(node*2+1,mid+1,right,u,v);

                M[node].div_1 = M[node*2].div_1+M[node*2+1].div_1;
                M[node].div_2 = M[node*2].div_2+M[node*2+1].div_2;
                M[node].div_3 = M[node*2].div_3+M[node*2+1].div_3;
        }
}

void query(int node, int left, int right, int u, int v)
{
        if(left>v||right<u)
                return;
        if(lazy[node])
               lazy_propagation(node);

         if(left>=u&&right<=v){
                ans+=M[node].div_3;
                return;
         }

        int mid = (left+right)/2;
        if(u<=mid)
                query(node*2, left, mid, u, v);
        if(v>mid)
                query(node*2+1,mid+1,right,u,v);
}

int main()
{
        int t,n,m,u,v,type,Case=1;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d%d",&n,&m);
                built_segment_tree(1,0,n-1);

                printf("Case %d:\n",Case++);
                while(m--)
                {
                        scanf("%d %d %d",&type,&u,&v);
                        if(type==0)
                        {
                                update(1,0,n-1,u,v);
                        }
                        else
                        {
                                ans = 0;
                                query(1,0,n-1,u,v);
                                printf("%d\n",ans);
                        }
                }
        }

        return 0;
}


/*void lazy_propagation()
{
                for(int i=0;i<lazy[node];i++)
                {
                                int temp = M[node].div_1;
                                M[node].div_1=M[node].div_3;

                                int temp2=M[node].div_2;
                                M[node].div_2=temp;

                                M[node].div_3=temp2;
                }
                if(u!=v){
                        lazy[node*2] += lazy[node];
                        lazy[1+node*2] += lazy[node];
                        lazy[node*2]%=3; lazy[1+node*2]%=3;
                }

                lazy[node] = 0;
}

void update_down(int node, int u, int v)
{
        if(u==v)
        {
                        int temp = M[node].div_1;
                        M[node].div_1=M[node].div_3;

                        int temp2=M[node].div_2;
                        M[node].div_2=temp;

                        M[node].div_3=temp2;
        }
}*/



/* int temp = M[node].div_1;
                M[node].div_1=M[node].div_3;

                int temp2=M[node].div_2;
                M[node].div_2=temp;

                M[node].div_3=temp2;
                lazy[node*2] += 1;  lazy[node*2]%=3;
                lazy[1+node*2] += 1;  lazy[1+node*2]%=3;*/

 /* M[node].div_1 = M[node*2].div_1+M[1+node*2].div_1;
                M[node].div_2 = M[node*2].div_2+M[1+node*2].div_2;
                M[node].div_3 = M[node*2].div_3+M[1+node*2].div_3;*/

