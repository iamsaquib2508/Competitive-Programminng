#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define mmxx 1e18

using namespace std;

class node
{
public:
    ll a, b;
    node(){}
    node(int aa, int bb)
    {
        a=aa; b=bb;
    }
};

bool cmp(node x, node y)
{
    ll temp=x.a-x.b+y.b-y.a;
    return (temp>0) ;
}

int main()
{
    ll n, i, aa, bb;
    node arr[100005];
    while (cin >> n) {
        ffr(i,0,n)
        {
            cin >> aa >> bb;
            arr[i]=node(aa,bb);
        }
        sort(arr,arr+n,cmp);
        ll ans=0;
        ffr(i,0,n)
        {
            ans+=(arr[i].a*i+arr[i].b*(n-1-i));
        }
        cout << ans << endl;
    }
}
