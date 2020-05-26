//
// Created by al_sah on 28.03.20.
//

#include "class_trip.h"
#include "utils.h"



std::ostream & operator << (std::ostream &out, trip &trip) {
    out
            << trip.getId() << ' '
            << trip.getDate() << ' '
            << trip.getTime() << ' '
            << trip.getPlatformId() << ' '
            << trip.getRouteId() << ' '
            << trip.getTrainId() << '\n';

    return out;
}

void operator >> (std::istream &in, trip &trip) {

    DB_ID tempID;
    PLATFORM_ID platformId;
    DATE trip_date;
    TIME trip_time;


    in >> tempID;
    trip.setId(tempID);

    in >> trip_date;
    trip.setDate(trip_date);

    in >> trip_time;
    trip.setTime(trip_time);

    in >> platformId;
    trip.setPlatformId(platformId);

    in >> tempID;
    trip.setRouteId(tempID);

    in >> tempID;
    trip.setTrainId(tempID);

}


bool operator>(const trip &A, const trip &B) {

    bool zz = false;
    int date_A = date_parser(A.date);
    int date_B = date_parser(B.date);
    if(date_A > date_B){
        zz = true;
    }
    if(date_A == date_B){
        int time_A = time_parser(A.time);
        int time_B = time_parser(B.time);
        if(time_A > time_B){
            zz = true;
        }
    }
    return zz;

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

const TIME &trip::getTime() const {
    return time;
}

void trip::setTime(const TIME &time) {
    trip::time = time;
}
