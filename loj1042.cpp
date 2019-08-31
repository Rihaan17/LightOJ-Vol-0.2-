using namespace std;

#include<iostream>
#include<cmath>
#include<cstdio>

int main()
{
    long long int num,arr[500],Case=1,T,temp,flag,k,i,temp2;

    cin>>T;
    while(T--)
    {
        scanf("%lld",&num);
        temp=num;
        k=flag=0;
        int sss=-1,ttt=-1;
        while(temp)
        {
            arr[k]=temp%2;
            if(sss!=-1&&arr[k]==1)
            {
                xd=temp/2;
                if(xd)
                    ttt=k;
            }
            if(arr[k]==0)
                sss=k;
            k++;
            temp/=2;
        }

        if(ttt==-1&&sss==-1)
        {
            num=num-pow(2,k-1)+pow(2,k);
        }
        else if(ttt==-1)
        {

        }

        /*if(ttt>sss)
        {
            num=num+pow(2,ttt)-pow(2,sss);
        }
        else if(arr[k-1]==1&&arr[k-2]==0)
        {
            num=pow(2,k);
        }
        else
        {
            num=num+pow(2,k)-pow(2,k-1);
        }*/


        printf("Case %lld: %lld\n",Case++,num);

    }

    return 0;
}
