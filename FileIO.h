#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "School.h"
#pragma once

struct Filereading{
    void readFile(std::vector<School*>& schools){
        std::ifstream file("Public_School_Characteristics_-_Current.csv");
        std::string line;
        bool first = true;
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
            School* school = new School(data);
            if(school->status == "1")
                schools.push_back(school);
            else
                delete school;

        }
        file.close();
    }

    std::vector<School*> filterState(const std::vector<School*>& schools,std::string targetstate){
        std::vector<School*> filtered_schools;
        copy_if(schools.begin(),schools.end(), back_inserter(filtered_schools),[targetstate](School* school) {
            return school->state == targetstate;
        });
        return filtered_schools;
    }

    std::vector<School*> filterLevel(const std::vector<School*>& schools, std::string targetlevel){
        std::vector<School*> filtered_schools;
        copy_if(schools.begin(),schools.end(), back_inserter(filtered_schools),[targetlevel](School* school) {
            return school->level == targetlevel;
        });
        return filtered_schools;
    }
};