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

int main(){
    int tt; cin >> tt;
    while(tt--){
        int i, j, k, n, ans=0;
        string a, b;
        int arr[23][23];
        cin >> n;
        cin >> a >> b;

        mm(arr,0);
        ffr(i,0,n){
            if(a[i]>b[i]) break;
            if(a[i]<b[i]){
                arr[a[i]-'a'][b[i]-'a']++;
            }
        }
        if(i<n){
            ans=-1;
        }
        else{
            ffr(i,0,20){
                ffr(j,i+1,20){
                    if(arr[i][j]>0)
                    {
                        arr[i][j]=0;
                        ans++;
                        ffr(k,j+1,20){
                            arr[j][k]+=arr[i][k];
                            arr[i][k]=0;

                        }
                        break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
