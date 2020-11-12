#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int main(){
    int tt; cin >> tt;
    while(tt--){
        int n, m, i, j, temp, cnt=0, ans;
        vector<int> v[2];

        v[1].clear(); v[0].clear();

        cin >> n >> m;
        string str;
        char s[minn(n,m)][n+m-minn(n,m)];
        if(n>m){

            ffr(i,0,n){
                cin >> str;
                ffr(j,0,m){
                    s[j][i] = str[j];
                }
            }
            temp = n; n=m; m=temp;
        }
        else{
            ffr(i,0,n){
                cin >> str;
                ffr(j,0,m){
                    s[i][j] = str[j];
                }
            }
        }
        if(n>=4 && m>=4){
            ans=-1;
        }
        else if(n==1 || m==1){
            ans=0;
        }
        else{

            if(n==2){
                ffr(j,1,m){
                    if((s[0][j]+s[1][j]+s[0][j-1]+s[1][j-1])%2==1){
                        //odd
                        v[0].pb(1);
                    }
                    else{
                        v[0].pb(0);
                    }
                }
                int sz=v[0].size();
                int cnts[2]={0,0}, mod=0, last=0;
                ffr(i,0,sz){
                    if(v[0][i]==1) last++;
                    else {
                        cnts[mod]++;
                        cnts[mod]+=last;
                        last=0;
                        mod=!mod;
                    }
                }
                cnts[mod]++;
                ans = minn(cnts[0], cnts[1]);
            }
            else{
                ffr(j,1,m){
                    if((s[0][j]+s[1][j]+s[0][j-1]+s[1][j-1])%2==1){
                        //odd
                        v[0].pb(1);
                    }
                    else{
                        v[0].pb(0);
                    }

                    if((s[2][j]+s[1][j]+s[2][j-1]+s[1][j-1])%2==1){
                        //odd
                        v[1].pb(1);
                    }
                    else{
                        v[1].pb(0);
                    }
                }
                pid=-1;
                ffr(i,0,sz){
                    if(v[0][i]==1 && v[1][i]==1) last++;
                    // else if(i+1<sz && v[i+1]==0){
                    //     ans++; i++;
                    // }

                    else if(v[0][i]==0 && v[1][i]==0){
                        //fix
                        if(pid==-1 || (v[0][pid]==v[1][pid]) ){

                        }
                        else {
                            cnts[mod]++;
                        }
                        pid=i;
                        cnts[mod]++;
                        mod=!mod;
                    }
                    else{
                        //any 1
                    }
                }
            }
        }
        cout << ans << endl;
    }
    cin >> tt;
}
