#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mkm make_pair
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
        int ans=n, x, y, i;
        cin >> x;
        ffr(i, 1, n){
            cin >> y;
            if(y!=x) ans=1;
        }
        cout << ans << endl;
    }
}
