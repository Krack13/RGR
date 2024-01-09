#include <iostream>
#include "orders.h"
using namespace std;
class controller {
private:
    transportation_service head_service;
public:
    controller() {}
    void execute() {
        int run = 1;
        while (run) {
            menu();
            int var = 0;
            while (var < 1 || var > 8) {cout << "Input variant: ";cin >> var;}
            if (var == 8) {run = 0;}
            if (var == 1) {head_service.print();}
            if (var == 2) {head_service.addRecord();cout << "����� ������� ������!";}
            if (var == 3) {head_service.print();cout << "������� ����� ������, ������� ���� �������:\n";int n;cin >> n; head_service.deleteRecord(n);}
            if (var == 4) {head_service.savingToFile(true);cout << "������ ������� ���������!" << endl;}
            if (var == 5) {head_service.savingToFile(false);}
            if (var == 6) {head_service.loadFiles();cout << "������ �� ����� ������� ���������!" << endl;}
            if (var == 7) {cout << "�������� �����, ������� ������� ���������������:" << endl;
                int choose = 0;
                while (choose < 1 || choose> head_service.getCon() + 1) {
                    head_service.print();
                    cin >> choose;
                }
                head_service.editRecord(choose);
                cout << "����� ������� ��������������!" << endl;
            }
        }
    }

    void menu() {
        cout << "Commands: " << endl;
        cout << "[1] ������� ������" << endl;
        cout << "[2] ������� ����� �����" << endl;
        cout << "[3] ������� ������������ �����" << endl;
        cout << "[4] �������� ������ � ����" << endl;
        cout << "[5] ������������ ���� � ��������" << endl;
        cout << "[6] ��������� ������ �� �����" << endl;
        cout << "[7] ��������������� �����" << endl;
        cout << "[8] ����� �� ���������" << endl;
    }
};