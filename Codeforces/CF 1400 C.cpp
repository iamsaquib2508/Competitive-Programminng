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
    int x; string s;
    while(cin >> s){
        cin >> x;
        int n=s.size(), i;
        bool oneable[n+5];
        mm(oneable,0);
        string w="";
        ffr(i,0,n) w+='1';
        ffr(i,0,n){
            if(s[i]=='0'){
                if(i+x<n)
                    w[i+x]='0';
                if(i-x>=0)
                    w[i-x]='0';
            }
        }
        ffr(i,0,n){
            if(s[i]=='1'){
                if( (i<x || (i>=x && w[i-x]=='0')) && (i+x>=n || (i+x<n && w[i+x]=='0')) ) break;
            }
        }
        if(i<n) w="-1";
        cout << w << endl;
    }
}
