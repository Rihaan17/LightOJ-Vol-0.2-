using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>

int main()
{
    int T,arr[110],n,temp,count,Case=1,i,j,MIN;

    scanf("%d",&T);

    while(T--)
    {
        count=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        for(i=0;i<n-1;i++)
        {
            MIN=i;
            for(j=i;j<n;j++)
            {
                if(arr[MIN]>arr[j])
                    MIN=j;
            }
            if(MIN!=i)
            {
                temp=arr[MIN];
                arr[MIN]=arr[i];
                arr[i]=temp;
                count++;
            }
        }

        printf("Case %d: %d\n",Case++,count);
    }

    return 0;
}

/*if(arr[i]>arr[j])
                {
                    temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                    count++;
                }*/
