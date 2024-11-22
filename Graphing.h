#include <iostream>
#include <vector>
#include <set>
#include <matplot/matplot.h>
#include <cstdlib>
#include "School.h"
#pragma once

using namespace std;

struct Graph{
    void graphTimes(vector<float> merge, vector<float> quick){
        int size = merge.size();
        int increment = max(5,size/10);
        vector<float> x_axis;
        for(int i = 1;i<size;i+=increment){
            x_axis.push_back(i);
        }
        x_axis.push_back(size);
        matplot::plot(x_axis, merge, quick);
        matplot::show();
    }

    pair<vector<float>,vector<float>> dataCall(vector<School*> schools){ //This is an un sorted version so we may have to change how we sort
        int size = schools.size();
        int increment = max(5,size/10);
        int i = increment;
        vector<float> merge_time;
        vector<float> quick_time;
        while(i<size){
            vector<School*> temp_m(schools.begin(),schools.begin()+increment);
            vector<School*> temp_q(schools.begin(),schools.begin()+increment);
            //float m_time = mergesort(temp_m);
            //float q_time = quicksort(temp_q);
            //merege_time.push_back(m_time);
            //quick_time.push_back(q_time);
        }
        return make_pair(merge_time,quick_time);
    }
};
