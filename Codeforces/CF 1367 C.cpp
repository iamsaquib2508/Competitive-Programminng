#include <bits/stdc++.h>
#define ull uint64_t
#define uint uint32_t
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define plolo pair<ull,ull>
#define xx first
#define yy second
#define mp make_pair

using namespace std;

int main()
{
    int tt; cin >> tt;
    //cout << (-1)/2 << endl;
    while(tt--){
        string s;
        int i, sz, cnt=0, ans, k;
        cin >> sz >> k;
        cin >> s;

        int fst, lst; bool fstdone=0;
        ffr(i,0,sz){
            if(s[i]=='1') {cnt++; if(!fstdone) {fstdone=1; fst=i;} lst=i; }

        }
        //cout << fst << " fst lst " << lst << endl;
        if(cnt==0){
            ans=(sz-1)/(k+1)+1;
        }
        else{
            ans=(fst)/(k+1);
            ans+=(sz-lst-1)/(k+1);
            //cout << ans << endl;
            cnt=0;
            lst++;
            ffr(i,fst+1,lst){
                if(s[i]=='1') {
                    //ans+=(cnt-1)/(k+1)+(cnt>0);
                    if(cnt>=k){
                        cnt-=k;
                        ans+=cnt/(k+1);
                    }
                    //cout << ans << endl;
                    cnt=0;
                }
                else{
                    cnt++;
                }
            }

        }
        cout << ans << endl;
    }
}
