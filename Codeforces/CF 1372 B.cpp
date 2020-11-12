#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define sf scanf

using namespace std;

int main(){
    int tt; cin >> tt;
    while(tt--){
        int i, n;
        cin >> n;

        i=2;
        while(1){
            if(i*i>n) {i=n; break;}
            if(n%i==0) break;
            i++;
        }
        cout << n/i << ' ' << n-n/i << endl;
    }
}
