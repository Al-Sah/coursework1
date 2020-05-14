//
// Created by al_sah on 27.03.20.
//

#ifndef ISE_CLASS_TICKET_H
#define ISE_CLASS_TICKET_H

#include <iostream>
#include "class_my_db_record.h"
#include "class_trip.h"


class ticket : public my_db_record {

public:
    typedef enum {
        FREE=0,
        SOLD=1,
        USED=2,
    } STATUS;

private:

    DB_ID trip_id;
    STATUS state;

    PlaceNo your_wagon;
    PlaceNo place_number;

    float price;

    DB_ID departure_station_id;
    DB_ID arrival_station_id;

    std::string passenger_name;



public:

    STATUS getState() const;
    void setState(STATUS t_state);

    PlaceNo getPlaceNumber() const;
    void setPlaceNumber(PlaceNo placeNumber);

    float getPrice() const;
    void setPrice(float t_price);

    DB_ID getTripId() const;
    void setTripId(DB_ID tripId);

    DB_ID getDepartureStationId() const;
    void setDepartureStationId(DB_ID departureStationId);

    DB_ID getArrivalStationId() const;
    void setArrivalStationId(DB_ID arrivalStationId);

    const std::string &getPassengerName() const;
    void setPassengerName(const std::string &passengerName);


    PlaceNo getYourWagon() const;
    void setYourWagon(PlaceNo yourWagon);


};

std::ostream & operator << (std::ostream &out, ticket &ticket1);
void operator >> (std::istream &in, ticket &ticket1);

#endif //ISE_CLASS_TICKET_H
