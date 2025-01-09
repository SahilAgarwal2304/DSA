#include <iostream>
#include <vector>
using namespace std;

vector<int> accept(int n) {
    vector<int> arr;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    return arr;
}

vector<int> remove(vector<int> arr) {
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
        arr.pop_back();
        cout << "Element removed successfully." << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    return arr;
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

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr = accept(n);
    char flag = 'y';
    do {
        cout << "Current array: ";
        printArray(arr);
        cout << "Choose an operation: " << endl;
        cout << "1. Remove an element" << endl;
        cout << "2. Find an element" << endl;
        cout << "3. Print array" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                arr = remove(arr);
                break;
            case 2:
                findElement(arr);
                break;
            case 3:
                printArray(arr);
                break;
            case 4:
                flag = 'n';
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        if (flag != 'n') {
            cout << "Do you want to continue? (y/n): ";
            cin >> flag;
        }
    } while (flag == 'y' || flag == 'Y');
    return 0;
}
