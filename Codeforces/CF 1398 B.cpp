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
    string s;
    while(cin >> s){
        int cnt, i, ans=0;
        vector<int> v; v.clear();
        cnt=0;
        for(char aa:s){
            if(aa=='1') cnt++;
            else{
                if(cnt>0) v.pb(cnt);
                cnt=0;
            }
        }
        if(cnt>0) v.pb(cnt);
        sort(v.rbegin(),v.rend());
        bool alice=1;
        for(int aa:v){
            if(alice) ans+=aa;
            alice=!alice;
        }
        cout << ans << endl;
    }
}
