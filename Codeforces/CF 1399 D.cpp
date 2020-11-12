

#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n, i, ansmax=0, cnt=0;
        vector<int> ans;
        string s;
        cin >> n;
        cin >> s;
        if(s[0]=='0') s='1'+s;
        else s='0'+s;
        ffrr(i,1,n){
            if(s[i]==s[i-1]){
                ++cnt;
            }
            else{
                cnt=1;
            }
            if(cnt>ansmax) ansmax=cnt;
            ans.pb(cnt);
        }
        cout << ansmax << endl;
        for(int aa:ans) cout << aa << ' '; cout << endl;
    }
    cin >> tt;
}
