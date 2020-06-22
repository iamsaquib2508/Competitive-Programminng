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

int main()
{
    int i, n;
    char prev, cur;
    while(cin >> n)
    {
        string s;
        cin >> s;
        prev=0;
        ffr(i,0,n)
        {
            cur=s[i];
            if(cur<prev)
            {
                cout << "YES\n"; cout << i << ' ' << i+1 << endl;
                break;
            }
            prev=cur;
        }
        if(i==n) cout << "NO\n";
    }
}
