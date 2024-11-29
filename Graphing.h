#include <vector>
#include <matplot/matplot.h>
#include <cstdlib>
#include <chrono>
#include "School.h"
#include "Sorting.h"
#pragma once

struct Graph{
    void graphTimes(std::vector<School*> schools){
        std::pair<std::vector<float>, std::vector<float>> times = dataCall(schools);
        std::vector<float> merge = times.first;
        std::vector<float> quick = times.second;
        int size = merge.size();
        int increment = std::max(5,size/10);
        std::vector<float> x_axis;
        for(int i = 1;i<size;i+=increment){
            x_axis.push_back(i);
        }
        x_axis.push_back(size);
        matplot::plot(x_axis, merge, quick);

        //FIXME: Use delay thread on input newline into cin?
        //FIXME: Doesn't work because our code doesn't run until entered is inputted into the console
        matplot::show();
    }

    std::pair<std::vector<float>,std::vector<float>> dataCall(std::vector<School*> schools){ //This is an un sorted version so we may have to change how we sort
        int size = schools.size();
        int increment = std::max(5,size/10);
        int i = increment;
        std::vector<float> merge_time;
        std::vector<float> quick_time;
        while(i<size){
            std::vector<School*> temp_m(schools.begin(),schools.begin()+i);
            std::vector<School*> temp_q(schools.begin(),schools.begin()+i);
            auto start = std::chrono::high_resolution_clock::now();
            //Call merge sort with temp_m
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration = end - start;
            merge_time.push_back(duration.count());
            start = std::chrono::high_resolution_clock::now();
            //Call quick sort with temp_q
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            quick_time.push_back(duration.count());
            i+=increment;
        }
        return make_pair(merge_time,quick_time); //comment so I can push
    }
};
