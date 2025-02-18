#include <iostream>
#include <string>

using namespace std;

struct Node {
    string title;
    Node* next;
    Node* child;
};

Node* createNode(const string& title) {
    Node* newNode = new Node;
    newNode->title = title;
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    if (!parent || !child) return;

    if (!parent->child) {
        parent->child = child;
    } else {
        Node* temp = parent->child;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void printTree(Node* root, int level = 0) {
    if (!root) return;

    for (int i = 0; i < level; ++i) cout << "  ";
    cout << root->title << endl;

    printTree(root->child, level + 1);
    printTree(root->next, level);
}

void menu() {
    cout << "\nMenu:\n";
    cout << "1. Add Chapter\n";
    cout << "2. Add Section\n";
    cout << "3. Add Subsection\n";
    cout << "4. Print Tree\n";
    cout << "5. Exit\n";
}

int getChoice() {
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
        } else if (choice < 1 || choice > 5) {
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        } else {
            break;
        }
    }
    return choice;
}

int main() {
    Node* book = NULL;
    Node* currentChapter = NULL;
    Node* currentSection = NULL;

    while (true) {
        menu();
        int choice = getChoice();

        switch (choice) {
            case 1: {
                string title;
                cout << "Enter Chapter title: ";
                cin.ignore();
                getline(cin, title);

                Node* newChapter = createNode("Chapter: " + title);
                if (!book) {
                    book = newChapter;
                    currentChapter = book;
                } else {
                    addChild(book, newChapter);
                }
                currentChapter = newChapter;
                currentSection = NULL;
                break;
            }
            case 2: {
                string title;
                cout << "Enter Section title: ";
                cin.ignore();
                getline(cin, title);

                if (!currentChapter) {
                    cout << "Error: Please create a chapter first.\n";
                } else {
                    Node* newSection = createNode("Section: " + title);
                    addChild(currentChapter, newSection);
                    currentSection = newSection;
                }
                break;
            }
            case 3: {
                string title;
                cout << "Enter Subsection title: ";
                cin.ignore();
                getline(cin, title);

                if (!currentSection) {
                    cout << "Error: Please create a section first.\n";
                } else {
                    Node* newSubsection = createNode("Subsection: " + title);
                    addChild(currentSection, newSubsection);
                }
                break;
            }
            case 4: {
                if (!book) {
                    cout << "Error: No book structure created yet.\n";
                } else {
                    printTree(book);
                }
                break;
            }
            case 5: {
                cout << "Exiting program...\n";
                return 0;
            }
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
