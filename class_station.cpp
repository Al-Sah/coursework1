//
// Created by al_sah on 27.03.20.
//

#include <vector>
#include "class_station.h"


const std::string &station::getName() const {
    return name;
}

void station::setName(const std::string &st_name) {
    station::name = st_name;
}

station::station() {
//    std::cout << " station[" << (void*)this << "] " << *this <<" born" << std::endl;
}

station::~station() {
//    std::cout << " station[" << (void*)this << "] " << *this <<" died" << std::endl;
}


std::ostream & operator << (std::ostream &out, station &station1) {
    out
            << station1.getId() << ' '
            << station1.getName() << '\n';
    return out;
}

void operator >> (std::istream &in, station &station1) {

    DB_ID tempID;
    std::string station_name;
    in >> tempID;
    station1.setId(tempID);

    in >> station_name;
    station1.setName(station_name);

}