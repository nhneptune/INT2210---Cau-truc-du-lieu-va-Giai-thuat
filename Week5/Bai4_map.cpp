#include <iostream>
#include <string>
#include <map>

using namespace std;

class Student {
    int ID;
    string ten;
    string lop;
public:
    Student(int _ID, string _ten, string _lop) {
        ID = _ID;
        ten = _ten;
        lop = _lop;
    }

    int getID() {
        return ID;
    }

    string getTen() {
        return ten;
    }

    string getLop() {
        return lop;
    }

    void setID(int _ID) {
        ID = _ID;
    }

    void setTen(string _ten) {
        ten = _ten;
    }

    void setLop(string _lop) {
        lop = _lop;
    }
};

class StudentManagement {
    map<int, Student*> studentMap;
public:
    void Insert(int _ID, string _ten, string _lop) {
        Student* student = new Student(_ID, _ten, _lop);
        studentMap.insert(pair<int, Student*>(_ID, student));
    }

    void Delete(int _ID) {
        studentMap.erase(_ID);
    }

    string Infor(int _ID) {
        if (studentMap.find(_ID) == studentMap.end()) {
            return "NA,NA\n";
        }
        else {
           return studentMap[_ID]->getTen() + "," + studentMap[_ID]->getLop() + "\n";
        }
    }
};

void cinUntilChar(string &s, char c) {
    while(true) {
        char temp;
        cin >> temp;
        if (temp == c) {
            break;
        }
        if (temp == '\n') {
            break;
        }
        s += temp;
    }
}

void convertFromStringtoInt(string s, int& i) {
    i = 0;
    for (int j = 0; j < s.length(); j++) {
        i = i * 10 + (s[j] - '0');
    }
}

int main()
{
    StudentManagement students;
    int numberOfOperations;
    cin >> numberOfOperations;
    string ketQua;
    for (int i = 0; i < numberOfOperations; i++) {
        string operation;
        cinUntilChar(operation, '(');
        if (operation == "Insert") {
            string _sID;
            string _ten;
            string _lop;
            cinUntilChar(_sID, ',');
            cinUntilChar(_ten, ',');
            cinUntilChar(_lop, ')');
            int _ID;
            convertFromStringtoInt(_sID, _ID);
            students.Insert(_ID, _ten, _lop);
        }
        else if (operation == "Delete") {
            string _sID;
            cinUntilChar(_sID, ')');
            int _ID;
            convertFromStringtoInt(_sID, _ID);
            students.Delete(_ID);
        }
        else if (operation == "Infor") {
            string _sID;
            cinUntilChar(_sID, ')');
            int _ID;
            convertFromStringtoInt(_sID, _ID);
            ketQua += students.Infor(_ID);
            // students.Infor(_ID);
        }
        else {
            break;
        }
    }
    cout << ketQua;
    return 0;
}