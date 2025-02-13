#include <iostream>
#include <string>
using namespace std;

class ContactEntry {
public:
string name;
int number;
ContactEntry* next;

ContactEntry(string contactName, int phoneNumber) {
name = contactName;
number = phoneNumber;
next = NULL;
}
};

class HashTableChaining {
ContactEntry* table[10] = {NULL};

public:
void insertContact(string name, int number) {
ContactEntry* newContact = new ContactEntry(name, number);
int index = number % 10;
if (table[index] == NULL) {
table[index] = newContact;
} else {
ContactEntry* temp = table[index];
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newContact;
}
}

bool searchContact(int number) {
int index = number % 10;
ContactEntry* temp = table[index];

NAME: Sahil Agarwal
Roll No: 23CO004
Comp A, Batch A

ASSIGNMENT 1

while (temp != NULL) {
if (temp->number == number) {
cout << "Name: " << temp->name << ", Phone: " << temp->number << endl;
return true;
}
temp = temp->next;
}
return false;
}

void displayContacts() {
for (int i = 0; i < 10; i++) {
ContactEntry* temp = table[i];
while (temp != NULL) {
cout << "Name: " << temp->name << " , Phone: " << temp->number << endl;
temp = temp->next;
}
}
}
};

class HashTableLinearProbing {
string names[10];
int numbers[10];
bool occupied[10] = {false};

public:
void insertContact(string name, int number) {
int index = number % 10;
int startIdx = index;

while (occupied[index]) {
index = (index + 1) % 10;
if (index == startIdx) {
cout << "Contact List is Full!" << endl;
return;
}
}

names[index] = name;
numbers[index] = number;
occupied[index] = true;
}

bool searchContact(int number) {
int index = number % 10;
int startIdx = index;

while (occupied[index]) {
if (numbers[index] == number) {
cout << "Name: " << names[index] << ", Phone: " << numbers[index] << endl;
return true;
}
index = (index + 1) % 10;
if (index == startIdx) break;
}
return false;
}

void displayContacts() {
for (int i = 0; i < 10; i++) {
if (occupied[i]) {
cout << "Name: " << names[i] << " , Phone: " << numbers[i] << endl;
}
}
}
};

int main() {
HashTableChaining chainingTable;
HashTableLinearProbing probingTable;

int methodChoice;
cout << "Choose Hashing Method:\n1. Chaining\n2. Linear Probing\nEnter choice: ";
cin >> methodChoice;

char action;

while (true) {
cout << "\nOptions:\n1. Add Contact\n2. Find Contact\n3. View Contacts\n4. Exit\nEnter action: ";
cin >> action;

if (action == '1') {
cout << "Enter Contact Name: ";
string name;
cin >> name;
cout << "Enter Phone Number: ";
int phone;
cin >> phone;

if (methodChoice == 1)
chainingTable.insertContact(name, phone);
else
probingTable.insertContact(name, phone);
} else if (action == '2') {
cout << "Enter Phone Number to search: ";
int searchPhone;
cin >> searchPhone;

bool found = (methodChoice == 1) ? chainingTable.searchContact(searchPhone) : probingTable.searchContact(searchPhone);
if (!found)
cout << "Phone Number not found." << endl;
} else if (action == '3') {
if (methodChoice == 1)
chainingTable.displayContacts();
else
probingTable.displayContacts();
} else if (action == '4') {
break;
} else {
cout << "Invalid Option" << endl;
}
}
return 0;
}
