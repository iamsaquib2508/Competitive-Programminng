#include<bits/stdc++.h>
#define ffr(i,a,b) for(i=a;i<b;i++)
#define ffrr(i,a,b) for(i=a;i<=b;i++)
#define ll long long int
#define pf printf
#define mm(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define MMAX 200005

using namespace std;

int minn(int a, int b)
{
    if(a<b) return a; return b;
}

string s, s2;

bool ok(int j, int i)
{
    string t=s;
    char temp=t[i]; t[i]=t[j]; t[j]=temp;
    int mn=minn(s.size(),s2.size()), k;
    ffr(k,i+1,mn)
    {
        if(t[k]>s2[k]) return false;
        if(t[k]<s2[k]) return true;
    }
    if(t.size()==k && s2.size()>k) return true;
    //if(t<s2) return true;
    else return false;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> s >> s2;
        //sort(s.begin(),s.end());
        int i, j, mn;
        string ans;
        mn=minn(s.size(), s2.size());
        int cnt[26]={}, lim, k;
        ffr(i,0,s.size())
        {
            cnt[s[i]-'a']++;
        }
        ans=s;
        i=0;
        while(i<mn)
        {
            //if(s[i]==s2[i]) continue;

            if(s[i]<s2[i]) {ans=s; break;}
            lim=s2[i]-'a';
            cnt[lim]--;
            ffr(j,0,lim)
                if(cnt[j]>0)
                {
                    ffr(k,i+1,s.size()) if(s[k]<s[i]) {char temp=s[i]; s[i]=s[k]; s[k]=temp; ans=s; break;}
                }
            if(j<lim) break;
            cout << i << " i\n";
            if(s[i]==s2[i])
            {
                //agao
            }
            else
            {
                cnt[lim]++;
                if(cnt[lim]==0) {ans="---"; break;}
                else
                {
                    int cur=cnt[lim];
                    ffr(k,i+1,s.size())
                    {
                        if(s[k]==s2[i])
                        {
                            if(cur>1) cur--;
                            else
                            {
                                char temp=s[i]; s[i]=s[k]; s[k]=temp; cur--; break;
                            }
                        }
                    }
                    if(k==s.size())
                    {
                        // wtf
                    }
                    else
                    {
                        if(s<s2) ans=s;
                        else ans="---";
                    }
                }
                break;
            }
            i++;
        }
        if(i==mn && i==s2.size()) ans="---";
        cout << ans << endl;
    }
}
