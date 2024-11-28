#include <vector>
#include <matplot/matplot.h>
#include <cstdlib>
#include "School.h"
#pragma once

struct Graph{
    void graphTimes(std::vector<float> merge, std::vector<float> quick){
        int size = merge.size();
        int increment = std::max(5,size/10);
        std::vector<float> x_axis;
        for(int i = 1;i<size;i+=increment){
            x_axis.push_back(i);
        }
        x_axis.push_back(size);
        matplot::plot(x_axis, merge, quick);

        //FIXME: Use delay thread on input newline into cin?
        matplot::show();
    }

    std::pair<std::vector<float>,std::vector<float>> dataCall(std::vector<School*> schools){ //This is an un sorted version so we may have to change how we sort
        int size = schools.size();
        int increment = std::max(5,size/10);
        int i = increment;
        std::vector<float> merge_time;
        std::vector<float> quick_time;
        while(i<size){
            std::vector<School*> temp_m(schools.begin(),schools.begin()+increment);
            std::vector<School*> temp_q(schools.begin(),schools.begin()+increment);
            //float m_time = mergesort(temp_m);
            //float q_time = quicksort(temp_q);
            //merege_time.push_back(m_time);
            //quick_time.push_back(q_time);
        }
        return make_pair(merge_time,quick_time); //comment so I can push
    }
};
