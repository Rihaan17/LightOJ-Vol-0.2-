using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

int arr[1010],mn[1010];

int divisor(int n)
{
    int i,sqr=sqrt(n),count=0;

    for(i=1;i<=sqr;i++)
    {
        if(n%i==0)
        {
            count+=2;
        }
    }

    if((sqr*sqr)==n)
        count--;

    return count;
}

bool cmp(int a,int b)
{
    if(arr[a]<arr[b])
        return true;
    if(arr[a]==arr[b])
    {
        if(a>b)
            return true;
        else
            return false;
    }
    return false;
}

int main()
{
    int t,i,Case=1,n;
    scanf("%d",&t);

    for(i=1;i<=1002;i++)
    {
        arr[i]=divisor(i);
        mn[i]=i;
    }

    sort(mn+1,mn+1001,cmp);

    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",Case++,mn[n]);
    }

    return 0;
}
