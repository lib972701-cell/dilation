#ifndef __DILATION_H
#define __DILATION_H

#include <vector>

using namespace std;

class dilation{
    private:
        vector<vector<int>> enter_in;   
        vector<vector<int>> result;    
    public:
        dilation(vector<vector<int>>a);
        vector<vector<int>> expand(vector<vector<int>>b);
        void dilation_process();
};


#endif
