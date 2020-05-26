//
// Created by al_sah on 27.03.20.
//

#include <vector>
#include "class_station.h"

#define CLR_NORMAL "\033[0m"
#define CLR_RED "\033[31;1;1m"
#define CLR_GREEN "\033[32;1;1m"


const std::string &station::getName() const {
    return name;
}

void station::setName(const std::string &st_name) {
    station::name = st_name;
}


bool operator>(const station &A, const station &B) {

    bool zz = false;
    if(A.name > B.name){
        zz = true;
    }
    return zz;

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