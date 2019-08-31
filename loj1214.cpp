using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>

int main()
{
    char num1[210];
    long long int num2;
    int i,Case=1,T;
    unsigned long long int ans;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%s%lld",num1,&num2);
        if(num2<0)
            num2=-num2;

        int l = strlen(num1);
        i=0;

        if(num1[i]=='-')
            i++;
        ans=0;
        for(;i<l;i++)
        {
            ans=((ans*10)%num2+(num1[i]-48)%num2);
            ans=ans%num2;
        }

        if(ans==0)
            printf("Case %d: divisible\n",Case++);
        else
            printf("Case %d: not divisible\n",Case++);
    }

    return 0;
}
