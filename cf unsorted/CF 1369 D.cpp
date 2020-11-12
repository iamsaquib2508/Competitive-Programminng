#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

ll maxx(ll a, ll b)
{
    if(a>b) return a; return b;
}

ll minn(ll a, ll b)
{
    if(a<b) return a; return b;
}

class mat{
public:
    ll r, c;
    ll arr[5][5];
    mat(){}
    mat(ll a, ll b){
        r=a, c=b;
    }
    void print(){
        ll i, j;
        cout << "--------\n";
        ffr(i,0,r){
            ffr(j,0,c){
                cout << arr[i][j] << ' ';
            }
            cout << endl;
        }
        cout << "--------\n";
    }
};


ll mod=1000000007, inv3;

mat mul(mat a, mat b){
    mat niu(a.r, b.c);
    ll i, j, k, sum;
    ffr(i,0,a.r){
        ffr(j,0,b.c){
            sum=0;
            ffr(k,0,a.c){
                sum+=a.arr[i][k]*b.arr[k][j];
            }
            niu.arr[i][j]=sum%mod;
        }
    }
    return niu;
}


mat bm(mat a, ll p){
    mat res;
    bool done=0;
    while(1){
        if(p&1){
            if(!done) {res=a; done=1;}
            else
            {res=mul(res,a);}
        }
        p>>=1;
        if(p==0) break;
        a=mul(a,a);
    }
    return res;
}

// int main(){
// sol2
//     int tt; cin >> tt;
//     while(tt--){
//         ll n; cin >> n;
//         ll ans, poww, lv;
//         bool root;
//
//         if(n<3) ans=0;
//         else if(n<5) ans=1;
//         else if(n==5) ans=3;
//         else if(n==6) ans=6;
//         else{
//             mat t1(4,4);
//             t1.arr[0][0]=1; t1.arr[0][1]=2; t1.arr[0][2]=0; t1.arr[0][3]=0;
//             t1.arr[1][0]=1; t1.arr[1][1]=0; t1.arr[1][2]=0; t1.arr[1][3]=0;
//             t1.arr[2][0]=0; t1.arr[2][1]=1; t1.arr[2][2]=0; t1.arr[2][3]=0;
//             t1.arr[3][0]=0; t1.arr[3][1]=0; t1.arr[3][2]=0; t1.arr[3][3]=1;
//
//             mat t3(4,4);
//             t3.arr[0][0]=1; t3.arr[0][1]=2; t3.arr[0][2]=0; t3.arr[0][3]=1;
//             t3.arr[1][0]=1; t3.arr[1][1]=0; t3.arr[1][2]=0; t3.arr[1][3]=0;
//             t3.arr[2][0]=0; t3.arr[2][1]=1; t3.arr[2][2]=0; t3.arr[2][3]=0;
//             t3.arr[3][0]=0; t3.arr[3][1]=0; t3.arr[3][2]=0; t3.arr[3][3]=1;
//             t3=mul(t3,mul(t1,t1));
//
//
//             //t1.print();
//             //mat temp(4,1);
//             //temp.arr[0][0]=1; temp.arr[1][0]=0; temp.arr[2][0]=0; temp.arr[3][0]=1;
//             n-=3;
//             ll rem=n%3, times=n/3;
//             mat res;
//             if(rem==1)
//                 res=mul(t1,bm(t3,times));
//             else if(rem==2)
//                 res=mul(mul(t1,t1),bm(t3,times));
//             else
//                 res=bm(t3,times);
//
//             //res.print();
//             ans=(res.arr[0][0]+res.arr[0][3]);
//             //ans=-1;
//         }
//         cout << (ans*4)%mod << '\n';
//     }
// }

int main(){
    //sol3
    int tt; cin >> tt;
    while(tt--){
        ll n; cin >> n;
        ll ans, poww, lv;
        bool root;

        if(n<3) ans=0;
        else{
            mat t1(5,5);
            t1.arr[0][0]=1; t1.arr[0][1]=2; t1.arr[0][2]=1; t1.arr[0][3]=0; t1.arr[0][4]=0;
            t1.arr[1][0]=1; t1.arr[1][1]=0; t1.arr[1][2]=0; t1.arr[1][3]=0; t1.arr[1][4]=0;
            t1.arr[2][0]=0; t1.arr[2][1]=0; t1.arr[2][2]=0; t1.arr[2][3]=0; t1.arr[2][4]=1;
            t1.arr[3][0]=0; t1.arr[3][1]=0; t1.arr[3][2]=1; t1.arr[3][3]=0; t1.arr[3][4]=0;
            t1.arr[4][0]=0; t1.arr[4][1]=0; t1.arr[4][2]=0; t1.arr[4][3]=1; t1.arr[4][4]=0;
            mat res=bm(t1,n-2);
            ans=(res.arr[0][2]);
            //ans=-1;
        }
        cout << (ans*4)%mod << '\n';
    }
}
//Contest:
// r_n = 2*u_{n-2}+u_{n-1} + 1 // ok
// u_n = 2*r_{n-2}+r_{n-1}     // not ok. in n is unrooted, children must not be forced to be rooted.
// should be u_n = 2* max(r,u_{n-2})+ max(r,u_{n-1})

//Sol1 linear
// actually, it's f_n = 2*f_{n-2}+f_{n-1} + (can we take root)?1:0. now. we can(need) to take root at 3. Thus, cannot at 4 or 5. again can at 6. thus n%3==0.
// f_n = 2*f_{n-2}+f_{n-1} + (n%3==0)?1:0
// not even implemented.

//sol2 mat expo
// f_3n       1 2 0 1   f_{3n-1}
// f_{3n-1}   1 0 0 0   f_{3n-2}
// f_{3n-2}   0 1 0 0   f_{3n-3}
//   1        0 0 0 1      1
//               T3
//and

// f_3n+1     1 2 0 0   f_{3n}
// f_{3n}     1 0 0 0   f_{3n-1}
// f_{3n-1}   0 1 0 0   f_{3n-2}
//   1        0 0 0 1      1
//               T

//thus, for n%3==0, (T3*T*T) makes a 3 step jump. do extra 1 or 2 T in the beginning. Then multiply with [F3,F2,F1,1] = [1,0,0,1]


//sol3 mat expo with f[n-2],f[n-1],n%3==0,n%3==1,n%3==2
// f_n         1 2 1 0 0   f_{n-1} 0
// f_{n-1}     1 0 0 0 0   f_{n-2} 0
// n+1%3==0    0 0 0 0 1   n%3==0  1
//   ..        0 0 1 0 0   n%3==1  0
//   ..        0 0 0 1 0   n%3==2  0
