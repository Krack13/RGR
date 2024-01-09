#include <iostream>
#include <string>
#include <stdlib.h>
#include "people.h"
#include <time.h>
#include <map>
using namespace std;
class record {
private:
    people client;
    string date, adress;
    string type_transport[3] = {"������� �����","�������� �������","������"};
    string transport;
    float weight;
public:
    record() {date = "01.01.1999";adress = "�����������,���������,40";transport = "������";weight = 100;}
    record(string name, string surname, string number, string transport, float weight, string date, string adress) {
        this->client = *(new people(name, surname, number));
        this->weight = weight;
        this->date = date;
        this->adress = adress;
        this->transport = transport;
    }
    void createOrder() {
        string name, surname, number;
        cout << "������� ���� ���: "; cin >> name;
        cout << "������� ���� �������: "; cin >> surname;
        cout << "������� ��� ����� ��������: "; cin >> number;
        client = *(new people(name, surname, number));
        cout << "�������� �������� ��������� ��������:" << endl;
        int select = 0;
        for (int i = 0; i < 3; i++) {cout << "[" << i + 1 << "] " << type_transport[i] << endl;}
        while (select < 1 || select>3) {cin >> select;}
        transport = type_transport[select - 1];
        cout << "������� ����� ��� ���������: ";
        int newweight = 0;
        while (newweight < 1) {cin >> newweight;}
        weight = newweight;
        string newdate;
        cout << "������� ���� ��������: ";
        do{cin >> newdate;} while (!(check_date(newdate)));
        date = newdate;
        string city, street, house;
        cout << "������� �����: "; cin >> city;
        cout << "������� �����: "; cin >> street;
        cout << "������� ����� ����: "; cin >> house;
        adress = city + "," + street + "," + house;
    }
    string getTransport() {return transport;}
    float getWeight() {return weight;}
    string getDate() {return date;}
    string getAdress() {return adress;}
    people getClient() {return client;}
    string getClientInfo() {client.print();}
    bool check_year(int y) {
        if (y % 400 == 0)return true;
        else {
            if (y % 100 == 0)return false;
            else {
                if (y % 4 == 0)return true;
                else return false;
            }
        }
    }
    bool check_date(string date) {
        int p1 = date.find('.');
        int p2 = date.find('.', p1 + 1);
        if (p1 == -1 || p2 == -2) {cout << "������������ ����." << endl;return false;}
        int d = stoi(date.substr(0, p1));
        int m = stoi(date.substr(p1 + 1, p2 - p1));
        int y = stoi(date.substr(p2 + 1, date.length() - p2));
        if (y < 0 || m>12 || m < 1 || d < 1) {cout << "������������ ����." << endl;return false;}
        map<string, int> days;
        days["1"] = 31;
        if (check_year(y))days["2"] = 29;
        else days["2"] = 28;
        days["3"] = 31;
        days["4"] = 30;
        days["5"] = 31;
        days["6"] = 30;
        days["7"] = 31;
        days["8"] = 31;
        days["9"] = 30;
        days["10"] = 31;
        days["11"] = 30;
        days["12"] = 31;
        if (d > days[to_string(m)]){cout << "������������ ����." << endl;return false;}
        return true;
    }
    void print() {client.print();cout << "��� ����������: " << transport << " - " << weight << "; ����: " << date << " - " << adress << endl;}
    void edit() {
        cout << "�������� ����� ������, ������� �� ������ �� ���������������:\n";
        cout << "1 - ��� ����������\n";
        cout << "2 - ����� ��� ���������\n";
        cout << "3 - ���� ��������\n";
        cout << "4 - ������ ��������\n";
        int choose = 0;
        while (choose < 1 || choose>4) {cin >> choose;}
        switch (choose) {
        case 1:
        {
            cout << "�������� ��� �������:" << endl;
            int select = 0;
            for (int i = 0; i < 3; i++) {cout << "[" << i + 1 << "] " << type_transport[i] << endl;}
            while (select < 1 || select>3) {cin >> select;}
            transport = type_transport[select - 1];
            break;
        }
        case 2:
        {
            cout << "������� ����� ��� ���������: ";
            int newweight = 0;
            while (newweight < 1){cin >> newweight;}
            weight = newweight;
            break;
        }
        case 3:
        {
            string newdate;
            cout << "������� ����� ���� ��������: ";
            do{cin >> newdate;} while (!(check_date(newdate)));
            date = newdate;
            break;
        }
        case 4:
        {
            string city, street, house;
            cout << "������� �����: "; cin >> city;
            cout << "������� �����: "; cin >> street;
            cout << "������� ����� ����: "; cin >> house;
            adress = city + "," + street + "," + house;
        }
        default:
            break;
        }
    }
};
