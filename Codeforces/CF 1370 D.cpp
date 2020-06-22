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

class my{
public:
    int val, id;
    my(){}
    my(int aa, int bb){
        val=aa, id=bb;
    }
};

bool cmp(my p, my q){
    if(p.val!=q.val) return p.val<q.val;
    return p.id<q.id;
}

int main(){
    int n, k;
    while(cin >> n >> k){
        int i, x, ans, temp, rem;
        vector< my > v; v.clear();
        bool done[200005]; mm(done,0);
        ffr(i,0,n){
            cin >> x;
            v.pb(my(x,i+1));
        }
        //cout << v[0].second << endl;
        sort(v.begin(),v.end(),cmp);
        for(auto aa: v) cout << aa.id << endl;
        done[0]=0;
        done[n+1]=0;
        if(k&1){
            ans=0;
            vector< my >::iterator it=v.begin();
            rem=k/2;
            while(rem>0){
                temp=it->id;
                //cout << i << " hello\n";
                if(!done[temp+1] && !done[temp-1]){
                    done[temp]=1;
                    ans=maxx(ans,it->val);
                    rem--;
                    //cout << ans << " in\n";
                }
                it++;
            }
            cout << ans << " init\n";
            if(done[1]==1 && done[n]==1){
                while(done[it->id+1] || done[it->id-1]) it++;
                ans=maxx(ans,it->val);

            }
            else if(done[1]==1 || done[n]==1){
                done[1]=0; done[n]=0;
                while(done[it->id+1] || done[it->id-1] || it->id==1 || it->id==n ) it++;
                ans=maxx(ans,it->val);

            }
            cout << ans << endl;
        }
        else{
            ans=0;
            vector< my >::iterator it=v.begin();
            rem=k/2;
            while(rem>0){
                temp=it->id;
                //cout << i << " hello\n";
                if(!done[temp+1] && !done[temp-1]){
                    done[temp]=1;
                    ans=maxx(ans,it->val);
                    rem--;
                }
                it++;
            }
            if(done[1]==1 && done[n]==1){
                done[1]=0; done[n]=0;
                while(done[it->id+1] || done[it->id-1]) it++;
                ans=maxx(ans,it->val);

            }
            cout << ans << endl;
        }

    }
}
