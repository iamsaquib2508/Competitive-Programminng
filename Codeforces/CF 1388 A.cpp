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
        int n;
        cin >> n;
        if(n>30){
            int c=14, temp = n-30;
            if(temp==6 || temp==14 || temp==10){
                temp--;
                c++;
            }
            cout << "YES\n6 10 " << c << ' ' << temp << endl;
        }
        else cout << "NO\n";
    }
    cin >> tt;
}
