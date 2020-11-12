#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define sf scanf

using namespace std;

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n, i, ans=0, a[200005], asum, rsum;
        cin >> n;
        ffrr(i,1,n){
            cin >> a[i];
        }
        bool inside=0, gotmix=0;
        ffrr(i,1,n){
            if(!inside){
                if(a[i]==i) continue;
                else{
                    inside=1;
                    asum=a[i];
                    rsum=i;
                }
            }
            else{
                asum+=a[i];
                rsum+=i;
                if(a[i]==i) gotmix=1;
                if(asum==rsum){
                    ans += (1+gotmix);
                    gotmix=0;
                    inside=0;
                }
            }
        }
        cout << ans << endl;
    }
}
