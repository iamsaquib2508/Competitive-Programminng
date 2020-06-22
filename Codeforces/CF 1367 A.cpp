#include <bits/stdc++.h>
#define ull uint64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

int main()
{
    int tt; cin >> tt;
    while(tt--){
        int i;
        string s, ans;
        cin >> s;
        ans=s[0];
        ffr(i,1,s.size()-1){
            ans+=s[i];
            i++;
        }
        ans+=s[s.size()-1];
        cout << ans << endl;
    }
}
