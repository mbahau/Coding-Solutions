//https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1




//3
struct hytNdata
{
    int hyt,data;
    
};
//2
hytNdata bottomUp(Node* root)
{
   
    if(!root) return {0,0};
    
    hytNdata lef = bottomUp(root->left);
    hytNdata rig = bottomUp(root->right);
    
    if(lef.hyt>rig.hyt) {
        return {lef.hyt+1,lef.data+root->data};
        
    }
    else if(lef.hyt<rig.hyt) return {rig.hyt+1,rig.data+root->data};
    else return {lef.hyt+1, max(lef.data,rig.data)+root->data};
    
    
}
//1
int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	if(!root) return 0;
	
	hytNdata ans= bottomUp(root);
	return ans.data;
	
}