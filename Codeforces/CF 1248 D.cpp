#include <bits/stdc++.h>
#define ll long long int
#define ffr(i,a,b) for(i=a;i<b;i++)
#define mm(a,b) memset(a,b,sizeof(a))
using namespace std;

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int maxx(int a, int b)
{
    if(a>b) return a; return b;
}

int fixer(int i, int dod, int n)
{
    return (dod+i)%n;
}

int main()
{
    int n, i, cl, clmx, clmaxsave, left, right, dod, ans;
    string s, resp, method;
    while(cin >> n >> s)
    {
        map<int,int> mp; mp.clear();
        method="";
        if(n&1) {ans=0; left=1; right=1;}
        else if(n==2)
        {
            if(s=="))" || s=="((") ans=0;
            else ans=1;
            left=1; right=1;
        }
        else
        {
            cl=0;
            ffr(i,0,n)
            {
                if(s[i]==')') cl++;
                else cl--;
                clmx=maxx(cl,clmx);
                mp[cl]++;
            }
            if(cl!=0) {ans=0; left=1; right=1;}
            else if(clmx>1)
            {
                clmaxsave=clmx;
                //cout << clmx << endl;
                i=0;
                while(i<n)
                {
                    if(clmx==0) break;
                    if(s[i]==')') clmx--;
                    else clmx++;
                    i++;
                }
                dod=i;
                //cout << dod << " dod\n";
                ffr(i,dod,n) resp+=s[i];
                ffr(i,0,dod) resp+=s[i];
                //ans=mp[clmaxsave];
                //cout << resp << endl;
                cl=0; ans=0;
                left=-1;
                right=-1;
                ffr(i,0,n)
                {
                    if(resp[i]==')') cl++;
                    else cl--;

                    if(right<0 && cl==-2) left=maxx(left,i);
                    else if(cl==-1 && left>0 && right<0) {right=i;}
                    else if(cl==0) ans++;
                }

                left=fixer(left,dod,n)+1;
                right=fixer(right,dod,n)+1;

            }
            else if(clmx==1)
            {
                left=-1; right=-1;
                ffr(i,0,n)
                {
                    if(s[i]==')') cl++;
                    else cl--;

                    if(cl==0 && left>=0 && right <0) right=i;
                    else if(cl==1 && right<0) {left=i;}

                }
                s[left]='(';
                s[right]=')';

                //ffr(i,right,n) resp+=s[i];
                //ffr(i,0,right) resp+=s[i];
                //cout << resp << endl;
                cl=0;
                ans=0;
                ffr(i,0,n)
                {
                    if(s[i]==')') cl++;
                    else cl--;
                    if(cl==0) ans++;
                }
                left++; right++;

            }
            else
            {
                cl=0; ans=0;
                left=-1;
                right=-1;
                ffr(i,0,n)
                {
                    if(s[i]==')') cl++;
                    else cl--;

                    //if(right<0 && cl==-2) left=maxx(left,i);
                    //else if(cl==-1 && left>0 && right<0) {right=i;}
                    //else if(cl==0) ans++;

                    if(cl==-2 && s[i]=='(')
                    {
                        if(left+1>=right)
                        {
                            left=i;
                        }
                    }
                    else if(cl==-1 && s[i]==')')
                    {
                        right=i;
                    }
                    //else if(cl==0) ans++;
                }

                //if(left+1==right) ans++;
                //if(left+1<right) ans+=2;
                s[left]=')'; s[right]='(';
                left++; right++;
                cl=0;
                ffr(i,0,n)
                {
                    if(s[i]==')') cl++;
                    else cl--;
                    if(cl==0) ans++;
                }


            }

        }
        cout << ans << endl;
        cout << left << " " << right << endl;
    }
}
