#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<ll,ll>
#define pb push_back
using namespace std;

int main()
{
    string s;
    int i, n, q, pos, l, r, com;
    char c;
    while(cin >> s)
    {

        cin >> q;
        set<int> mp[26];
        ffr(i,0,26) mp[i].clear();
        ffr(i,0,s.size()) mp[s[i]-'a'].insert(i);
        while(q--)
        {
            cin >> com;
            if(com==1)
            {
                cin >> pos >> c;
                pos--;
                mp[s[pos]-'a'].erase(pos);
                mp[c-'a'].insert(pos);
                s[pos]=c;
            }
            else
            {
                cin >> l >> r;
                l--; r--;
                int ans=0;
                ffr(i,0,26)
                {
                    if(!mp[i].empty())
                    {
                        set<int>::iterator it=mp[i].lower_bound(l);
                        if(it!=mp[i].end() && (*it)<=r) ans++;
                    }
                }
                cout << ans << endl;
            }
        }
    }
}
