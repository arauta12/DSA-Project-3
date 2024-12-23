#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "School.h"
#pragma once

struct Filereading{
    //Reads the csv
    static void readFile(std::vector<School*>& schools){
        std::ifstream file("..\\cmake-build-debug\\Public_School_Characteristics_-_Current.csv");
        std::string line;
        bool first = true;
        //Reads the ifstream
        while(getline(file,line)){
            std::vector<std::string> data;
            std::string value;
            std::stringstream ss(line);
            if(first){
                first = false;
                continue;
            }
            while(getline(ss,value,',')){
                data.push_back(value);
            }
            //Doesn't add invalid/incomplete schools
            School* school = new School(data);
            if(school->status == "1" and !school->checkBlank()) {
                schools.push_back(school);
            }
            else
                delete school;

        }
        file.close();
    }

    //Filters the data by a state from user input
    static std::vector<School*> filterState(const std::vector<School*>& schools, std::string targetstate){
        std::vector<School*> filtered_schools;
        copy_if(schools.begin(),schools.end(), back_inserter(filtered_schools),[targetstate](School* school) {
            return school->state == targetstate;
        });
        return filtered_schools;
    }

    //Filters the data by user chosen school level
    static std::vector<School*> filterLevel(const std::vector<School*>& schools, std::string targetlevel){
        std::vector<School*> filtered_schools;
        copy_if(schools.begin(),schools.end(), back_inserter(filtered_schools),[targetlevel](School* school) {
            return school->level == targetlevel;
        });
        return filtered_schools;
    }
};