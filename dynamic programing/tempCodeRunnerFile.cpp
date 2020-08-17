int dp[1000];
// ll maxVal(int w[], ll v[], int n, int W, int wtSum)
// {
//   //  cout<<wtSum<<" "<<n<<endl;
//     if(n==0) return 0;
//     if(dp[n]!=-1) return dp[n];

//     if(wtSum+w[n-1]>W)  return dp[n]= maxVal(w,v,n-1,W, wtSum);
//     //if( W > wtSum+w[n-1]); 

//     return dp[n]=max( maxVal(w,v,n-1,W, wtSum), v[n-1]+maxVal(w,v,n-1,W,  wtSum + w[n-1]) ); 

// }