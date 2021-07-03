#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair
#define ll long long int
#define pb push_back
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}


bool ok(string s, string a){
    int slen = s.size();
    int alen = a.size();
    if (slen%alen>0) return false;
    int times = slen/alen, i;
    string test="";
    ffr(i,0,times){test += a;}
    return test == s;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int cc=1, tt;
    cin >> tt;
    while(tt--){
        int i, x, n, aa, d, bb, j;
        
        string s, t, start;
        cin >> s >> t;
        int lc, sz = s.size(), a, b;
        // start = "";
        for(i=sz;i>0;i--){
            start = "";
            ffr(j,0,i)
                start += s[j];
            if(ok(s, start) && ok(t, start)) {
                a = s.size()/start.size();
                b = t.size()/start.size();
                lc = a*b/gcd(a,b);
                ffr(j,0,lc)
                    cout << start;
                cout << "\n";
                break;
            }
        }
        if(i==0) cout << "-1\n";
    }
}