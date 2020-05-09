//
// Created by al_sah on 27.03.20.
//

#include "class_train.h"

std::ostream & operator << (std::ostream &out, train &train1) {
    out
    << train1.getId() << ' '
    << train1.getWagons() << ' '
    << train1.getWagonPlaces() << ' '
    << train1.getTotalPlaces() << '\n';

    return out;
}


void operator >> (std::istream &in, train &train1) {

    DB_ID tempID;
    int wag_place;
    in >> tempID;
    train1.setId(tempID);

    in >> wag_place;
    train1.setWagons(wag_place);

    in >> wag_place;
    train1.setWagonPlaces(wag_place);

    in >> wag_place;

}


int train::getWagons() const {
    return wagons;
}
void train::setWagons(int wagons) {
    train::wagons = wagons;
    setTotalPlaces();
}
int train::getWagonPlaces() const {
    return wagon_places;
}
void train::setWagonPlaces(int wagonPlaces) {
    wagon_places = wagonPlaces;
    setTotalPlaces();
}
int train::getTotalPlaces() const {
    return total_places;
}
void train::setTotalPlaces() {
    total_places = getWagons() * getWagonPlaces();
}
