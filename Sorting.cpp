//FIXME: We need to figure out a way to determine which variable we're comparing and make a min version
#include "Sorting.h"
int partition(std::vector<School*> &schools, int low, int high, std::function<bool(School*, School*)> compare){
    School* pivot = schools[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if(compare(schools[j], pivot)){
            i++;
            std::swap(schools[i], schools[j]);
        }
    }
    std::swap(schools[i + 1], schools[high]);
    return i + 1;
}

void quickSort(std::vector<School*> &schools, int low, int high, std::function<bool(School*, School*)> compare){
    if(low < high){
        int index = partition(schools, low, high, compare);
        quickSort(schools, low, index - 1, compare);
        quickSort(schools, index + 1, high, compare);
    }
}

void merge(std::vector<School*>& schools, int left, int mid, int right, std::function<bool(School*, School*)> compare){
    int indexL = mid - left + 1;
    int indexR = right - mid;
    std::vector<School*> leftArray(indexL), rightArray(indexR);
    for(int i = 0; i < indexL; i++){
        leftArray[i] = schools[left + i];
    }
    for(int j = 0; j < indexR; j++){
        rightArray[j] = schools[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while(i < indexL && j < indexR){
        if(compare(leftArray[i], rightArray[j])){
            schools[k] = leftArray[i];
            i++;
        }
        else{
            schools[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while(i < indexL){
        schools[k] = leftArray[i];
        i++;
        k++;
    }
    while(j < indexR){
        schools[k] = rightArray[j];
        j++;
        k++;
    }
}
void mergeSort(std::vector<School*>& schools, int left, int right, std::function<bool(School*, School*)> compare){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(schools, left, mid, compare);
        mergeSort(schools, mid + 1, right, compare);
        merge(schools, left, mid, right, compare);
    }
}