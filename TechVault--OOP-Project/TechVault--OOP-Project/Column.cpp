#include "Column.h"

// Default constructor
Column::Column() : name(""), type(""), size(0), default_value(""), data(nullptr) {}

// Parameterized constructor
Column::Column(string name, string type, int size, string default_value)
    : name(name), type(type), size(size), default_value(default_value) {
    data = new string[size];
    for (int i = 0; i < size; ++i) {
        data[i] = default_value;
    }
}

// Copy constructor
Column::Column(const Column& other)
    : name(other.name), type(other.type), size(other.size), default_value(other.default_value) {
    data = new string[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

// Destructor
Column::~Column() {
    delete[] data;
}

// Setters and getters
void Column::setName(string name) {
    this->name = name;
}

string Column::getName() {
    return name;
}

void Column::setType(string type) {
    this->type = type;
}

string Column::getType() {
    return type;
}

void Column::setDefaultValue(string default_value) {
    this->default_value = default_value;
    for (int i = 0; i < size; ++i) {
        data[i] = default_value;
    }
}

string Column::getDefaultValue() {
    return default_value;
}

void Column::setSize(int size) {
    delete[] data;
    this->size = size;
    data = new string[size];
    for (int i = 0; i < size; ++i) {
        data[i] = default_value;
    }
}

int Column::getSize() {
    return size;
}

void Column::setData() {
    for (int i = 0; i < size; ++i) {
        cout << "Enter value for index " << i << ": ";
        cin >> data[i];
    }
}

string* Column::getData() {
    return data;
}

// Friend operators
istream& operator>>(istream& console, Column& c) {
    cout << "Enter column name: ";
    console >> c.name;
    cout << "Enter column type: ";
    console >> c.type;
    cout << "Enter column size: ";
    console >> c.size;
    cout << "Enter column default value: ";
    console >> c.default_value;

    c.setSize(c.size); // Initialize data with size and default value
    return console;
}

ostream& operator<<(ostream& console, Column& c) {
    console << "Column Name: " << c.name << endl;
    console << "Column Type: " << c.type << endl;
    console << "Column Size: " << c.size << endl;
    console << "Default Value: " << c.default_value << endl;
    console << "Data: ";
    for (int i = 0; i < c.size; ++i) {
        console << c.data[i] << " ";
    }
    console << endl;
    return console;
}
