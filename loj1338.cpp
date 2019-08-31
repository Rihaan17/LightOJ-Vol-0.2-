using namespace std;

#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctype.h>

int main()
{
    char str1[101],str2[101];
    int T,count1[27],count2[27],Case=1,i,flag;

    scanf("%d",&T);
    getchar();
    while(T--)
    {
        memset(count1,0,sizeof(count1));
        memset(count2,0,sizeof(count2));
        gets(str1);
        gets(str2);

        int l1=strlen(str1);
        int l2=strlen(str2);

        flag=1;
        for(i=0;i<l1;i++)
        {
            if(str1[i]!=' ')
            {
                count1[tolower(str1[i])-97]++;
            }

        }

        for(i=0;i<l2;i++)
        {
            if(str2[i]!=' ')
            {
                count2[tolower(str2[i])-97]++;
            }

        }

        for(i=0;i<26;i++)
        {
            if(count1[i]!=count2[i])
            {
                flag=0;
                break;
            }
        }

        if(flag)
        {
            printf("Case %d: Yes\n",Case++);
        }
        else
        {
            printf("Case %d: No\n",Case++);
        }
    }
}
