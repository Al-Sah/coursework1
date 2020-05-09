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
//    DB_ID train_id;
    int wagons;
    int wagon_places;
    int total_places;


public:
    int getWagons() const;

    void setWagons(int wagons);

    int getWagonPlaces() const;

    void setWagonPlaces(int wagonPlaces);

    int getTotalPlaces() const;

    void setTotalPlaces();


    //TODO: route / stations
//    std::vector<DB_ID> station_ids;


public:


};
std::ostream & operator << (std::ostream &out, train &train1);
void operator >> (std::istream &in, train &train1);

#endif //ISE_CLASS_TRAIN_H
