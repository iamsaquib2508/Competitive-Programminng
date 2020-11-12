#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mkm make_pair
#define MMAX 200005
#define bug() cout << "hello\n"

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt=1; cin >> tt;
    int n, i;
    while(cin >> n){
        string s;
        cin >> s;
        char a=s[n-1];
        ffr(i,0,n){
            cout << a;
        }
        cout << endl;
    }
}
