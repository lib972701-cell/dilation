#include "dilation.hpp"
#include <vector>
#include <iostream>


dilation::dilation(vector<vector<int>>a)
{
    enter_in = a;
    result.clear();
}

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

void dilation::point_dilation(int x,int y)
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
                point_dilation(i+2,j+2);
            }
        }
    }
}

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
