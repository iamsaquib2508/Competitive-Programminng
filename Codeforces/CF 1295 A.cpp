#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define PI acos(-1.0)
#define pb push_back
#define ll long long int
#define pf printf

using namespace std;



int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--)
    {
        int n; string ans="";
        cin >> n;
        if(n&1 && n>2) {ans+='7'; n-=3;}
        while(n>0)
        {
            n-=2; ans+='1';
        }
        
        cout << ans << endl;
    }

    return 0;
}
