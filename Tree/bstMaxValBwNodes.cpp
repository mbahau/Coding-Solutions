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


int maxVal(BinaryTreeNode<int> *root,int x)
{
    int ans=INT_MIN;
    bool isit=0;
    while(x!=root->data && root)
    {
        ans = max(ans,root->data);
        if(x>root->data) root=root->right;
        else if(x<root->data) root=root->left;
        if(root->data == x) isit=1;
    }
    if(!isit) return -5;
    return ans;
}
int maximumElement(BinaryTreeNode<int> *root, int x, int y)
{
	//find LCA

    BinaryTreeNode<int> *lca;
    lca=root;
    while(x < lca->data && y < lca->data || x> lca->data && y> lca->data)
    {
        if(x < lca->data && y < lca->data)  lca=lca->left;

        else if( x> lca->data && y> lca->data) lca = lca->right;   
    }
    if(x==y) return -1;
    int maxX = maxVal(lca, x);
    int maxY = maxVal(lca,y);
    if(maxX==-1 && maxY==-5) return -1;
    if(maxX==-1) return y;
    if(maxY==-1) return x;
    return max(maxX, max(maxY, max(x,y)));  
}

int main()
{
    fastio;
    int t=1; //cin>>t;
    while(t--)
    {


    }
    return 0;
}   

