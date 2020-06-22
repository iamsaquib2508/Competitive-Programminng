#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define bug cout << "hello\n"
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

int maxx(int a, int b){
    if(a>b) return a; return b;
}

int main(){
    int n;
    while(cin >> n){
        string s, t;
        int i, z=0, o, ans;
        cin >> s >> t;
        for(char aa:s) if(aa=='0') z++;
        for(char aa:t) if(aa=='0') z--;
        //cout << z << endl;
        if(z!=0) cout << "-1\n";
        else{
            o=0;
            ans=0;
            ffr(i,0,n){
                if(s[i]!=t[i])
                {
                    if(s[i]=='0'){
                        if(o>0) o--;
                        z++;
                    }
                    else{
                        if(z>0) z--;
                        o++;
                    }
                    ans=maxx(ans,maxx(o,z));
                }
            }
            //cout << o << " o z " << z << endl;
            cout << ans << endl;
        }

    }
}
