#include <vector>
#include <matplot/matplot.h>
#include <cstdlib>
#include <chrono>
#include "School.h"
#include "Sorting.h"
#pragma once

struct Graph{
    //Graphs the times of merge sort vs quick sort
    void graphTimes(std::vector<School*> schools,std::string comparer, bool ascending){
        std::pair<std::vector<float>, std::vector<float>> times = dataCall(schools,comparer,ascending);
        std::vector<float> merge = times.first;
        std::vector<float> quick = times.second;
        int size = schools.size();
        //Creates an increment of 30 points
        int increment = std::max(5,size/29);
        //Creates the number of points matplot needs to make a correct x axis
        int num_points = size/increment + 1;
        //Creates the x axis
        std::vector<double> x_axis = matplot::linspace(0,size,num_points);
        //Keeps the plot constant and clears it every instance of graphing
        matplot::hold(true);
        matplot::cla();
        //Plots both time functions and labels them
        auto p1 = matplot::plot(x_axis,merge);
        p1->display_name("Merge Sort");
        auto p2 = matplot::plot(x_axis,quick);
        p2->display_name("Quick Sort");

        //Creates the legend and axis labels
        matplot::legend();
        matplot::xlabel("Number of Schools");
        matplot::ylabel("Execution Time(s)");

        //Shows the plot
        matplot::show();
    }

    //Gets the time data
    std::pair<std::vector<float>,std::vector<float>> dataCall(std::vector<School*> schools, std::string comparer, bool ascending){ //This is an un sorted version so we may have to change how we sort
        int size = schools.size();
        //Makes sure 29 + end data points are collected
        int increment = std::max(5,size/29);
        int i = increment;
        std::vector<float> merge_time;
        std::vector<float> quick_time;
        //0 y intercept
        merge_time.push_back(0);
        quick_time.push_back(0);
        //Gets the comparison function for the sorts
        auto compare_function = getComparisonFunction(comparer,ascending);
        //Creates a temporary vector of the schools to the incremented value and runs the sorts with these
        //and storing the times using chrono
        while(i<size){
            std::vector<School*> temp_m(schools.begin(),schools.begin()+i);
            std::vector<School*> temp_q(schools.begin(),schools.begin()+i);
            auto start = std::chrono::high_resolution_clock::now();
            mergeSort(temp_m,0,temp_m.size()-1,compare_function);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration = end - start;
            merge_time.push_back(duration.count());
            start = std::chrono::high_resolution_clock::now();
            quickSort(temp_q,0,temp_q.size()-1,compare_function);
            end = std::chrono::high_resolution_clock::now();
            duration = end - start;
            quick_time.push_back(duration.count());
            i+=increment;
        }
        //Does the whole size of schools
        i = size - 1;
        std::vector<School*> temp_m(schools.begin(),schools.begin()+i);
        std::vector<School*> temp_q(schools.begin(),schools.begin()+i);
        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(temp_m,0,temp_m.size()-1,compare_function);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        merge_time.push_back(duration.count());
        start = std::chrono::high_resolution_clock::now();
        quickSort(temp_q,0,temp_q.size()-1,compare_function);
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        quick_time.push_back(duration.count());
        return make_pair(merge_time,quick_time); //comment so I can push
    }
};
