#include <iostream>

const int maxn = 10050;
const int maxm = 1050;
struct node
{
    int belong;
    char wheel[maxm];
    int next;
    int where;
};
node all[maxn];
int n, m;
int Time = 0;
int CNT = 0;
int poi[17580000];// 指向和为这么多的第一个元素

int init()
{
    int x=0,f=1;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    return x*f;
}

int calc(node &a)
{
    int sum = 0;
    for(int i=0;i<m;++i)
    {
        sum += (a.wheel[i] - 97)*676 + (a.wheel[i + 1] - 97)*26 + a.wheel[i + 2] - 97;
    }
    return sum;
}




int Index (char T[],char S[],int tlength,int slength,int pos)
{
    int j=0,i=pos;
    while(i<tlength&&j<slength)
    {
        if(T[i % m]==S[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    return j==slength?i-slength:-1;
    
}


void lookup(node &a)
{
    const int sum = calc(a);
    int temp = poi[sum];
    if(!temp)
    {
        printf("0\n");
        a.belong = Time;
        poi[sum] = a.where;
        return;
    }
    while(true)
    {
        if(Index(all[temp].wheel, a.wheel, 2*m, m, 0) != -1)
        {
            printf("%d\n",all[temp].belong);
            break;
        }
        if(!all[temp].next)
        {
            printf("0\n");
            a.belong = Time;
            all[temp].next = a.where;
            break;
        }
        temp = all[temp].next;
    }
}

int main()
{
    m = init();
    n = init();
    int j = 0;
    for(Time = 1;Time <= n;++Time)
    {
        ++CNT;
        while(j<m)
        {
            all[CNT].wheel[j] = getchar();
            ++j;
        }
        all[CNT].wheel[m] = all[CNT].wheel[0];
        all[CNT].wheel[m + 1] = all[CNT].wheel[1 % m];
        j = 0;
        getchar();
        all[CNT].where = CNT;
        lookup(all[CNT]);
    }
}
