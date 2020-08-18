//Serialize and Deserialize a Binary Tree 
//practice https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
//solution https://www.youtube.com/watch?time_continue=2&v=jwzo6IsMAFQ&feature=emb_logo


//1
void inorder(Node *root,vector<int> &A)
{
    if(!root) { A.push_back(-1); return ;}
    A.push_back(root->data);
    inorder(root->left, A);
    inorder(root->right,A); 
}
void serialize(Node *root,vector<int> &A)
{
    //Your code here
    if(!root) return ;
    inorder(root,A);
    
}


//2
/*this function deserializes
 the serialized vector A*/
 int ind=0;
Node* consTree(vector<int> &A, int n)
{
    if(ind==n || A[ind]==-1) { ind++; return NULL; }  
    
    Node* temp= new Node(A[ind++]);
    
    temp->left = consTree(A,n);
    temp->right= consTree(A,n);
    return temp;
}
Node * deSerialize(vector<int> &A)
{
   //Your code here
   if(A.size()==0) return NULL;
   Node* ans=consTree(A,A.size());
   ind=0;
   return ans;
   
}
