#include <iostream>
#include <string>
using namespace std;

class Column {
private:
    string name;
    string type;
    int size;
    string default_value;

public:
    // Constructors
    Column();
    Column(string name, string type, int size, string default_value);

    // Getters and setters
    void setName(string name);
    string getName();
    void setType(string type);
    string getType();
    void setDefaultValue(string default_value);
    string getDefaultValue();
    void setSize(int size);
    int getSize();

    // Friend operators for input/output
    friend istream& operator>>(istream& console, Column& c);
    friend ostream& operator<<(ostream& console, Column& c);
};

class Table {
private:
    Column* columns;
    string name;
    int columnCount;

public:
    // Constructors and destructor
    Table();
    Table(string name, int columnCount, Column* columns);
    ~Table();

    // Getters and setters
    void setName(string name);
    string getName();
    void setColumnCount(int columnCount);
    int getColumnCount();
};
