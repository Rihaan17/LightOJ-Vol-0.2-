using namespace std;

#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>

#define N 1000000+10
#define mod 1000003

long long int fac[N];
//int mod_inv[mod];

void factorial()
{
        fac[0] = 1;
        for(long long int i=1;i<N;i++){
                fac[i]=((i%mod)*(fac[i-1]%mod))%mod;
                //mod_inv[i] = -1;
        }
}

long long pow(long long a, long long b, long long MOD) {

            long long x = 1, y = a;
            while(b > 0) {
                if(b%2 == 1) {
                    x=(x*y);
                    if(x>MOD) x%=MOD;
                }
                y = (y*y);
                if(y>MOD) y%=MOD;
                b /= 2;
            }
            return x;
}

long long modInverse(long long a, long long m) {
    return pow(a,m-2,m);
}

int main()
{
        factorial();
        //modula_inverse();
        int t,Case=1; long long int n,k,i;
        unsigned long long int temp;
        scanf("%d",&t);

        while(t--)
        {
                scanf("%lld%lld",&n,&k);

                temp = ((fac[n-k]%mod)*(fac[k]%mod))%mod;

                temp = modInverse(temp,mod);

                printf("Case %d: %lld\n",Case++,((fac[n]%mod)*(temp%mod))%mod);
        }

        return 0;
}


/*
int modula_inverse(int a, int b)
{
            int x = 1, y = 0;
            int xLast = 0, yLast = 1;
            int q, r, m, n;
            while(a != 0) {
                q = b / a;
                r = b % a;
                m = xLast - q * x;
                n = yLast - q * y;
                xLast = x, yLast = y;
                x = m; y = n;
                b = a; a = r;
            }

            return x;
}

*/
