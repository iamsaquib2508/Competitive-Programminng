#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define nmax 300003

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int n2, nb2, i, j, temp, x, cnt[1002]={};
        vector<int> f, t, o;
        f.clear(); t.clear(); o.clear();
        n2=n*n;
        nb2=n/2;
        ffr(i,0,n2)
        {
            cin >> x;
            cnt[x]++;
        }
        ffr(i,1,1001)
        {
            if(cnt[i]>3)
            {
                while(cnt[i]>3) {f.pb(i); cnt[i]-=4;}
            }
            if(cnt[i]>1)
            {
                while(cnt[i]>1) {t.pb(i); cnt[i]-=2;}
            }
            if(cnt[i]>0) {o.pb(i); cnt[i]--;}

        }
        int ans[n][n];
        if(f.size()*4+t.size()*2+o.size()!=n2) cout << "NO\n";
        else
        {
            if(n&1)
            {

                while(f.size()>nb2*nb2)
                {
                    temp=f.back(); f.pop_back();
                    t.pb(temp); t.pb(temp);
                }
                
                if(f.size()==nb2*nb2 && t.size()==n-1 && o.size()==1)
                {
                    cout << "YES\n";
                    ffr(i,0,nb2)
                    {
                        ffr(j,0,nb2)
                        {
                            temp=f.back(); f.pop_back();
                            ans[i][j]=temp;
                            ans[i][n-1-j]=temp;
                            ans[n-1-i][j]=temp;
                            ans[n-1-i][n-1-j]=temp;
                        }
                    }
                    ffr(j,0,nb2)
                    {
                        temp=t.back(); t.pop_back();
                        ans[i][j]=temp;
                        ans[i][n-1-j]=temp;
                    }
                    ffr(j,0,nb2)
                    {
                        temp=t.back(); t.pop_back();
                        ans[j][i]=temp;
                        ans[n-1-j][i]=temp;
                    }
                    ans[nb2][nb2]=o[0];
                    ffr(i,0,n)
                    {
                        ffr(j,0,n)
                        {
                            cout << ans[i][j] << ' ';
                        }
                        cout << '\n';
                    }
                }
                else cout << "NO\n";
            }
            else
            {
                if(f.size()==nb2*nb2)
                {
                    cout << "YES\n";
                    ffr(i,0,nb2)
                    {
                        ffr(j,0,nb2)
                        {
                            temp=f.back(); f.pop_back();
                            ans[i][j]=temp;
                            ans[i][n-1-j]=temp;
                            ans[n-1-i][j]=temp;
                            ans[n-1-i][n-1-j]=temp;
                        }
                    }
                    ffr(i,0,n)
                    {
                        ffr(j,0,n)
                        {
                            cout << ans[i][j] << ' ';
                        }
                        cout << '\n';
                    }
                }
                else cout << "NO\n";
            }
        }
    }
}
