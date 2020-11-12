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

ll cnt[3002][3002];



ll qq(int pos1, int pos2, int elem){
    //both inclusive

    return cnt[pos2][elem]-cnt[pos1-1][elem];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int tt=1; cin >> tt;
    int n, id, a[3003];
    while(cin >> n){
        int i, j, k;
        id = 0;
        map<int,int> uid;
        uid.clear();

        ffrr(i,1,n){
            cin >> a[i];
            if(uid.find(a[i])==uid.end()){
                uid[a[i]]=(id++);
            }
        }

        ffr(j,0,id) cnt[0][j]=0;

        ffrr(i,1,n){
            ffr(j,0,id){
                cnt[i][j] = cnt[i-1][j];
            }
            cnt[i][uid[a[i]]]++;
        }
        ll ans=0;
        ffrr(i,1,n){
            ffrr(j,i+1,n){
                ll l = qq(1,i-1,uid[a[j]]);
                ll r = qq(j+1,n,uid[a[i]]);
                ans += l*r;
            }
        }
        cout << ans << endl;

    }
}
