#include "Sorting.h"
std::function<bool(School*, School*)> getComparisonFunction(const std::string &attribute, bool ascending){
    return std::function<bool(School*, School*)>(
            [attribute, ascending](School* a, School* b) {
                // if ascending true, greatest to smallest
                // if ascending false, smallest to greatest
                // if the user chooses to have ascending data, the comparison symbol will represent less than
                // if the user chooses to have descending data, the comparison symbol will represent greater than
                // this is implemented to prevent redundant code by using <functional>
                if (attribute == "Population") {
                    return ascending ? (a->population < b->population) : (a->population > b->population);
                } else if (attribute == "Free/reduced lunch") {

                    return ascending ? (a->freereducedlunch < b->freereducedlunch) : (a->freereducedlunch > b->freereducedlunch);
                } else if (attribute == "Student-to-Faculty") {
                    return ascending ? (a->studentfacratio < b->studentfacratio) : (a->studentfacratio > b->studentfacratio);
                }
                return false; // Default case
            }
    );
}
int partition(std::vector<School*> &schools, int low, int high, const std::function<bool(School*, School*)> &compare){
    // chooses the pivot to be the end of the data
    School* pivot = schools[high];
    int i = low - 1;
    for (int j = low; j < high; j++){
        if(compare(schools[j], pivot)){
            i++;
            // swaps values if the comparison operator
            // pass as true for the current pivot and data point
            std::swap(schools[i], schools[j]);
        }
    }
    std::swap(schools[i + 1], schools[high]);
    return i + 1;
}

void quickSort(std::vector<School*> &schools, int low, int high, const std::function<bool(School*, School*)> &compare){
    if(low < high){
        // applying quick sort to sub-arrays
        int index = partition(schools, low, high, compare);
        quickSort(schools, low, index - 1, compare);
        quickSort(schools, index + 1, high, compare);
    }
}

void merge(std::vector<School*>& schools, int left, int mid, int right, const std::function<bool(School*, School*)> &compare){
    int indexL = mid - left + 1;
    int indexR = right - mid;
    std::vector<School*> leftArray(indexL), rightArray(indexR);
    // splits into left and right sub-arrays
    for(int i = 0; i < indexL; i++){
        leftArray[i] = schools[left + i];
    }
    for(int j = 0; j < indexR; j++){
        rightArray[j] = schools[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    // compares the sub-arrays to each other
    // and swaps values accordingly
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
        // performs recursive mergeSort to continue
        // dividing the arrays in half into sub-arrays
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