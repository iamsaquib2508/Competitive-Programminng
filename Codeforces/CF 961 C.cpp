




/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */




#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define ld long double
#define pb push_back
#define pii pair<int,int>
#define plolo pair<ll,ll>
#define mm(a,b) memset(a,b,sizeof(a))
#define pf printf
#define xx first
#define yy second
#define PI acos(-1.0)
#define mp make_pair

using namespace std;



/*  ***************************           DONATE BLOOD, SAVE LIFE!               ********************************  */

int k, n;
char a[5][102][102];

bool ok(int i, int j, char want)
{
    if(i<0 || i>=n || j<0 || j>=n) return 1;
    if(a[k][i][j]==want) return 1;
    return 0;
}


int main()
{
    int i, j, ans, temp1, temp2, temp3, temp4, temp5, temp6, k1, k2;
    int cnt[2][5]; mm(cnt,0);
    char x, want;
    bool zmode;
    cin >> n;
    ffr(k,0,4)
    {
        ffr(i,0,n)
        {
            ffr(j,0,n)
            {
                cin >> a[k][i][j];
            }
        }
    }
    ffr(k,0,4)
    {
        zmode=0;
        if(a[k][0][0]=='0')
        {
            zmode=1;
        }
        
        ffr(i,0,n)
        {
            ffr(j,0,n)
            {
                x=a[k][i][j];
                if(x=='0') want='1';
                else want='0';
                if(!ok(i+1,j,want))
                {
                    a[k][i+1][j]=want; cnt[zmode][k]++;
                }
                if(!ok(i,j+1,want))
                {
                    a[k][i][j+1]=want; cnt[zmode][k]++;
                }
            }
        }
        cnt[!zmode][k]=n*n-cnt[zmode][k];
    }
    
    temp1=cnt[0][0]+cnt[0][3] + cnt[1][1]+cnt[1][2];
    temp2=cnt[0][1]+cnt[0][3] + cnt[1][0]+cnt[1][2];
    temp3=cnt[0][2]+cnt[0][3] + cnt[1][1]+cnt[1][0];
    temp4=cnt[0][0]+cnt[0][2] + cnt[1][1]+cnt[1][3];
    temp5=cnt[0][1]+cnt[0][2] + cnt[1][3]+cnt[1][0];
    temp6=cnt[0][0]+cnt[0][1] + cnt[1][3]+cnt[1][2];
    ans=min(temp1,temp2);
    ans=min(ans,temp3);
    ans=min(ans,temp4);
    ans=min(ans,temp5);
    ans=min(ans,temp6);
    cout << ans << endl;
    
    return 0;
}
