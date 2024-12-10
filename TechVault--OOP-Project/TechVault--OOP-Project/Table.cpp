#include "Table.h"
#include <iostream>
using namespace std;

// Default constructor
Table::Table() : columns(nullptr), name(""), columnCount(0) {}

// Parameterized constructor
Table::Table(string name, int columnCount, Column* columns) : name(name), columnCount(columnCount) {
    this->columns = new Column[columnCount];
    for (int i = 0; i < columnCount; ++i) {
        this->columns[i] = columns[i];
    }
}

// Copy constructor
Table::Table(const Table& table) : name(table.name), columnCount(table.columnCount) {
    columns = new Column[columnCount];
    for (int i = 0; i < columnCount; ++i) {
        columns[i] = table.columns[i];
    }
}

// Destructor
Table::~Table() {
    delete[] columns;
}

// Setters and getters
void Table::setName(string name) {
    this->name = name;
}

string Table::getName() {
    return name;
}

void Table::setColumnCount(int columnCount) {
    delete[] columns;
    this->columnCount = columnCount;
    columns = new Column[columnCount];
}

int Table::getColumnCount() {
    return columnCount;
}

Column* Table::getColumns() {
    return columns;
}

// Additional methods
void Table::addColumn(const Column& column) {
    Column* newColumns = new Column[columnCount + 1];
    for (int i = 0; i < columnCount; ++i) {
        newColumns[i] = columns[i];
    }
    newColumns[columnCount] = column;
    delete[] columns;
    columns = newColumns;
    ++columnCount;
}

void Table::removeColumn(int index) {
    if (index < 0 || index >= columnCount) {
        cout << "Invalid index." << endl;
        return;
    }
    Column* newColumns = new Column[columnCount - 1];
    for (int i = 0, j = 0; i < columnCount; ++i) {
        if (i != index) {
            newColumns[j++] = columns[i];
        }
    }
    delete[] columns;
    columns = newColumns;
    --columnCount;
}

void Table::displayTable() {
    cout << "Table Name: " << name << endl;
    cout << "Number of Columns: " << columnCount << endl;
    for (int i = 0; i < columnCount; ++i) {
        cout << "Column " << i + 1 << ":" << endl;
        cout << columns[i] << endl;
    }
}
