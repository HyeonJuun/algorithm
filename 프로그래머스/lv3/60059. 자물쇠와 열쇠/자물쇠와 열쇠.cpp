#include <string>
#include <vector>

using namespace std;

int keySize, lockSize, boardSize;

void RotateKey(vector<vector<int>> &key)
{
    vector<vector<int>> tmp(keySize, vector<int>(keySize, 0));
    
    for(int i=0; i<keySize; i++)
    {
        for(int j=0; j<keySize; j++)
            tmp[i][j] = key[keySize - (j + 1)][i];
    }
    key = tmp;
}
bool check(vector<vector<int>> board, vector<vector<int>> key, int y, int x)
{
    bool res = true;
    
    for(int i=0; i<keySize; i++)
    {
        for(int j=0; j<keySize; j++)
        {
            board[i+y][j+x] += key[i][j];
        }
    }
    
    for(int i=0; i<lockSize; i++)
    {
        for(int j=0; j<lockSize; j++)
        {
            if(board[i + keySize - 1][j + keySize -1] != 1)
            {
                return false;
            }
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    
    keySize = key.size(), lockSize = lock.size();
    boardSize = 2 *(keySize -1) + lockSize;
    
    vector<vector<int>> board(boardSize, vector<int>(boardSize, 0));
    
    for(int i=0; i<lockSize; i++)
    {
        for(int j=0; j<lockSize; j++)
        {
            board[i+keySize-1][j+keySize-1] = lock[i][j];
        }
    }
    
    for(int rotate = 0; rotate <4; rotate++)
    {
        for(int i=0; i<=boardSize - keySize; i++)
        {
            for(int j=0; j<boardSize - keySize; j++)
            {
                if(check(board, key, i, j))
                    return true;
            }
        }
        RotateKey(key);
    }
    return false;
}