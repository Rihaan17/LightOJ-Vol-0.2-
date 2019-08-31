using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>

int main()
{
    int T,n,p,q,count,Case=1,i,arr[32];

    scanf("%d",&T);

    while(T--)
    {
        count=0;
        scanf("%d%d%d",&n,&p,&q);

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        if(q-arr[count]>=0&&p-1>=0&&count+1<=n)
        {
            q-=arr[count];
            p--;
            count++;
        }

        while(q>0&&p>0&&count<n)
        {
            q-=arr[count];
            p--;
            if(q>=0&&p>=0&&n>=count+1)
                count++;
        }

        printf("Case %d: %d\n",Case++,count);
    }

    return 0;
}
