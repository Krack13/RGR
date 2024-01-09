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
            if (var == 2) {head_service.addRecord();cout << "Заказ успешно создан!";}
            if (var == 3) {head_service.print();cout << "Введите номер заказа, которой надо удалить:\n";int n;cin >> n; head_service.deleteRecord(n);}
            if (var == 4) {head_service.savingToFile(true);cout << "Заказы успешно сохранены!" << endl;}
            if (var == 5) {head_service.savingToFile(false);}
            if (var == 6) {head_service.loadFiles();cout << "Заказы из файла успешно загружены!" << endl;}
            if (var == 7) {cout << "Выберите заказ, который следует отредактировать:" << endl;
                int choose = 0;
                while (choose < 1 || choose> head_service.getCon() + 1) {
                    head_service.print();
                    cin >> choose;
                }
                head_service.editRecord(choose);
                cout << "Заказ успешно отредактирован!" << endl;
            }
        }
    }

    void menu() {
        cout << "Commands: " << endl;
        cout << "[1] Вывести заказы" << endl;
        cout << "[2] Создать новый заказ" << endl;
        cout << "[3] Удалить существующий заказ" << endl;
        cout << "[4] Добавить заказы в файл" << endl;
        cout << "[5] Перазаписать файл с заказами" << endl;
        cout << "[6] Загрузить заказы из файла" << endl;
        cout << "[7] Отредактировать заказ" << endl;
        cout << "[8] Выход из программы" << endl;
    }
};