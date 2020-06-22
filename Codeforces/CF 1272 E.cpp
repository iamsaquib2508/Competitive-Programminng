#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int ans[MMAX], a[MMAX], n;
bool vis[MMAX];

inline int minn(int a, int b)
{if(a<b) return a; return b;}

int solve(int i)
{
    if(ans[i]>0 || ans[i]==MMAX) return ans[i];
    if(vis[i]) return MMAX;
    //cout << i << " i\n";
    int tmp=MMAX;
    vis[i]=1;
    if(i-a[i]>=0)
    {
        if( (a[i-a[i]]^a[i])&1 ) tmp=1;
        else tmp=minn(tmp,1+solve(i-a[i]));
    }
    //ans[i]=tmp;
    if(tmp>1 && i+a[i]<n)
    {
        if( (a[i+a[i]]^a[i])&1 ) tmp=1;
        else tmp=minn(tmp,1+solve(i+a[i]));
    }

    //if(i==84-8 || i==84-8-8 || i==84 || i==84+8)
    //cout << tmp << " tmp i " << i << endl;
    return ans[i]=tmp;
}

int main()
{
    int i;
    while(cin >> n)
    {
        ffr(i,0,n)
        {
            cin >> a[i];
            ans[i]=-1;
            vis[i]=0;
        }
        ffr(i,0,n) solve(i);
        ffr(i,0,n)
        {
            if(ans[i]>=MMAX) ans[i]=-1;
            cout << ans[i] << ' ';
        }

        cout << '\n';
    }
}
