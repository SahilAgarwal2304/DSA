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

int main() {
    vector<int> arr;
    accept(arr);
    char flag = 'y';
    while (flag == 'y' || flag == 'Y') {
        cout << "Current array: ";
        printArray(arr);
        cout << "Choose an operation: " << endl;
        cout << "1. Remove an element" << endl;
        cout << "2. Find an element" << endl;
        cout << "3. Print array" << endl;
        cout << "4. Count elements" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                remove(arr);
                break;
            case 2:
                findElement(arr);
                break;
            case 3:
                printArray(arr);
                break;
            case 4:
                cout << "Number of elements in the array: " << countElements(arr) << endl;
                break;
            case 5:
                flag = 'n';
                continue;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        if (flag != 'n') {
            cout << "Do you want to continue? (y/n): ";
            cin >> flag;
        }
    }
    return 0;
}
