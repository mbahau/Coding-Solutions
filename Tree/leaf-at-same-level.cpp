
//https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1




//2
int H;
bool isutil(Node* root, int h)
{
    if(root==NULL) return 1;
  //  if(H==-1) H=h;
    if(root->left==NULL && root->right==NULL) if(H==-1) { H=h; return 1;} 
            else if(h!=H) return 0;
    return isutil(root->left, h+1) && isutil(root->right, h+1);
}
//1
bool check(Node *root)
{
    //Your code here
    if(root==NULL) return 1;
    H=-1;
    return isutil(root,0);
}