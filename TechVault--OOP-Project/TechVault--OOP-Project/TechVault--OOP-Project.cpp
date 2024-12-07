// TechVault--OOP-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include<string>
using namespace std;


class Column {
private:
    string name = "";
    string type = "";
    int size = 0;
    string default_value="";
public:
    Column() {};
    Column(string name, string type, int size, string default_value) : name(name), type(type), size(size), default_value(default_value) {};   
 //getters and setters
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
    void setType(string type) {
        this->type = type;
    }
    string getType() {
        return this->type;
    }
    void setDefaultValue(string default_value) {
        this->default_value = default_value;
    }
    string getDefaultValue() {
        return this->default_value;
    }
    void setSize(int size) {
        this->size = size;
    }
   int getSize() {
        return this->size;
    }


    
};

class Table {
    Column* column;


};
class Database {
    void Create_Table() {}
    void Drop_Table() {}
    void Display_Table() {}
    void Create_Index() {}
    void Drop_Index() {}
    void Insert() {}
    void Update() {}
    void Delete(){}
    void Select() {}

};

enum CommandType { CREATE_TABLE, DROP_TABLE, DISPLAY_TABLE, CREATE_INDEX, DROP_INDEX, INSERT, SELECT, UPDATE, DELETE, WRONG };

CommandType identify(string command) {
    for (int i = 0; i < command.size(); i++) {
        if (command[i] > 'a' && command[i] < 'z') {
            command[i] = command[i] - ('a' - 'A');
        }
    }

    if (command.find("CREATE TABLE") == 0) {
        return CREATE_TABLE;
    }
    else if (command.find("DROP TABLE") == 0) {
        return DROP_TABLE;
    }
    else if (command.find("DISPLAY TABLE") == 0) {
        return DISPLAY_TABLE;
    }
    else if (command.find("CREATE INDEX") == 0) {
        return CREATE_INDEX;
    }
    else if (command.find("DROP INDEX") == 0) {
        return DROP_INDEX;
    }
    else if (command.find("INSERT") == 0) {
        return INSERT;
    }
    else if (command.find("SELECT") == 0) {
        return SELECT;
    }
    else if (command.find("UPDATE") == 0) {
        return UPDATE;
    }
    else if (command.find("DELETE") == 0) {
        return DELETE;
    }
    else {
        return WRONG;
    }
 
}

//these 2 need to be edited to diplay ONE whole table/database

istream& operator>> (istream& console, Column& c) {
    string name; string type; int size; string default_value;
    cout << "name: "; console >> name;
    cout<<"type: "; console>> type;
    cout << "size: ";  console >> size;
    cout << "default val: "; console >> default_value;
    c.setName(name); c.setDefaultValue(default_value); c.setSize(size); c.setType(type);

    return console;

}
ostream& operator<<(ostream& console, Column& c) {
    cout << "The column created is: ";
    console << "name: " << c.getName() << endl;
    console << "type: " << c.getType() << endl;
    console << "size: " << c.getSize() << endl;
    console << "default val: " << c.getDefaultValue()<<endl;
    return console;
}
int main()
{
    //std::cout << "Hello World!!!  incepem proiectu\n";
    //std::cout << endl << "Testare";
    //std::cout << endl << "Nia, tot nu merge.  --Maria";
    //std::cout << "merge! - nia";
    string command; 
    cout << "Enter a SQL command: " << endl;
    getline(cin, command);
    CommandType type = identify(command);
    cout << endl << "Command Type is:  ";
    switch (type) {
    case CREATE_TABLE:
        cout << "CREATE_TABLE"; break;
    case DROP_TABLE:
        cout << "DROP_TABLE"; break;
    case DISPLAY_TABLE: 
        cout << "DISPLAY_TABLE"; break;
    case CREATE_INDEX:
        cout << "CREATE_INDEX"; break;
    case DROP_INDEX: 
        cout << "DROP_INDEX"; break;
    case INSERT:
        cout << "INSERT"; break;
    case SELECT:
        cout << "SELECT"; break;
    case UPDATE:
        cout << "UPDATE"; break;
    case DELETE:
        cout << "DELETE"; break;
    case WRONG:
        cout << "WRONG"; break;
    }
    cout << endl;

    Column c;
    cin >> c;
    cout <<c;
   
    return 0;

}

