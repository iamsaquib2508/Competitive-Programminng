#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

int main() {
    int q, a[26], i;
    cin >> q;
    string s, t;
    while(q--)
    {
        mm(a,0);
        cin >> s >> t;
        ffr(i,0,s.size())
        {
            a[s[i]-'a']=1;
        }
        ffr(i,0,s.size())
        {
            if(a[t[i]-'a']==1) break;
        }
        if(i==s.size()) cout << "NO\n";
        else cout << "YES\n";
    }
}
