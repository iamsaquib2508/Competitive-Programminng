#include<bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)

using namespace std;

ll mod = 1000000007;

// class mat{
// public:
//     ll r, c;
//     ll arr[2][2];
//     mat(){}
//     mat(ll a, ll b){
//         r=a, c=b;
//     }
//     void print(){
//         ll i, j;
//         cout << "--------\n";
//         ffr(i,0,r){
//             ffr(j,0,c){
//                 cout << arr[i][j] << ' ';
//             }
//             cout << endl;
//         }
//         cout << "--------\n";
//     }
// };
//
// mat mul(mat a, mat b){
//     mat niu(a.r, b.c);
//     ll i, j, k, sum;
//     ffr(i,0,a.r){
//         ffr(j,0,b.c){
//             sum=0;
//             ffr(k,0,a.c){
//                 sum+=a.arr[i][k]*b.arr[k][j];
//             }
//             niu.arr[i][j]=sum%mod;
//         }
//     }
//     return niu;
// }

ll bigMod(ll a, ll n , ll m)
{
    ll res=1, x=a;
    while(n)
    {
        if(n&1)
        {
            res *= x;
            if(res>=m) res%=m;
        }
        x *= x;
        if(x>=m) x%=m;
        n >>= 1;
    }
    return res;
}

// mat bigModMatrix(mat x, ll n)
// {
//     mat res; bool done=0;
//     while(n)
//     {
//         if(n&1)
//         {
//             if(done)
//                 res = mul(res,x);
//             else {res=x; done=1;}
//         }
//         x = mul(x,x);
//         n >>= 1;
//     }
//     return res;
// }

int main(){
	ll fxpgx, fxm2gx, qfxm2gx;
	ll inv3 = mod/3+1, fx, gx, p, N;
    ll inv11= bigMod(11,mod-2,mod);
	int T, cc=1;
	cin >> T;
	while(T--){
		cin >> N;
        p = bigMod(2,N+1,mod-1);

        fxpgx = bigMod(3,p,mod) * inv3 % mod;
        // mat base(2,2);
        // base.arr[0][0]=12; base.arr[0][1]=1;
        // base.arr[1][0]=0; base.arr[1][1]=1;
        //base = bigModMatrix(base,N);
        //qfxm2gx = ((-base.arr[0][1]+mod)*21) %mod;
        fxm2gx = 21*(mod-(bigMod(12,N,mod)-1)*inv11%mod) %mod;
        //assert(fxm2gx==qfxm2gx);

        gx = (fxpgx - fxm2gx); if(gx<0) gx+=mod;
        gx = gx*inv3%mod;

        fx = (fxpgx + fxpgx + fxm2gx); if(fx>=mod) fx-=mod;
        fx = fx*inv3%mod;

        cout << "Case " << cc++ << ": " << fx << ' ' << gx << '\n';
	}
}

// https://toph.co/p/oh-functions
// f(x) = 2 * ( f(x-1) + g(x-1) - 1 ) * ( f(x-1) + g(x-1) - 3 ) + 12 * f(x-1) - 13
// g(x) = ( f(x-1) + g(x-1) ) * ( f(x-1) + g(x-1) - 4 ) + 12 * g(x-1) + 7

// so,
// fx = 2( f[x-1]+g[x-1] )^2 + (-8) ( f[x-1]+g[x-1] ) + 12 f[x-1] - 7
//  gx = ( f[x-1]+g[x-1] )^2 + (-4) ( f[x-1]+g[x-1] ) + 12 g[x-1] + 7

// so f[x]+g[x] = 3 ( f[x-1]+g[x-1] )^2
// thus f[N]+g[N]= 3 ^ (2^N-1) . ( f[0]+g[0] (=3) ) ^ (2^N) = 3 ^ ( 2^(N+1) - 1)

//and f[x]- 2*g[x] = 12 ( f[x-1]- 2*g[x-1] ) - 21

// thus f[x]- 2*g[x]  = | 12  1 |    f[x-1]- 2*g[x-1]
//        -21         = | 0   1 |        -21
// thus f[N]- 2*g[N]  = | 12  1 |^N  f[0]- 2*g[0] = 0
//        -21         = | 0   1 |        -21
// so, f[N]-2g[N] = {matrix^N)[0][1]*(-21)
// actually, it's even simpler. f[N] - 2g[N] = 12^N*(f[0]-2g[0]) + (-21)*(1+12+12^2+...+12^(N-1)) = 0 + (-21)*(12^N-1)/11
// find fN and gN
