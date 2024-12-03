#include "Sorting.h"
std::function<bool(School*, School*)> getComparisonFunction(const std::string &attribute, bool ascending){
    return std::function<bool(School*, School*)>(
            [attribute, ascending](School* a, School* b) {
                if (attribute == "Population") {
                    return ascending ? (a->population < b->population) : (a->population > b->population);
                } else if (attribute == "Free/Reduced Lunch") {

                    return ascending ? (a->freereducedlunch < b->freereducedlunch) : (a->freereducedlunch > b->freereducedlunch);
                } else if (attribute == "Student-Faculty Ratio") {
                    return ascending ? (a->studentfacratio < b->studentfacratio) : (a->studentfacratio > b->studentfacratio);
                }
                return false; // Default case
            }
    );
}
int partition(std::vector<School*> &schools, int low, int high, const std::function<bool(School*, School*)> &compare){
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

void quickSort(std::vector<School*> &schools, int low, int high, const std::function<bool(School*, School*)> &compare){
    if(low < high){
        int index = partition(schools, low, high, compare);
        quickSort(schools, low, index - 1, compare);
        quickSort(schools, index + 1, high, compare);
    }
}

void merge(std::vector<School*>& schools, int left, int mid, int right, const std::function<bool(School*, School*)> &compare){
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
void mergeSort(std::vector<School*>& schools, int left, int right, const std::function<bool(School*, School*)> &compare){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(schools, left, mid, compare);
        mergeSort(schools, mid + 1, right, compare);
        merge(schools, left, mid, right, compare);
    }
}


//i'll put a sample implementation here:
// Assume you have a vector of School pointers
// std::vector<School*> schools = /* your data */;

// User selections from the front-end
// std::string selectedAttribute = "Population"; // Could be "School Name" or "City"
// bool ascendingOrder = true; // or false for descending order

// Get the comparison function
// auto compareFunc = getComparisonFunction(selectedAttribute, ascendingOrder);

// Perform sorting
// quickSort(schools, 0, schools.size() - 1, compareFunc);
// Or use mergeSort
// mergeSort(schools, 0, schools.size() - 1, compareFunc);

// Update the display or further process the sorted data