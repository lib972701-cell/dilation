#include "dilation.hpp"
#include <vector>
#include <iostream>
#include <cmath>


dilation::dilation(vector<vector<int>>a,vector<vector<int>>b)
{
    enter_in = a;
    struct_element = b;
    ele_row = struct_element.size();
    ele_col = struct_element[0].size();
    result.clear();
}

//扩容
void dilation::expand(vector<vector<int>> oringin)
{
    int rows = oringin.size();         //获取行数
    int cols = oringin[0].size();     //获取列数
    int end_row = rows + ele_row/2*2;
    int end_col = cols + ele_col/2*2;

    //扩容result容器
    result.resize(end_row);
    for(auto& row:result)
    {
        row.resize(end_col);
    }

}

//膨胀
void dilation::point_dilation(int x,int y)
{
    int startx,starty;
    startx = x-ele_row / 2;
    starty = y-ele_col/2;
    for(int i=0;i<ele_row;i++)
    {
        for(int j=0;j<ele_col;j++)
        {
            if(struct_element[i][j] == 1)
            {
                result[startx+i][starty+j] = 1;
            }
        }
    }
    
}

void dilation::circle_point_dilation(int x,int y)
{
    int radius = 2;
    int dx,dy;
    int startx = x-radius;
    int starty = y-radius;
    float distance;
    for(int i=startx;i<startx+2*radius+1;i++)
    {
        for(int j = starty;j<starty+2*radius+1;j++)
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
                point_dilation(i+struct_element.size()/2,j+struct_element[0].size()/2);
            }
        }
    }
}

bool dilation::is_struct_point(int x,int y)
{
    int startx = x-ele_row/2;
    int starty = y-ele_col/2;
        for(int i = 0;i<ele_row;i++)
        {
            for(int j=0;j<ele_col;j++)
            {
                if(struct_element[i][j]==1 && enter_in[startx+i][starty+j] == 0)
                {
                    return false;
                }
            }
        }
        return true;
    
    return false;
}

void dilation::shrink_process()
{
    int row = enter_in.size();
    int col = enter_in[0].size();
    int ele_row = struct_element.size();
    int ele_col = struct_element[0].size();
    result.resize(row);
    //收缩result
    for(auto& row:result)
    {
        row.resize(col);
    }
    for(int i = ele_row/2;i<row-ele_row/2;i++)
    {
        for(int j = ele_col/2;j<col-ele_col/2;j++)
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
