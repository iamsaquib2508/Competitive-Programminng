#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ll long long int
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define sf scanf

using namespace std;

ll dp[12][2][2];
string s;
int N;

ll solve(int pos, int freee, int prev1){
    if(pos==N){
        //base case
        return 0;
    }
    ll &ret = dp[pos][freee][prev1];
    if(~ret) return ret;
    if(freee){
        ret = solve(pos+1,1,0); //put zero
        ret += prev1+solve(pos+1,1,1);
    }
    else{
        if(s[pos]=='0'){
            ret = solve(pos+1,0,0);
        }
        else{
            ret = solve(pos+1,1,0);
            ret += prev1+solve(pos+1,0,1);
        }
    }
    return ret;
}

ll all(int n){
    return (n-1)*(1<<(n-2));
}

int main(){
    int cc=1, tt, temp;
    cin >> tt;
    while(tt--){
        mm(dp,-1);
        s="";

        cin >> temp;
        while(temp){
            s+= ( (temp&1) + '0');
            temp>>=1;
        }
        reverse(s.begin(),s.end());
        s='0'+s;
        cout << s << endl;
        N=s.size();

        cout << "Case " << cc++ << ": " << solve(0,0,0) << '\n';
    }
}
