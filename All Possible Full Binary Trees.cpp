class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {

        if(n==1)
            return {new TreeNode(0)};

        vector<TreeNode*> ans;
        
        for(int i=1;i<n;i+=2){

            vector<TreeNode*> left = allPossibleFBT(i);

            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root = new TreeNode();
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};
