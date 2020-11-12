#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt=1;
    cin >> tt;
    int n;
    while(cin >> n){
        string s;
        cin >> s;
        map<ll, ll > mp; mp.clear();
        ll extra=0, c, i, ans=0, x=0;
        mp[0]=1; // //
        ffr(i,0,n){
            c = s[i]-'0';
            extra += c;
            extra--;

            ans+=mp[extra];
            mp[extra]++;
        }
        cout << ans/*+mp[0]*/ << endl;
    }
}
