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
    int tt; cin >> tt;
    while(tt--){
        int n, i, x;
        bool done=0;
        cin >> n;
        n+=n;
        vector<int> odd, even; odd.clear(); even.clear();
        ffr(i,0,n){
            cin >> x;
            if(x&1){
                odd.pb(i+1);
            }
            else even.pb(i+1);
        }
        //cout << odd.size() << ' ' << even.size() << endl;
        if(odd.size()&1){
            ffr(i,1,odd.size()){
                cout << odd[i] << ' ' << odd[i+1] << endl; i++;
            }
            ffr(i,1,even.size()){
                cout << even[i] << ' ' << even[i+1] << endl; i++;
            }
        }
        else{
            int id=0;
            if(odd.size()==n){id=2;}
            ffr(i,id,odd.size()){
                cout << odd[i] << ' ' << odd[i+1] << endl; i++;
            }
            ffr(i,2,even.size()){
                cout << even[i] << ' ' << even[i+1] << endl; i++;
            }
        }
        //cout << endl;
    }
}
