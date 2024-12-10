#pragma once
#include <iostream>
#include <string>
using namespace std;

class Column {
private:
    string name;
    string type;
    int size;
    string default_value;
    string* data;

public:
    // Constructors
    Column();
    Column(string name, string type, int size, string default_value);
    Column(const Column& other);

    //Destructor
    ~Column();

    // Getters and setters
    void setName(string name);
    string getName();
    void setType(string type);
    string getType();
    void setDefaultValue(string default_value);
    string getDefaultValue();
    void setSize(int size);
    int getSize();
    void setData();
    string* getData();

    // Friend operators for input/output
    friend istream& operator>>(istream& console, Column& c);
    friend ostream& operator<<(ostream& console, Column& c);
};

