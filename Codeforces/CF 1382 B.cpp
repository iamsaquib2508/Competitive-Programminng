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
    int tt; cin >> tt;
    while(tt--){
        int n, x, one=0, i;
        cin >> n;
        int init=0;
        ffr(i,0,n){
            cin >> x;
            if(x==1) init^=1;
            else {one=1; break;}
        }
        ffr(i,i+1,n)
            cin >> x;

        if(init==1 && one==1){
            cout << "Second\n";
        }
        else if(init==1){
            cout << "First\n";
        }
        else if(one==1){
            cout << "First\n";
        }
        else cout << "Second\n";
    }
}
