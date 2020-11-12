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
    int tt; cin >> tt;
    while(tt--){
        int n, m, i, j, cnt=0;
        string s;
        cin >> n >> m;
        ffr(i,1,n){
            cin >> s;
            if(s[m-1]=='R') cnt++;
        }
        cin >> s;
        ffr(i,0,m-1){
            if(s[i]=='D') cnt++;
        }
        cout << cnt << endl;
    }
    cin >> tt;
}
