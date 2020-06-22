#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
using namespace std;

int main() {
    int n, q, i, cur;
    string s[2];
    cin >> q;
    while(q--)
    {
        cin >> n;
        cin >> s[0];
        cin >> s[1];
        i=0;
        cur=0;
        while(i<n)
        {
            if(s[cur][i]<'3')
            {
                i++;
            }
            else
            {
                if(s[!cur][i]<'3') break;
                cur=!cur;
                i++;
            }
        }
        if(i==n && cur==1) cout << "YES\n";
        else cout << "NO\n";
    }
}
