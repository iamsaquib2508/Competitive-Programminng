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
    int tt;
    cin >> tt;
    int n, k;
    while(cin >> n >> k){
        if(n<k){
            cout << k-n << endl;
        }
        else if((n&1)==(k&1)){
            cout << "0\n";
        }
        else cout << "1\n";
    }
}
