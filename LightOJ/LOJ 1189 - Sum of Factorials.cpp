#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define bug cout << "hello\n"
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

int maxx(int a, int b){
    if(a>b) return a; return b;
}

vector<int> ans;

string getcar(int a){
    string b="";
    if(a<10) return (b+(char)('0'+a));
    return (b+(char)('0'+a/10)+(char)('0'+a%10));
}

bool doit(ll n){
    if(n==0) return true;
    int cur=3;
    n>>=1;
    bool once=0;
    while(1){
        if(n<1) break;
        if(n%cur==0){
            n/=cur;
            cur++;
            once=0;
        }
        else{
            if(once) return false;
            ans.pb(cur-1);
            n--;
            once=1;
        }
    }
    return (n==0);
    //return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int cc=1, tt; cin >> tt;
    while(tt--){

        ll n; bool result;
        cin >> n;
        int i;
        if(n&1){
            //easier
            ans.pb(1);
            result=doit(n-1);
        }
        else{
            ans.pb(0); ans.pb(1);
            result=doit(n-2);
            if(!result){
                ans.clear();
                result=doit(n);
            }
        }
        string print;
        if(!result){
            print="impossible";
        }
        else{
            print=(getcar(ans[0])+'!');
            ffr(i,1,ans.size()){
                print+=('+'+getcar(ans[i])+'!');
            }
        }
        cout << "Case " << cc++ << ": " << print <<'\n';
        ans.clear();
    }
}
