using namespace std;

#include<iostream>
#include<cstdio>
#include<cmath>

#define N 1000010

double arr[N];

void digit()
{
    long i;
    arr[0]=log(1);
    arr[1]=log(1);

    for(i=2;i<N;i++)
    {
        arr[i]=arr[i-1]+log10(i);
    }
}

int main()
{
    digit();
    long n,t,Case=1,b;
    scanf("%ld",&t);


    while(t--)
    {
        scanf("%ld%ld",&n,&b);
        printf("Case %d: %d\n",Case++,(long)(arr[n]/log10(b))+1);
    }

    return 0;
}
