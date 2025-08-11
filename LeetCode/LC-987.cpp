//987 -->Vertical Order Traversal of a Binary Tree


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;

        queue<pair<TreeNode*, pair<int, int>>>q;
        //node, {row, col}

        q.push({root, {0,0}});

        map<int, map<int, multiset<int>>>mp; //col -> row -> {sorted values}

        while(!q.empty()){

            auto front = q.front(); q.pop();

            TreeNode*&node = front.first;
            auto&coordinate = front.second;
            int&row = coordinate.first;
            int&col = coordinate.second;

            mp[col][row].insert(node->val);

            if(node->left)
                q.push({node->left, {row+1, col-1}});
            
            if(node->right)
                q.push({node->right, {row+1, col+1}});
        }

        //storing result 
        for(auto it:mp){
            auto&colMp = it.second;

            vector<int>vLine;

            for(auto colMpIt : colMp){
                auto&mset = colMpIt.second;
                vLine.insert(vLine.end(), mset.begin(), mset.end());
            }

            ans.push_back(vLine);
        }

     return ans;
    }
};

