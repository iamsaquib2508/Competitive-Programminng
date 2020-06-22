#include<iostream>
#include<cmath>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int

using namespace std;

ll solve(ll b, ll c){
    ll k = (long long int) ( (-b+sqrtl(b*b-(c<<2) ) ) /2.0 );

    if(k*k+(b+2)*k+b+c+1<=0) k++;
    else if(k*k+b*k+c<=0) k=k;
    else k--;
    return k;
}

int main(){
    ll n, n2, k, i, rem, tt; cin >> tt;
    while(cin >> n){
        if(n<10){
            ffr(i,0,n) cout << '1';
            cout << "337\n";
            continue;
        }
        k = solve(1,1-n);
        rem=n-(k*k+k+1);
        cout << rem << " m k " << k << endl;
        //if(k+k+rem+5>100000) cout << "mara\n";

        cout << "133"; ffr(i,0,rem) cout << '7';
        cout << '1'; ffr(i,0,k) cout << '3'; cout << '7';
        cout << endl;
    }
}
