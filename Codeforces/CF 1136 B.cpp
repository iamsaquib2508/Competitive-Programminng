#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int

using namespace std;

int main()
{
    int n, k, ans;
    while(cin >> n >> k)
    {
        ans=min(n-k,k-1);
        ans=n+n+n+ans;
        cout << ans << endl;
    }
}
