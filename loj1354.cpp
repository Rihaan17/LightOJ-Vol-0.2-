#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int T,deci[10],binary[10],tem,i,k,Case=1,arr[10],m,j;
    char str1[50],str2[50];

    scanf("%d",&T);

    while(T--)
    {
        scanf("\n%s\n%s",str1,str2);
        int l1=strlen(str1);
        int l2=strlen(str2);

        i=0;
        k=0;
        tem=0;
        while(i<=l1)
        {
            if(str1[i]=='.'||i==l1)
            {
                deci[k++]=tem;
                tem=0;
            }
            else
            {
                tem=(tem*10)+str1[i]-48;
            }
            i++;
        }


        i=0;
        int temp;
        for(k=0;k<4;k++)
        {
            m=0;
            temp=0;
            while(i<l2&&str2[i]!='.')
            {
                arr[m++]=(int)str2[i]-48;
                i++;
            }

            for(j=0;j<m;j++)
            {
                temp+=(arr[j]*pow(2,m-(j+1)));
            }
            binary[k]=temp;
            i++;
        }

        k=1;
        for(i=0;i<4;i++)
        {
            if(deci[i]!=binary[i])
            {
                k=0;
                break;
            }

        }

        if(k)
            printf("Case %d: Yes\n",Case++);
        else
            printf("Case %d: No\n",Case++);
    }

    return 0;
}
