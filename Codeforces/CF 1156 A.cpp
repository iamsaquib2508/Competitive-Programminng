#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mp(a,b) make_pair(a,b)
#define mmxx 1000000

using namespace std;

int main()
{
    int n, i, prev, cur, ans;
    while(cin >> n)
    {
        ans=0;
        cin >> prev;
        bool fail=0;
        ffr(i,1,n)
        {
            cin >> cur;
            if(cur==prev) fail=1;
            if(cur+prev==5) fail=1;
            ans+=(cur+prev);
            prev=cur;
        }
        if(fail) cout << "Infinite\n";
        else
        {
            cout << "Finite\n";
            cout << ans << endl;
        }
    }
}
