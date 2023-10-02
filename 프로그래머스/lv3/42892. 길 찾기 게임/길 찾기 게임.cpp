#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pre;
vector<int> post;

struct TREE{
    int num;
    int x, y;
    TREE *leftNode;
    TREE *rightNode;
};

bool cmp(TREE A, TREE B)
{
    if(A.y == B.y)
        return A.x < B.x;
    return A.y > B.y;
}
void MakeTree(TREE *root, TREE* node)
{
    if(root->x > node->x)
    {
        if(root->leftNode == NULL)
        {
            root->leftNode = node;
            return;
        }
        else
        {
            MakeTree(root->leftNode, node);
        }
    }
    else
    {
        if(root->rightNode == NULL)
        {
            root->rightNode = node;
            return;
        }
        else
        {
            MakeTree(root->rightNode, node);
        }
    }
}
void PreOrder(TREE* node)
{
    if(node == NULL)
        return;
    
    pre.push_back(node->num);
    PreOrder(node->leftNode);
    PreOrder(node->rightNode);
}

void PostOrder(TREE* node)
{
    if(node == NULL)
        return;
    PostOrder(node->leftNode);
    PostOrder(node->rightNode);
    post.push_back(node->num);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    vector<TREE> treeV;
    for(int i=0; i<nodeinfo.size(); i++)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int num = i + 1;
        treeV.push_back({num, x, y, NULL, NULL});
    }
    
    sort(treeV.begin(), treeV.end(), cmp);
    
    TREE *root = &treeV[0];
    
    for(int i=1; i<treeV.size(); i++)
    {
        MakeTree(root, &treeV[i]);
    }
    PreOrder(root);
    PostOrder(root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}