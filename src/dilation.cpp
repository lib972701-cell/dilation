#include "dilation.hpp"
#include <vector>
#include <iostream>
#include <cmath>


dilation::dilation(vector<vector<int>>a)
{
    enter_in = a;
    result.clear();
}

//扩容
void dilation::expand(vector<vector<int>> oringin)
{
    int rows = oringin.size();         //获取行数
    int cols = oringin[0].size();     //获取列数
    int end_row = rows+4;
    int end_col = cols+4;

    //扩容result容器
    result.resize(end_row);
    for(auto& row:result)
    {
        row.resize(end_col);
    }

}

//膨胀
void dilation::square_point_dilation(int x,int y)
{
    int startx,starty;
    startx = x-2;
    starty = y-2;
    for(int i=startx;i<startx+5;i++)
    {
        for(int j=starty;j<starty+5;j++)
        {
            result[i][j] = 1;
        }
    }
}

void dilation::circle_point_dilation(int x,int y)
{
    int radius = 2;
    int dx,dy;
    int startx = x-2;
    int starty = y-2;
    float distance;
    for(int i=startx;i<startx+5;i++)
    {
        for(int j = starty;j<starty+5;j++)
        {
            dx = i-x;
            dy = j-y;
            distance = sqrt(dx*dx+dy*dy);
            if(distance <= 2)
            {
                result[i][j] = 1;
            }
        }
    }

}

//总的处理
void dilation::dilation_process()
{
    int row,col;
    expand(enter_in);
    row = enter_in.size();
    col = enter_in[0].size();
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(enter_in[i][j] == 1)
            {
                circle_point_dilation(i+2,j+2);
            }
        }
    }
}

bool dilation::is_struct_point(int x,int y)
{
    int startx = x-2;
    int starty = y-2;
    if(enter_in[x][y] == 1)
    {
        for(int i = startx;i<startx+5;i++)
        {
            for(int j=starty;j<starty+5;j++)
            {
                if(enter_in[i][j] != 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

void dilation::shrink_process()
{
    int row = enter_in.size();
    int col = enter_in[0].size();
    result.resize(row);
    //收缩result
    for(auto& row:result)
    {
        row.resize(col);
    }
    for(int i = 2;i<row-2;i++)
    {
        for(int j = 2;j<col-2;j++)
        {
            if(is_struct_point(i, j))
            {
                result[i][j] = 1;
            }
        }
    }
}

//展示输入的矩阵
void dilation::view_enter()
{
    int row,col;
    row = enter_in.size();
    col = enter_in[0].size();
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<enter_in[i][j]<<' ';
        }
        cout<<endl;
    }
}

//展示输出矩阵
void dilation::view_result()
{
    int row,col;
    row = result.size();
    col = result[0].size();
    for(int i = 0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<result[i][j]<<' ';
        }
        cout<<endl;
    }
}
