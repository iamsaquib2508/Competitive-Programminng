#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define sf scanf

using namespace std;

ll gc(ll a, ll b, ll *x, ll *y)  
{  
    // Base Case  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    ll x1, y1;
    ll gcd = gc(b%a, a, &x1, &y1);  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
}  

int main(){
    int tt=1; 
    // cin >> tt;
    while(tt--){
        ll n, i, a[100002], x, y;
        
        cin >> n;
        if(n>1)
        {
            ll sum = 0, otsum;
            ffr(i,0,n){
                cin >> a[i];
            }
            gc(n,n-1,&x,&y);
            //cout << x << y << endl;
            cout << "1 " << n << endl;
            ffr(i,0,n){
                cout << n*x*(-a[i]) << ' ';
            }
            cout << "\n2 " << n << endl;
            ffr(i,1,n){
                cout << (n-1)*y*(-a[i]) << ' ';
            }
            cout << "\n1 1\n";
            cout << -(a[0]+(n*x*(-a[0]))) << endl;
        }
        else{
            cin >> a[0];
            cout << "1 1\n" << a[0] << "\n1 1\n" << -a[0] << "\n1 1\n" << -a[0] << endl;
        }
        //cout << ans << endl;
        
    }
}

