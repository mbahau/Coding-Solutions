//answer can include both the given nodes
//problem https://codezen.codingninjas.com/practice/524/2196/maximum-element-between-two-nodes-of-bst
//solution https://www.geeksforgeeks.org/maximum-element-two-nodes-bst/



//2
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
//1
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