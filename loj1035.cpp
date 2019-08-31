using namespace std;

#include<iostream>
#include<cstdio>
#include<math.h>
#include<vector>

#define N 110

bool prime[110];
vector<int>primes;

void sieve()
{
        int i,j,sq=sqrt(N);
        prime[0]=prime[1]=true;

        primes.push_back(2);
        for(i=4;i<N;i+=2)
                prime[i]=true;

        for(i=3;i<sq;i+=2)
        {
                if(prime[i]==false)
                {
                        primes.push_back(i);
                        for(j=i*i;j<N;j+=2*i)
                                prime[j]=true;
                }
        }

        while(i<N)
        {
                if(prime[i]==false)
                        primes.push_back(i);
                i+=2;
        }
}

int main()
{
        sieve();
        int t,n,Case=1,ans[110],i,sz=primes.size(),temp,p;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%d",&n);

                for(i=0;i<sz&&primes[i]<=n;i++)
                {
                        temp=n; p=0;
                        while(temp)
                        {
                                p=p+temp/primes[i];
                                temp/=primes[i];
                        }

                        ans[primes[i]]=p;
                }

                printf("Case %d: %d = ",Case++,n);

                for(i=0;primes[i]<=n;i++)
                {
                        printf("%d (%d)",primes[i],ans[primes[i]]);
                        if(primes[i+1]<=n)
                                printf(" * ");
                }

                printf("\n");
        }

        return 0;
}

