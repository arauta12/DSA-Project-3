#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "School.h"
#pragma once

using namespace std;

struct Filereading{
    vector<School*> readFile(){
        vector<School*> schools;
        ifstream file("Public_School_Characteristics_-_Current.csv");
        string line;
        bool first = true;
        while(getline(file,line)){
            vector<string> data;
            string value;
            stringstream ss(line);
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
        return schools;
    }

    vector<School*> filterState(const vector<School*>& schools,string targetstate){
        vector<School*> filtered_schools;
        copy_if(schools.begin(),schools.end(), back_inserter(filtered_schools),[targetstate](School* school) {
            return school->state == targetstate;
        });
        return filtered_schools;
    }

    vector<School*> filterLevel(const vector<School*>& schools, string targetlevel){
        vector<School*> filtered_schools;
        copy_if(schools.begin(),schools.end(), back_inserter(filtered_schools),[targetlevel](School* school) {
            return school->level == targetlevel;
        });
        return filtered_schools;
    }
};