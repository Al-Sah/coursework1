//
// Created by al_sah on 13.05.20.
//

#ifndef ISE_INTERFACES_H
#define ISE_INTERFACES_H

#include <vector>
#include "class_station.h"


class StationsStorage {
public:
    virtual std::vector<station> Get_station_vector() = 0;
    virtual DB_ID add_station(station & station) = 0;

    virtual ~StationsStorage(){}
};


#endif //ISE_INTERFACES_H
