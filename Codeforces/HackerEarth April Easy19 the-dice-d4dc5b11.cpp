#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define max(q,w) (q<w)? w:q
#define min(q,w) (q>w)? w:q

using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        int i, sz=s.size(), cnt;
        if(s[sz-1]=='6')
        {
            cout << "-1\n"; continue;
        }
        ffr(i,0,sz)
        {
            if(s[i]!='6') cnt++;
        }
        cout << cnt << endl;
    }
}
