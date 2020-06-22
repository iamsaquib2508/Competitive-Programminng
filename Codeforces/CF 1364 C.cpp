#include <bits/stdc++.h>
#define ll int64_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int maxx(int a, int b){
    if(a>b) return a; return b;
}

int minn(int a, int b){
    if(a<b) return a; return b;
}

int main()
{
    int n;
    while(cin >> n){
        int i, a[100005], cur, put;
        int ans[100005];
        mm(ans,-1);
        ffr(i,0,n){
            cin >> a[i];
        }
        bool ok=1;
        bool done[100055]; mm(done,0);
        cur=a[0];
        stack<int> anslast;
        ffr(i,0,n){
            if(a[i]==cur) continue;
            else{
                ans[i]=cur;
                done[cur]=1;
                anslast.push(cur);
                cur=a[i];
            }
        }
        int out=100050;
        put=a[n-1]-1;
        for(i=n-1;i>=0;i--){
            if(ans[i]==-1 ){
                if(anslast.empty()){
                    if(put==a[i]) put--;
                    while(put>=0 && done[put]) put--;
                    ans[i]=put;
                    put--;
                }
                else if( !anslast.empty() && anslast.top()==put) {
                    ans[i]=put;
                }
                else if( a[i]==put ){
                    ans[i]=out;
                }
                else {
                    ans[i]=put;
                    put--;
                }
            }
            else if(ans[i]!=-1){

                put=maxx(a[i]-1,put);
                anslast.pop();
            }
        }
        //for(int aa=0;aa<n;aa++) cout << ans[aa] << ' ';
        //cout << endl;

        for(int aa=0;aa<n;aa++) if(ans[aa]<0) { if(a[aa]==0) ans[aa]=out; else ans[aa]=0;}

        bool got[100055];
        mm(got,0);
        int mex=0;
        ffr(i,0,n){
            got[ans[i]]=1;
            while(got[mex]) mex++;
            if(mex!=a[i]) {ok=0; break;}
        }
        if(!ok) cout << "-1\n";
        else
        {
            for(int aa=0;aa<n;aa++) cout << ans[aa] << ' ';
            cout << endl;
        }
    }
}
