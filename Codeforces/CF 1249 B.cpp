#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int a[200005];
int ans[200005];

int find(int cur, int root, int depth)
{
    if(cur==root) {ans[cur]=depth; return depth;}
    else {ans[cur]=find(a[cur],root, depth+1); return ans[cur];}
}

int main()
{
    int i, n, q;

    cin >> q;
    while(q--)
    {
        mm(ans,-1);
        cin >> n;
        ffrr(i,1,n)
        {
            cin >> a[i];
        }
        ffrr(i,1,n)
        {
            if(ans[i]==-1)
                find(a[i], i, 1);
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
