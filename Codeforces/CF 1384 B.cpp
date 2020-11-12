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

#define pii pair<int,int>

int l, k, k2;

pair< pii, pii > ff(int d){
    pii anss1, anss2;
    if(l-d>k){
        anss1=mp(0,k2-2);
        anss2=mp(k2-1,k2-1);
    }
    else{
        int four=l-d;
        anss1=mp(0,four+1);
        anss2=mp(k2-four,k2-1);
    }
    return mp(anss1,anss2);
}

bool failed;

pii ans;

void resolve(int d){
    pii p=ans;
    int l1 = p.first%k2;
    int r1 = p.second%k2;
    if(r1<l1) r1+=k2;

    pii temp = ff(d);
    int l2 = temp.first;
    int r2 = temp.second;
    if(r2<l2) r2+=k2;

    temp = mp(maxx(l1,l2),minn(r1,r2)));
    if(temp.second>temp.fisrt) failed=1;
    ans=temp;

}

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n, i, t, d[100005];
        cin >> n >> k >> l;

        failed=0;
        ffr(i,0,n){
            cin >> d[i];
            if(d[i]>l) failed=1;
        }
        k2=k+k;

        if(!failed){
            pair< pii, pii > tpp = ff(d[0]);
            ans1 = tpp.first;
            ans2 = tpp.second;
            
            t=0;
            ffr(i,1,n){
                t++;
                if(t==k2) t=0;
                tmodk2 = (t>k)?(k-(t-k)):t;
                if(d[i]+tmodk2<=l) continue;
                //
                templ=ans.first+1; tempr=l-d[i];
                pii tempans=pp(ans,templ,tempr)
            }
        }

        if(failed) cout << "No\n";
        else cout << "Yes\n";

    }
    cin >> tt;
}
