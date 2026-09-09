#ifndef __DILATION_H
#define __DILATION_H

#include <vector>

using namespace std;

class dilation{
    private:
        vector<vector<int>> enter_in; //输入测试用例 
        vector<vector<int>> result;    //膨胀、腐蚀算法后的结果
    public:
        dilation(vector<vector<int>>a);
        void expand(vector<vector<int>>b);
        void square_point_dilation(int x,int y);
        void circle_point_dilation(int x,int y);
        void dilation_process();
        bool is_struct_point(int x,int y);
        void shrink_process();
        void view_enter();
        void view_result();
};


#endif
