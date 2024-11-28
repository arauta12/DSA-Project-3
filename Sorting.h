#pragma once
#include <vector>
#include "School.h"
#include <functional>

void quickSort(std::vector<School*> &schools, int low, int high, std::function<bool(School*, School*)> compare);
void mergeSort(std::vector<School*> &schools, int low, int high, std::function<bool(School*, School*)> compare);


#ifndef DSA_PROJECT3_SORTING_H
#define DSA_PROJECT3_SORTING_H

#endif //DSA_PROJECT3_SORTING_H
