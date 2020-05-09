//
// Created by al_sah on 27.03.20.
//

#include "class_passenger.h"


int passenger::getPassengerId() const {
    return passenger_id;
}
void passenger::setPassengerId(int passengerId) {
    passenger_id = passengerId;
}
const std::string &passenger::getFullName() const {
    return full_name;
}
void passenger::setFullName(const std::string &fullName) {
    full_name = fullName;
}

const std::string &passenger::getPassword() const {
    return password;
}

void passenger::setPassword(const std::string &password) {
    passenger::password = password;
}
