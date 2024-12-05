// TechVault--OOP-Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>


using namespace std;

//which will also be the CLASSES NAMES
enum CommandType { CREATE_TABLE, DROP_TABLE, DISPLAY_TABLE, CREATE_INDEX, DROP_INDEX, INSERT, SELECT, UPDATE, DELETE, WRONG };

CommandType identify(string command) {
    string cmd = command; //a copy
    for (int i = 0; i < strlen(command); i++)
        cmd[i] = toupper(cmd[i]);

    if (strncmp(cmd, "CREATE TABLE", 12) == 0) {
        return CREATE_TABLE;       //it returns one of the enum types
    }
    else if (strncmp(cmd, "DROP TABLE", 10) == 0) {
        return DROP_TABLE;
    }
    else if (strncmp(cmd, "DISPLAY TABLE", 13) == 0) {
        return DISPLAY_TABLE;
    }
    else if (strncmp(cmd, "CREATE INDEX", 12) == 0) {
        return CREATE_INDEX;
    }
    else if (strncmp(cmd, "DROP INDEX", 10) == 0) {
        return DROP_INDEX;
    }
    else if (strncmp(cmd, "INSERT", 6) == 0) {
        return INSERT;
    }
    else if (strncmp(cmd, "SELECT", 6) == 0) {
        return SELECT;
    }
    else if (strncmp(cmd, "UPDATE", 6) == 0) {
        return UPDATE;
    }
    else if (strncmp(cmd, "DELETE", 6) == 0) {
        return DELETE;
    }
    else {
        return WRONG;
    }
}

int main()
{
    string command;
    cout << "Enter a SQL command: " << endl;
    getline(cin, command);
    CommandType type = identify(command);
    cout << endl<<"Command Type is:  " << type;


}


