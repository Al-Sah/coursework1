//
// Created by al_sah on 27.03.20.
//

#ifndef ISE_CLASS_TRAIN_H
#define ISE_CLASS_TRAIN_H

#include <iostream>
#include <vector>
#include "class_my_db_record.h"

class train: public my_db_record {

private:
    size_t wagons;
    size_t wagon_places;
    size_t total_places;


public:
    size_t getWagons() const;

    void setWagons(int wagons);

    size_t getWagonPlaces() const;

    void setWagonPlaces(int wagonPlaces);

    size_t getTotalPlaces() const;

    void setTotalPlaces();

};
std::ostream & operator << (std::ostream &out, train &train1);
void operator >> (std::istream &in, train &train1);

#endif //ISE_CLASS_TRAIN_H
