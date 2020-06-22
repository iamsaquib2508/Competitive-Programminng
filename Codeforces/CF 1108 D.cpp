#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)

using namespace std;

int n;
int dp[3][200005];
int arr[200005];
char soln[3][200005];

int call(int col, int pos)
{
    if(pos>n) return 0;
    if(~dp[col][pos]) return dp[col][pos];
    int ans, ch, temp, temp2;

    if(arr[pos]==col)
    {
        if(col==0)
        {
            temp=call(1,pos+1);
            temp2=call(2,pos+1);

            if(temp<temp2)
            {ans= 1+temp; ch=1;}
            else {ans=1+temp2; ch=2;}
        }
        else if(col==1)
        {

            temp=call(0,pos+1);
            temp2=call(2,pos+1);

            if(temp<temp2)
            {ans= 1+temp;ch=0;}
            else {ans=1+temp2;ch=2;}
        }
        else if(col==2)
        {
            temp=call(1,pos+1);
            temp2=call(0,pos+1);

            if(temp<temp2)
            {ans= 1+temp;ch=1;}
            else {ans=1+temp2;ch=0;}
        }
    }
    else
    {
        temp=1+call(3-col-arr[pos],pos+1);
        temp2=call(arr[pos],pos+1);

        if(temp<temp2)
        {ans= temp;ch=3-col-arr[pos];}
        else {ans=temp2;ch=arr[pos];}
    }

    soln[col][pos]=ch;
    return dp[col][pos]=ans;
}

int main()
{
    while(cin >> n)
    {
        mm(dp,-1);
        mm(soln,-1);
        //arr[0]=-1;
        char ch;
        int i, j, temp, ans=200005;
        ffrr(i,1,n)
        {
            cin >> ch;
            if(ch=='R') arr[i]=0;
            else if(ch=='G') arr[i]=1;
            else if(ch=='B') arr[i]=2;
        }
        ffr(i,0,3)
        {
            temp=call(i,1);
            if(temp<ans)
            {
                ans=temp;
                ch=i;
            }
        }
        string color="RGB";
        cout << ans << endl;
        ffrr(j,1,n)
        {
            ch= soln[ch][j];
            cout << color[ch];
        }
        cout << endl;
    }
    return 0;
}
