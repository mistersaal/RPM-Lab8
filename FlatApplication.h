/**
 * Требование и предложение
 * @file FlatApplication.h
 * @author Сааль Степан
 */

#ifndef LAB8_FLATAPPLICATION_H
#define LAB8_FLATAPPLICATION_H

#include "Flat.h"

/**
 * Требование и предложение
 */
class FlatApplication {
public:
    FlatApplication(Flat *requirement, Flat *offer) : requirement(requirement), offer(offer) {};

    ~FlatApplication() {
        delete requirement;
        delete offer;
    }

    /**
     * Проверка, подходят ли два запроса друг к другу
     * @param another
     * @return
     */
    bool isEqual(FlatApplication *another)
    {
        return requirement->isEqual(another->getOffer()) && offer->isEqual(another->getRequirement());
    }

    /**
     * Геттер для требования
     * @return
     */
    Flat *getRequirement() const {
        return requirement;
    }

    /**
     * Геттер для предложения
     * @return
     */
    Flat *getOffer() const {
        return offer;
    }

private:
    Flat *requirement;
    Flat *offer;
};


#endif //LAB8_FLATAPPLICATION_H
