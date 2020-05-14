//
// Created by al_sah on 28.03.20.
//

#include "class_trip.h"



std::ostream & operator << (std::ostream &out, trip &trip) {
    out
            << trip.getId() << ' '
            << trip.getDate() << ' '
            << trip.getPlatformId() << ' '
            << trip.getRouteId() << ' '
            << trip.getTrainId() << '\n';

    return out;
}

void operator >> (std::istream &in, trip &trip) {

    DB_ID tempID;
    PLATFORM_ID platformId;
    DATE trip_date;


    in >> tempID;
    trip.setId(tempID);

    in >> trip_date;
    trip.setDate(trip_date);

    in >> platformId;
    trip.setPlatformId(platformId);

    in >> tempID;
    trip.setRouteId(tempID);

    in >> tempID;
    trip.setTrainId(tempID);

}







const PLATFORM_ID &trip::getPlatformId() const {
    return platform_id;
}

void trip::setPlatformId(const PLATFORM_ID &platformId) {
    platform_id = platformId;
}

DB_ID trip::getRouteId() const {
    return route_id;
}

void trip::setRouteId(DB_ID routeId) {
    route_id = routeId;
}

const DATE &trip::getDate() const {
    return date;
}

void trip::setDate(const DATE &trip_date) {
    trip::date = trip_date;
}

DB_ID trip::getTrainId() const {
    return train_id;
}

void trip::setTrainId(DB_ID trainId) {
    train_id = trainId;
}
