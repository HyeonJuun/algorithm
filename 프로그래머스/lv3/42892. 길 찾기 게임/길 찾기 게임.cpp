#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TREE
{
    int ind;
    int x, y;
    TREE *leftChild;
    TREE *rightChild;
};
bool cmp(TREE a, TREE b)
{
    if(a.y >= b.y)
    {
        if(a.y == b.y)
        {
            if(a.x < b.x)
                return true;
            return false;
        }
        return true;
    }
    return false;
}
void MakeTree(TREE *root, TREE* child)
{
    if(root->x > child->x)
    {
        if(root->leftChild == NULL)
        {
            root->leftChild = child;
            return;
        }
        MakeTree(root->leftChild, child);
    }
    else
    {
        if(root->rightChild == NULL)
        {
            root->rightChild = child;
            return;
        }
        MakeTree(root->rightChild, child);
    }
}
void PreOrder(TREE* root, vector<int> &answer)
{
    if(root == NULL)
        return;
    answer.push_back(root->ind);
    PreOrder(root->leftChild, answer);
    PreOrder(root->rightChild, answer);
}
void PostOrder(TREE* root, vector<int> &answer)
{
    if(root == NULL)
        return;
    PostOrder(root->leftChild, answer);
    PostOrder(root->rightChild, answer);
    answer.push_back(root->ind);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<TREE> tree;
    
    for(int i=0; i<nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int ind = i + 1;
        tree.push_back({ind, x, y, NULL, NULL});
    }
    sort(tree.begin(), tree.end(), cmp);
    
    TREE *root = &tree[0];
    for(int i=1; i< tree.size(); i++)
        MakeTree(root, &tree[i]);
    vector<int> pre_ans, post_ans;
    PreOrder(root, pre_ans);
    PostOrder(root, post_ans);
    answer.push_back(pre_ans);
    answer.push_back(post_ans);
    return answer;
}