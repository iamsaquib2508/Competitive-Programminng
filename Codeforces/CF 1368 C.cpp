#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
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

ll maxx(ll a, ll b){
    if(a>b) return a; return b;
}

int main(){
    int n, j;
    while(cin >> n){
        cout << 3*n+4 << endl;
        cout << "0 0\n0 1\n1 0\n";
        ffr(j,1,n){
            cout << j << ' ' << j << endl;
            cout << j << ' ' << j+1 << endl;
            cout << j+1 << ' ' << j << endl;
        }
        cout << j << ' ' << j << endl;
        cout << j << ' ' << j+1 << endl;
        cout << j+1 << ' ' << j << endl;
        j++;
        cout << j << ' ' << j << endl;
    }
}
