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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int cc=1, tt;
    cin >> tt;
    while(tt--){
        int i, x, n, k, last;
        
        string s, t, start;
        cin >> n >> k;
        last = k-n+k;
        ffr(i,1,last){
            cout << i << ' ';
        }
        for(i=k;i>=last;i--){
            cout << i << ' ';
        }
        cout << endl;
    }
}