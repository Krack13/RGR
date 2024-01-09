#include <iostream>
#include <string>
#include "record.h"
#include <vector>
#include <fstream>
using namespace std;
class transportation_service{
private:
    int con;
    record* orders;
public:
    transportation_service() {
        con = 3;
        setlocale(LC_ALL, "ru");
        orders = new record[con];
        for (int j = 0; j < con; j++) {record newobject;newobject.createOrder();orders[j] = newobject;}
    }
    void print() {
        setlocale(LC_ALL, "ru");
        for (int i = 0; i < con; i++) {record head_record = orders[i];cout << "[" << i + 1 << "] ";head_record.print();}
    }
    void addRecord() {
        record newrc;
        newrc.createOrder();
        record* newor = new record[con + 1];
        for (int i = 0; i < con; i++) {newor[i] = orders[i];}
        newor[con] = newrc;
        con++;
        orders = newor;
    }
    void addRecordFile(record& newrc) {
        record* newor = new record[con + 1];
        for (int i = 0; i < con; i++) {newor[i] = orders[i];}
        newor[con] = newrc;
        con++;
        orders = newor;
    }
    void deleteRecord(int k) {
        record* newor = new record[con - 1];
        for (int i = 0, j = 0; i < con; i++, j++) {if (i == (k - 1)) { i++; }if (i < con) { newor[j] = orders[i]; }}
        con--;
        orders = newor;
    }
    void savingToFile(bool app) {
        ofstream out;
        try {
            if (app) { out.open("orders.txt", ios::app); }
            else { out.open("orders.txt"); }
        }
        catch (const char* error_message) {cout << error_message << endl;return;}
        if (out.is_open()) {
            string rcInfo;
            for (int i = 0; i < con; i++) {
                record cr_rc = orders[i];
                rcInfo = cr_rc.getClient().getName() + "||" + cr_rc.getClient().getSurname() + "||" + cr_rc.getClient().getNumber() + "||" + cr_rc.getTransport() + "||" + to_string(cr_rc.getWeight()) + "||" + cr_rc.getDate() + "||" + cr_rc.getAdress();
                out << rcInfo << endl;
            }
            out.close();
        }
    }
    void loadFiles() {
        ifstream in("orders.txt");
        if (in.is_open()){
            string newrc;
            while (getline(in, newrc)) {
                string name = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string surname = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string number = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string transport = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                float weight = stof(newrc.substr(0, newrc.find("||")));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string date = newrc.substr(0, newrc.find("||"));
                newrc = newrc.substr(newrc.find("||") + 2, newrc.length() - newrc.find("||"));
                string adress = newrc.substr(0, newrc.length());
                record* newrc = new record(name, surname, number, transport, weight, date, adress);
                addRecordFile(*newrc);
            }
        }
        in.close();
    }
    void editRecord(int con) {orders[con - 1].edit();}
    int getCon() {return con;}
};
