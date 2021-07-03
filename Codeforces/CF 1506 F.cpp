#include <bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define ll long long int
#define plolo pair<ll,ll>
#define ind first
#define id second
#define mp make_pair
#define pb push_back

using namespace std;

ll maxx(ll a, ll b){
    if(a>b) return a; return b;
}

ll minn(ll a, ll b){
    if(a<b) return a; return b;
}

ll abss(ll a, ll b){
    if(a>b) return a-b;
    else return b-a;
}

ll gcd(ll a, ll b){
    if(b==0) return a; return gcd(b, a%b);
}

int main(){
    int cc=1, tt;
    cin >> tt;
    while(tt--){
        int n, i, x;
        int arr[200005];
        int mx0 = 1, mxdiff = 0;
        map<int,int> mp, mp2;
        map<int, int>::iterator it, it2;
        mp.clear();
        mp2.clear();
        cin >> n;
        ffr(i,0,n){
            cin >> arr[i];
        }
        mp[0] = 1;
        mp2[0] = 1;
        int maxlv = 0;
        ffr(i,0,n){
            cin >> x;
            int diffc = arr[i] - x;
            if(diffc > maxlv) maxlv = diffc;
            if(diffc & 1) continue;
            diffc >>= 1;

            if(mp.find(diffc) != mp.end()){
                if(arr[i] > mp[diffc]) mp[diffc] = arr[i];
                if(arr[i] < mp2[diffc]) mp2[diffc] = arr[i];
            }
            else{
                mp[diffc] = arr[i];
                mp2[diffc] = arr[i];
            }
        }
        int ans = 0;
        for(it = mp.begin(), it2 = mp2.begin(); it != mp.end(); it++, it2++ ){
            // cout << it->second << " max ... min " << it2 -> second << endl;;
            ans += it->second - it2->second;
        }

        ans += (maxlv >> 1);
        cout << ans << "\n";
    }
}