/**
 * Точка входа
 * @file main.com
 * @author Сааль Степан
 */

#include <iostream>
#include "Menu.h"

/**
 * Вывод меню
 * @return
 */
int main() {
    auto *menu = new Menu;
    menu->show();

    return 0;
}
