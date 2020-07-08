/**
 * Квартира
 * @file Flat.h
 * @author Сааль Степан
 */

#ifndef LAB8_FLAT_H
#define LAB8_FLAT_H

#include <string>
#include <cmath>

using namespace std;

/**
 * Квартира
 */
class Flat {
public:
    /**
     * Запись всех данных о квартире
     * @param rooms
     * @param area
     * @param floor
     * @param district
     */
    Flat(int rooms, float area, int floor, const string &district) :
            rooms(rooms), area(area), floor(floor), district(district) {};

    /**
     * Проверка, схожи ли квартиры по требованиям
     * @param another
     * @return
     */
    bool isEqual(const Flat *another) {
        return rooms == another->getRooms() && floor == another->getFloor() &&
               abs(1 - area / another->getArea()) < 0.1;
    }

    int getRooms() const {
        return rooms;
    }

    float getArea() const {
        return area;
    }

    int getFloor() const {
        return floor;
    }

    const string &getDistrict() const {
        return district;
    }

private:
    int rooms;
    float area;
    int floor;
    string district;
};


#endif //LAB8_FLAT_H
