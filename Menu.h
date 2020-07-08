/**
 * Меню для картотеки
 * @file Menu.h
 * @author Сааль Степан
 */

#ifndef LAB8_MENU_H
#define LAB8_MENU_H

#include <iostream>
#include "FileCabinet.h"
#include "FlatApplication.h"
#include "Flat.h"
#include <string>

using namespace std;

/**
 * Меню
 */
class Menu {
public:
    /** Создание новой картотеки */
    Menu() {
        fileCabinet = new FileCabinet();
    }

    /**
     * Показать главное меню
     */
    void show() {
        cout << endl;
        cout << "1. Show file-cabinet" << endl;
        cout << "2. New request" << endl;
        cout << "0. Exit" << endl;
        mainMenuAction();
    }

private:
    /** Картотека */
    FileCabinet *fileCabinet;

    /**
     * Действия главного меню
     */
    void mainMenuAction() {
        int action;
        cin >> action;
        if (action == 1) {
            showAction();
        } else if (action == 2) {
            newRequest();
        } else if (action == 0) {
            cout << "Bye!";
            return;
        } else {
            cout << "Wrong action, try again:" << endl;
        }
        show();
    }

    /**
     * Показать картотеку
     */
    void showAction() {
        cout << "File-cabinet:" << endl << endl;
        fileCabinet->show();
        cout << "END" << endl << endl;
    }

    /**
     * Записать данные о квартире
     * @return
     */
    Flat *createFlat() {
        int rooms, floor;
        float area;
        string distinct;
        cout << "Input rooms:" << endl;
        cin >> rooms;
        cout << "Input floor:" << endl;
        cin >> floor;
        cout << "Input area:" << endl;
        cin >> area;
        cout << "Input distinct:" << endl;
        cin >> distinct;
        return new Flat(rooms, area, floor, distinct);
    }

    /**
     * Записать данные о требовании и предложении
     * @return
     */
    FlatApplication *createApplication() {
        Flat *offer, *requirement;
        cout << "Offer:" << endl;
        offer = createFlat();
        cout << "Requirement:" << endl;
        requirement = createFlat();
        return new FlatApplication(requirement, offer);
    }

    /**
     * Создать новый запрос
     */
    void newRequest() {
        FlatApplication *application = createApplication();
        Flat *response = fileCabinet->newRequest(application);
        if (response == nullptr) {
            cout << "No suitable apartments, you are added to the list." << endl;
        } else {
            cout << "You made an exchange! You received:" << endl;
            cout << "rooms:" << response->getRooms()
                << " floor: " << response->getFloor()
                << " area: " << response->getArea()
                << " distinct: " << response->getDistrict() << endl << endl;
        }
    }
};


#endif //LAB8_MENU_H
