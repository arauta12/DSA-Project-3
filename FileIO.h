#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "School.h"
#pragma once

struct Filereading{
    static void readFile(std::vector<School*>& schools){
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

    static std::vector<School*> filterState(const std::vector<School*>& schools, std::string targetstate){
        std::vector<School*> filtered_schools;
        copy_if(schools.begin(),schools.end(), back_inserter(filtered_schools),[targetstate](School* school) {
            return school->state == targetstate;
        });
        return filtered_schools;
    }

    static std::vector<School*> filterLevel(const std::vector<School*>& schools, std::string targetlevel){
        std::vector<School*> filtered_schools;
        copy_if(schools.begin(),schools.end(), back_inserter(filtered_schools),[targetlevel](School* school) {
            return school->level == targetlevel;
        });
        return filtered_schools;
    }

    static std::vector<School*> filter(std::vector<School*>& schools, std::string targetstate, std::string targetlevel){
        std::vector<School*> filtered_schools;
        if(targetstate != "Enter State abbreviation: "){
            for(char& c: targetstate){
                c = std::toupper(c);
            }
            filtered_schools = filterState(schools,targetstate);
        }
        else
            filtered_schools = schools;
        if(targetlevel != "(Select School Grade)"){
            filtered_schools = filterLevel(filtered_schools,targetlevel);
        }
        return filtered_schools; //If this is empty that means that the state the user entered doesn't exist
    }


};