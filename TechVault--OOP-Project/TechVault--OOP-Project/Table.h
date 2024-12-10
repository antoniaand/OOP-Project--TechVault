#pragma once
#include "Column.h"

class Table {
private:
    Column* columns;
    string name;
    int columnCount;

public:
    // Constructors and destructor
    Table();
    Table(string name, int columnCount, Column* columns);
    Table(const Table& table);
    ~Table();

    // Getters and setters
    void setName(string name);
    string getName();
    void setColumnCount(int columnCount);
    int getColumnCount();
    Column* getColumns();

    // Additional methods
    void addColumn(const Column& column);
    void removeColumn(int index);
    void displayTable();
};
