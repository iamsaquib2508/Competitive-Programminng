#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair
#define lllast 29

using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int minn(int a, int b){if(a<b) return a; return b;}

int a[100005], n;
bool ans[32];

int func(int bit=lllast, int st=0, int end=n)
{
    if(bit<0) return 0;
    if(st==end) return 0;
    int i;
    sort(a+st,a+end);
    ffr(i,st,end)
    {
        if( (a[i]&(1<<bit)) > 0 ) break;
    }


    if( i==st || i==end )
        return func(bit-1,st,end);
    else
        return minn(func(bit-1,st,i), func(bit-1,i,end))+(1<<bit);
}

int main()
{

    while(cin >> n)
    {
        int i;
        //mm(ans,1);
        ffr(i,0,n) cin >> a[i];
        // func();
        // int ret=0, cur=1;
        // ffrr(i,0,lllast)
        // {
        //     if(ans[i]) ret+=cur;
        //     cur+=cur;
        // }
        cout << func() << endl;
    }
}
