//problem https://atcoder.jp/contests/dp/tasks/dp_f
// solution https://www.geeksforgeeks.org/printing-longest-common-subsequence/

//بسم الله الرحمن الرحيم
//اللہ کے نام سے شروع جو بڑا مہربان اور نہایت رحم والا ہے
//Allah in the name of The Most Affectionate, the Merciful
//अल्लाह के नाम से जो दयालु और कृपाशील है
#include<iostream>
#include<algorithm>
#include<climits>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<ctime>

using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define ull unsigned ll
#define pb push_back

#define endl '\n'
#define mod 1000000007

#define FOR(i,k,n) for(int i=k; i<n; i++)
#define ROF(i,k,n) for(int i=k; i>=n; i--)
#define MEMSET(t) memset(t,0,sizeof(t));
#define time clock_t tStart
#define Start clock()
#define Time printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)

string lcs(string s, string t)
{
    int nS= s.length();
    int nT= t.length();

    int dp[nS+1][nT+1];
    memset(dp,0,sizeof(dp));

    FOR(i,1,nS+1){
        FOR(j,1,nT+1){
            if(s[i-1]==t[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }
            else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }

   /// FOR(i,0,nS+1) { FOR(j,0,nT+1) cout<<dp[i][j]<<" "; cout<<endl; }
    if(dp[nS][nT]==0) return " ";

    string ans;

    int i=nS,j=nT;

  //  cout<<dp[nS][nT]<<endl; // number of lcs
    while(i>0 && j>0)
    {
        if(s[i-1]==t[j-1]){
            ans+=s[i-1];
            i--; j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]) j--;
        else i--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
//input 
// ajj aksjfjk
int main()
{
    fastio;
    int t=1; //cin>>t;
    while(t--)
    {
        string s,t;
        cin>>s>>t;
        cout<<lcs(s,t);

    }
    return 0;
}   