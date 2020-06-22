#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
using namespace std;

int main() {
    int q; int n, ans;
    cin >> q;
    while(q--)
    {
        cin >> n;
        if(n==2) ans=2;
        else ans=n&1;
        cout << ans << endl;
    }
}
