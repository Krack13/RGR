#include <iostream>
#include "controller.h"
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;


int main() {
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    controller ctrl;
    ctrl.execute();
}
