//https://practice.geeksforgeeks.org/problems/sum-tree/1


//2
bool ans;
int bu(Node* root)
{
    if(root==NULL ) return 0;
    if(!root->left && !root->right) return root->data;
    int lef=0,rig=0;
    
    lef = bu(root->left);
    
    rig= bu(root->right);
    
    int temp= root->data;
    
    root->data+=lef+rig;
    
    if( (lef+rig) != temp)
    { ans=0;   return 0; }
    
    return root->data;
    
}

//1
bool isSumTree(Node* root)
{
    ans=1;
      bu(root);
      return ans;
}