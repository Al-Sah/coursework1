//
// Created by al_sah on 27.03.20.
//

#include "class_ticket.h"

std::ostream & operator << (std::ostream &out, ticket &ticket1) {
    out
    << ticket1.getId() << ' '
    << ticket1.getState() << ' '
    << ticket1.getPlaceNumber()  << ' '
    << ticket1.getPrice() << ' '
    << ticket1.getTripId() << ' '
    << ticket1.getDepartureStationId() << ' '
    << ticket1.getArrivalStationId() << ' '
    << ticket1.getPassengerName()  << '\n';
    
    return out;
}

void operator >> (std::istream &in, ticket &ticket1) {

    DB_ID tempID;
    PlaceNo place;
    float temp_float;
    std::string temp;
    int state;


    in >> tempID;
    ticket1.setId(tempID);

    in >>  state;
    ticket1.setState((ticket::STATUS)state);

    in >> place;
    ticket1.setPlaceNumber(place);

    in >> temp_float;
    ticket1.setPrice(temp_float);

    in >> tempID;
    ticket1.setTripId(tempID);

    in >> tempID;
    ticket1.setDepartureStationId(tempID);

    in >> tempID;
    ticket1.setArrivalStationId(tempID);

    in >> temp;
    ticket1.setPassengerName(temp);

}

ticket::STATUS ticket::getState() const {
    return state;
}
void ticket::setState(ticket::STATUS t_state) {
    ticket::state = t_state;
}
PlaceNo ticket::getPlaceNumber() const {
    return place_number;
}
void ticket::setPlaceNumber(PlaceNo placeNumber) {
    place_number = placeNumber;
}
float ticket::getPrice() const {
    return price;
}
void ticket::setPrice(float t_price) {
    ticket::price = t_price;
}
DB_ID ticket::getTripId() const {
    return trip_id;
}
void ticket::setTripId(DB_ID tripId) {
    trip_id = tripId;
}
DB_ID ticket::getDepartureStationId() const {
    return departure_station_id;
}
void ticket::setDepartureStationId(DB_ID departureStationId) {
    departure_station_id = departureStationId;
}
DB_ID ticket::getArrivalStationId() const {
    return arrival_station_id;
}
void ticket::setArrivalStationId(DB_ID arrivalStationId) {
    arrival_station_id = arrivalStationId;
}
const std::string &ticket::getPassengerName() const {
    return passenger_name;
}
void ticket::setPassengerName(const std::string &passengerName) {
    passenger_name = passengerName;
}