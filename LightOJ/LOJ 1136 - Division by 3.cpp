#include<bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)

using namespace std;

int f(int a){
    return a/3*2+((a%3)>1);
}

int main(){
    int cc=1, T; cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;
        cout << "Case " << cc++ << ": " << f(b)-f(a-1) << '\n';
    }
}
