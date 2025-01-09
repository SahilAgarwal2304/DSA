#include <iostream>
#include <vector>
using namespace std;

void accept(vector<int>& arr) {
    cout << "Enter elements: ";
    int val;
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        cin >> val;
        arr.push_back(val);
        cout << "Do you want to enter another element? (y/n): ";
        cin >> choice;
    }
}

void remove(vector<int>& arr) {
    cout << "Enter element to remove: ";
    int e;
    cin >> e;
    int pos = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == e) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        for (int i = pos; i < arr.size() - 1; i++) {
            arr[i] = arr[i + 1];
        }
        arr.resize(arr.size() - 1);
        cout << "Element removed successfully." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
}

void findElement(const vector<int>& arr) {
    cout << "Enter element to check: ";
    int e;
    cin >> e;
    int pos = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == e) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        cout << "Element found at position: " << pos + 1 << endl;
    } else {
        cout << "Element not found!" << endl;
    }
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int countElements(const vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        count++;
    }
    return count;
}

vector<int> intersection(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result;
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                result.push_back(arr1[i]);
                break;
            }
        }
    }
    return result;
}

vector<int> unionSets(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result = arr1;
    for (int i = 0; i < arr2.size(); i++) {
        bool found = false;
        for (int j = 0; j < result.size(); j++) {
            if (arr2[i] == result[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(arr2[i]);
        }
    }
    return result;
}

vector<int> difference1(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result;
    for (int i = 0; i < arr1.size(); i++) {
        bool found = false;
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(arr1[i]);
        }
    }
    return result;
}

vector<int> difference2(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> result;
    for (int i = 0; i < arr2.size(); i++) {
        bool found = false;
        for (int j = 0; j < arr1.size(); j++) {
            if (arr2[i] == arr1[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            result.push_back(arr2[i]);
        }
    }
    return result;
}

bool isSubset(const vector<int>& arr1, const vector<int>& arr2) {
    for (int i = 0; i < arr1.size(); i++) {
        bool found = false;
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr1, arr2;
    char flag = 'y';
    while (flag == 'y' || flag == 'Y') {
        cout << "Current array 1: ";
        printArray(arr1);
        cout << "Choose an operation: " << endl;
        cout << "1. Accept array 1" << endl;
        cout << "2. Accept array 2" << endl;
        cout << "3. Remove an element from array 1" << endl;
        cout << "4. Remove an element from array 2" << endl;
        cout << "5. Find an element in array 1" << endl;
        cout << "6. Find an element in array 2" << endl;
        cout << "7. Print array 1" << endl;
        cout << "8. Print array 2" << endl;
        cout << "9. Count elements in array 1" << endl;
        cout << "10. Count elements in array 2" << endl;
        cout << "11. Find intersection of array 1 and array 2" << endl;
        cout << "12. Find union of array 1 and array 2" << endl;
        cout << "13. Find difference of array 1 from array 2" << endl;
        cout << "14. Find difference of array 2 from array 1" << endl;
        cout << "15. Check if array 1 is a subset of array 2" << endl;
        cout << "16. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: accept(arr1); break;
            case 2: accept(arr2); break;
            case 3: remove(arr1); break;
            case 4: remove(arr2); break;
            case 5: findElement(arr1); break;
            case 6: findElement(arr2); break;
            case 7: printArray(arr1); break;
            case 8: printArray(arr2); break;
            case 9: cout << "Number of elements in array 1: " << countElements(arr1) << endl; break;
            case 10: cout << "Number of elements in array 2: " << countElements(arr2) << endl; break;
            case 11: {
                vector<int> intersectionResult = intersection(arr1, arr2);
                cout << "Intersection of array 1 and array 2: ";
                printArray(intersectionResult);
                break;
            }
            case 12: {
                vector<int> unionResult = unionSets(arr1, arr2);
                cout << "Union of array 1 and array 2: ";
                printArray(unionResult);
                break;
            }
            case 13: {
                vector<int> differenceResult1 = difference1(arr1, arr2);
                cout << "Difference of array 1 from array 2: ";
                printArray(differenceResult1);
                break;
            }
            case 14: {
                vector<int> differenceResult2 = difference2(arr1, arr2);
                cout << "Difference of array 2 from array 1: ";
                printArray(differenceResult2);
                break;
            }
            case 15: {
                if (isSubset(arr1, arr2)) {
                    cout << "Array 1 is a subset of Array 2." << endl;
                } else {
                    cout << "Array 1 is NOT a subset of Array 2." << endl;
                }
                break;
            }
            case 16: flag = 'n'; continue;
            default: cout << "Invalid choice! Please try again." << endl;
        }
        if (flag != 'n') {
            cout << "Do you want to continue? (y/n): ";
            cin >> flag;
        }
    }
    return 0;
}
