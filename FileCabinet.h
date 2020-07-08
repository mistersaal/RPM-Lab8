/**
 * Картотека
 * @file FileCabinet.h
 * @author Сааль Степан
 */

#ifndef LAB8_FILECABINET_H
#define LAB8_FILECABINET_H

#include "Flat.h"
#include "FlatApplication.h"
#include <list>
#include <iostream>

using namespace std;

/**
 * Картотека
 */
class FileCabinet {
public:
    /**
     * Новый запрос
     * @param application
     * @return
     */
    Flat *newRequest(FlatApplication *application) {
        auto it = applications.begin();
        for (FlatApplication* item : applications) {
            if (item->isEqual(application)) {
                applications.erase(it);
                return item->getOffer();
            }
            advance(it, 1);
        }
        applications.push_back(application);
        return nullptr;
    }

    /**
     * Показать картотеку
     */
    void show() {
        for (FlatApplication* item : applications) {
            cout << "Offer => rooms: " << item->getOffer()->getRooms()
                 << " floor: " << item->getOffer()->getFloor()
                 << " area: " << item->getOffer()->getArea()
                 << " distinct: " << item->getOffer()->getDistrict() << endl;
            cout << "Requirement => rooms: " << item->getRequirement()->getRooms()
                 << " floor: " << item->getRequirement()->getFloor()
                 << " area: " << item->getRequirement()->getArea()
                 << " distinct: " << item->getRequirement()->getDistrict() << endl << endl;
        }
    }

private:
    /** Список запросов */
    list<FlatApplication*> applications = {};
};


#endif //LAB8_FILECABINET_H
