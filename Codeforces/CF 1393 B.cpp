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
    while(tt--){
        int n, i, x, q, non=0;
        char cmd;
        map<int,int> a; a.clear();
        //int a[100005];
        int ss[9]={0,0,0,0,0,0,0};
        string ans;
        cin >> n;

        ffr(i,0,n){
            cin >> x;
            ss[minn(a[x],8)]--;
            a[x]++;
            ss[minn(a[x],8)]++;
        }
        cin >> q;
        while(q--){
            cin >> cmd >> x;
            if(cmd=='+'){
                ss[minn(a[x],8)]--;
                a[x]++;
                ss[minn(a[x],8)]++;
            }
            else{
                ss[minn(a[x],8)]--;
                a[x]--;
                ss[minn(a[x],8)]++;
            }
            if(ss[8]>=1) ans="YES\n";
            else if(ss[6]+ss[7]>=2) ans="YES\n";
            else if(ss[6]+ss[7]>=1){

                if(ss[2]>=1 || ss[3]>=1 || ss[4]>=1 || ss[5]>=1) ans="YES\n";
                else ans="NO\n";
            }
            else if(ss[4]+ss[5]>=2) ans="YES\n";
            else if(ss[4]+ss[5]>=1){

                if(ss[2]+ss[3]>=2) ans="YES\n";
                else ans="NO\n";
            }
            else ans="NO\n";
            cout << ans;
        }
    }
    cin >> tt;
}
