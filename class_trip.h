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
    DB_ID train_id;
    DB_ID ticket_id;

public:

    const PLATFORM_ID &getPlatformId() const;
    void setPlatformId(const PLATFORM_ID &platformId);

    DB_ID getRouteId() const;
    void setRouteId(DB_ID routeId);

    const DATE &getDate() const;
    void setDate(const DATE &trip_date);

    DB_ID getTrainId() const;
    void setTrainId(DB_ID trainId);

    DB_ID getTicketId() const;
    void setTicketId(DB_ID ticketId);

};

std::ostream & operator << (std::ostream &out, trip &trip);
void operator >> (std::istream &in, trip &trip);















#endif //ISE_CLASS_TRIP_H
