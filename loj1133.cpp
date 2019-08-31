using namespace std;

#include<iostream>
#include<cstdio>

int arr[110],n,i,x,y;

void multiply()
{
    scanf("%d",&x);
    //getchar();
    for(i=0;i<n;i++)
        arr[i]*=x;
}

void divide()
{
    scanf("%d",&x);
    //getchar();
    for(i=0;i<n;i++)
        arr[i]/=x;
}

void sum()
{
    scanf("%d",&x);
    //getchar();
    for(i=0;i<n;i++)
        arr[i]+=x;
}

void swap()
{
    scanf("%d%d",&x,&y);
   // getchar();
    int temp=arr[x];
    arr[x]=arr[y];
    arr[y]=temp;
}

void reverse()
{
    int temp,k=n-1;
    for(i=0;i<n/2;i++)
    {
        temp=arr[i];
        arr[i]=arr[k];
        arr[k]=temp;
        k--;
    }
}

int main()
{
    int T,Case=1,m;
    char c;
    scanf("%d",&T);
    //getchar();

    while(T--)
    {
        scanf("%d%d",&n,&m);
        //getchar();
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
            //getchar();
        }



        while(m--)
        {
            scanf(" %c",&c);
           // getchar();

            if(c=='S')
                sum();
            else if(c=='D')
                divide();
            else if(c=='M')
                multiply();
            else if(c=='R')
                reverse();
            else if(c=='P')
                swap();
        }
        printf("Case %d:\n",Case++);

        for(i=0;i<n;i++)
        {
            printf("%d",arr[i]);

            if(i+1<n)
                printf(" ");
        }

        printf("\n");
    }

    return 0;
}
