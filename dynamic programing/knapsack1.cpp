//https://atcoder.jp/contests/dp/tasks/dp_d

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

//method1
//memoization
ll dp[1000][100001];
ll maxVal(int w[], ll v[], int n, int W)
{
  //  cout<<wtSum<<" "<<n<<endl;
    if(n==0 || W==0) return 0;
    //if(W<0) return INT_MIN;
    if(dp[n][W]!=-1) return dp[n][W];

    
    //if( W > wtSum+w[n-1]); 
    if(W-w[n-1]>=0)
    return dp[n][W]=max( maxVal(w,v,n-1,W), v[n-1]+maxVal(w,v,n-1,W-w[n-1]) ); 
    else return dp[n][W]= maxVal(w,v,n-1,W);

}

//method 2
//table
// ll dptable(int w[], ll v[], int n, int W, int S)
// {
//     ll dp[n+1][W+1];

//     memset(dp,0,sizeof(dp));

//     FOR(i,1,n+1){
//         FOR(j,1,W+1){
//             if(w[i-1]<=j) {
//                 dp[i][j] = max( dp[i-1][j], v[i-1]+dp[i-1][j-w[i-1]] );  
//             } 
//             else dp[i][j] = dp[i-1][j];
//         }
//     }
//     return dp[n][W];
// }

//1
int main()
{
    fastio;
    int t=1; //cin>>t;
    while(t--)
    {
        int n,W; cin>>n>>W;

        int w[n];
        ll v[n];

        FOR(i,0,n) cin>>w[i]>>v[i];
        memset(dp,-1,sizeof(dp));
        cout<<maxVal(w,v,n,W);
        //cout<<dptable(w,v,n,W, 0);
    }
    return 0;
}   