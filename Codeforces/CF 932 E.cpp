#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define pb push_back
#define mm(a,b) memset(a,b,sizeof(a))
#define ll long long int
#define mp make_pair

using namespace std;

#define kk 5002
int arr[kk+2][kk+2];
ll MOD=1000000007;

ll bm(ll a, ll p)
{
    if(a==0) return 0;
    if(p==0) return 1;
    if(p==1) return a;
    ll x=bm(a,p/2);
    x=(x*x)%MOD;
    if(p&1) x=(x*a)%MOD;
    return x;
}

int main()
{
    mm(arr,0);

    int i, j;
    int N, K;

    ffrr(i,1,kk)
    {
        ffrr(j,1,i)
        {
            //cout << arr[i][j] << ' ';
        }
        //cout << endl;
    }

    ll inv2=(MOD+1)/2;
    ll mul, up, ans;
    while(cin >> N >> K)
    {
        mm(arr,0);
        arr[1][1]=1;
        if(N>=K)
        {
            ffrr(i,1,K)
            {
                ffrr(j,1,i)
                {
                    arr[i+1][j+1] += arr[i][j];   arr[i+1][j+1]%=MOD;
                    arr[i+1][j]   += arr[i][j]*j;  arr[i+1][j]%=MOD;
                }
            }

            ans=0;
            mul=1; //2^n
            up=N;
            ffrr(i,1,K)
            {
                mul*=(up);    mul%=MOD; up--;
                mul*=(inv2);  mul%=MOD;
                ans+=(arr[K][i]*mul);
                ans%=MOD;
            }
            ans*=bm(2,N);
            ans%=MOD;
            cout << ans << endl;
        }
        else
        {
            ffr(i,1,N)
            {
                ffrr(j,1,i)
                {
                    arr[i+1][j+1] += arr[i][j];   arr[i+1][j+1]%=MOD;
                    arr[i+1][j]   += arr[i][j]*j;  arr[i+1][j]%=MOD;
                }
            }
            ffrr(i,N,K)
            {
                ffr(j,1,N)
                {
                    arr[i+1][j+1] += arr[i][j];   arr[i+1][j+1]%=MOD;
                    arr[i+1][j]   += arr[i][j]*j;  arr[i+1][j]%=MOD;
                }

                arr[i+1][N]   += arr[i][N]*N;  arr[i+1][N]%=MOD;
            }

            ffrr(i,1,K)
            {
                ffrr(j,1,i)
                {
                    //cout << arr[i][j] << ' ';
                }
                //cout << endl;
            }

            ans=0;
            mul=bm(2,N); //2^n
            up=N;
            ffrr(i,1,N)
            {
                mul*=(up);    mul%=MOD; up--;
                mul*=(inv2);  mul%=MOD;
                ans+=(arr[K][i]*mul);
                ans%=MOD;
            }

            ans%=MOD;
            cout << ans << endl;
        }
    }
    return 0;
}
