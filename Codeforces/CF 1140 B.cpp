#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        while(n--)
        {
            int sz, i; string s;
            cin >> sz;
            cin >> s;
            if(sz==1)
            {
                cout << "0\n";
                continue;
            }
            int ans=0;
            ffr(i,0,sz)
            {
                if(s[i]=='<') ans++;
                else break;
            }
            int ans2=0;
            for(i=sz-1;i>=0;i--)
            {
                if(s[i]=='>') ans2++;
                else break;
            }
            cout << min(ans,ans2) << endl;
        }
    }
}
