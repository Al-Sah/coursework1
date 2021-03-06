//
// Created by al_sah on 28.03.20.
//

#ifndef ISE_CLASS_TRIP_H
#define ISE_CLASS_TRIP_H

#include <iostream>
#include "class_my_db_record.h"

class trip: public my_db_record {

private:

    PLATFORM_ID platform_id;
    DB_ID route_id;
    DATE date;
    TIME time;
    DB_ID train_id;

public:


    const TIME &getTime() const;
    void setTime(const TIME &time);

    const PLATFORM_ID &getPlatformId() const;
    void setPlatformId(const PLATFORM_ID &platformId);

    DB_ID getRouteId() const;
    void setRouteId(DB_ID routeId);

    const DATE &getDate() const;
    void setDate(const DATE &trip_date);

    DB_ID getTrainId() const;
    void setTrainId(DB_ID trainId);

    friend bool operator > ( const trip & A,  const trip & B);
};

std::ostream & operator << (std::ostream &out, trip &trip);
void operator >> (std::istream &in, trip &trip);















#endif //ISE_CLASS_TRIP_H
