#include <iostream>
#include <vector>

using namespace std;

//  调试开关
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


#ifdef __tmain
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
//	TreeNode(int x)
//	:val(x), left(NULL), right(NULL)
//    {
//	}
};

#endif // __tmain

class Solution
{
public:

    vector< vector<int> > FindPath(TreeNode* root, int expectNumber)
    {
        vector< vector<int> > res;

        if(root == NULL)
        {
            return res;
        }
        FindPath(root, expectNumber, res);

        return res;
    }
protected :
    void FindPath(TreeNode* root, int leftSum, vector< vector<int> > &res)
    {
        if(root == NULL)
        {
            return;
        }

        /// 用一个静态的变量来存储路径
        static vector<int> path;

        leftSum -= root->val;
        path.push_back(root->val);

        ///
        if(leftSum == 0
        && ((root->left == NULL && root->right == NULL)))
        {
            debug <<"find a path" <<endl;
            for(int i = 0; i < path.size( ); i++)
            {
                debug <<path[i] <<" ";
            }
            debug <<endl;

            res.push_back(path);
            cout <<"size = " <<res.size( ) <<endl;
        }
        else
        {

            if(root->left != NULL)
            {
                FindPath(root->left, leftSum, res);
            }

            if(root->right != NULL)
            {
                FindPath(root->right, leftSum, res);
            }
        }
        leftSum += root->val;
        path.pop_back( );
    }

};


int __tmain( )
{
    //  0  1  2  3 4
    //  {10,5,12,4,7},22
    TreeNode tree[5];
    tree[0].val = 10;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].val = 5;
    tree[1].left = &tree[3];
    tree[1].right = &tree[4];

    tree[2].val = 12;
    tree[2].left = NULL;
    tree[2].right = NULL;

    tree[3].val = 4;
    tree[3].left = NULL;
    tree[3].right = NULL;

    tree[4].val = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;

    Solution solu;
    vector< vector<int> > res = solu.FindPath(&tree[0], 15);
    cout <<"size = " <<res.size( ) <<endl;
    for(int i = 0; i < res.size( ); i++)
    {
        for(int j = 0; j < res[i].size( ); j++)
        {
            cout <<res[i][j] <<" ";
        }
        cout <<endl;
    }

    return 0;
}
