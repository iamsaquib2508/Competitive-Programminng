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
    int i, j, n;
    while(cin >> n){
        ll mul;
        ffr(i,1,n){
            cout << "0 ";
        }
        cout << "0\n";
        mul=1;
        ffr(j,1,n){
            ffr(i,1,n){
                cout << mul << ' ';
            }
            cout << "0\n";
            mul*=(n-1);
        }
    }
}
