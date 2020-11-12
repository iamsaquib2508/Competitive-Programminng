#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mkm make_pair
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

int n;
string s, st;

int dp[200005][2];

int call(int i, bool lastR){
    if(i>=n) return 0;
    if(i+1==n){
        //last
        if(lastR){
            if(s[n-1]=='R') return 200005;
            else return 0;
        }
        else{
            if(s[n-1]=='R'){

            }
        }
    }
    if(dp[i][lastR]!=-1) return dp[i][lastR];
    int ans=0;
    if(lastR){
        if(s[i]=='L' && s[i+1]=='L'){
            ans = call(i+1,0);
        }
        else if(s[i]=='L' && s[i+1]=='R'){
            ans = call(i+2,1);
        }
        else if(s[i]=='R' && s[i+1]=='R'){
            ans = minn(call(i+2,1),call(i+2,0))+1;
        }
        else if(s[i]=='R' && s[i+1]=='L'){
            ans = call(i+2,0);
        }
    }
    else{
        if(s[i]=='R' && s[i+1]=='R'){
            ans = call(i+1,1);
        }
        else if(s[i]=='R' && s[i+1]=='L'){
            ans = call(i+2,0);
        }
        else if(s[i]=='L' && s[i+1]=='L'){
            ans = minn(call(i+2,0),call(i+2,1))+1;
        }
        else if(s[i]=='L' && s[i+1]=='R'){
            ans = call(i+2,1);
        }
    }
    return dp[i][lastR] = ans;
}


int main(){
    int tt=1;
    cin >> tt;
    while(cin >> n >> s){
        int ans=0, i;
        st = s;
        char last = s[n-1];
        ffr(i,0,n){
            dp[i][0]=-1;
            dp[i][1]=-1;
        }
        dp[n][0]=-1;
        dp[n][1]=-1;
        st = s;
        int ans1, ans2, ans3, ans4;
        s[0]='R'; s[1]='R'; fin='L';
        ans1=call(2,1)+(s[0]!=st[0])+(s[1]!=st[1]);
        s[0]='R'; s[1]='L'; fin='U';
        ans2=call(2,0)+(s[0]!=st[0])+(s[1]!=st[1]);
        s[0]='L'; s[1]='L'; fin=
        ans3=call(2,0)+(s[0]!=st[0])+(s[1]!=st[1]);
        s[0]='L'; s[1]='R';
        ans4=call(2,1)+(s[0]!=st[0])+(s[1]!=st[1]);
        cout << minn(ans, call(0,last=='R')+1) << endl;
    }
}
