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
        int i, a[50005];
        ffr(i,0,n){
            cin >> a[i];
        }
        if(a[0]+a[1]>a[n-1]){
            cout << "-1\n";
        }
        else{
            cout << "1 2 " << n << endl;
        }
    }
}
