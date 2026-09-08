#include "dilation.hpp"
#include <vector>

dilation::dilation(vector<vector<int>>a)
{
    enter_in = a;
    result.clear();
}

vector<vector<int>> dilation::expand(vector<vector<int>> oringin)
{
    vector<vector<int>> result;
    int rows = oringin.size();         //获取行数
    int cols = oringin[0].size();     //获取列数
    int end_row = rows;
    int end_col = cols;
    int i,j;
    //遍历待处理二维数组最外圈元素，进行扩容处理
    for(i = 0;i<cols-1;i++)
    {
        if(oringin[0][i]==1)
        {
            i = cols-1;
            end_row += 2;
            break;
        }
    }
    for(int j = 0;j<rows-1;j++)
    {
        if(oringin[i][j] == 1)
        {
            end_col+=2;
            j=rows-1;
            break;
        }
    }
    for(j;j>0;j--)
    {
        if(oringin[rows-1][j]==1)
        {
            end_row+=2;
            break;
        }
    }
    for(i = rows-1;i>=0;i--)
    {
        if(oringin[i][0]==1)
        {
            end_col+=2;
            break;
        }
    }

    //扩容二维容器
    result.resize(end_row);
    for(auto& row:result)
    {
        row.resize(end_col);
    }
}

void dilation::dilation_process()
{
    int rows = enter_in.size();         //获取行数
    int cols = enter_in[0].size();     //获取列数

}
