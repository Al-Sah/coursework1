//
// Created by al_sah on 27.03.20.
//

#include "class_passenger.h"





std::ostream & operator << (std::ostream &out, passenger &passenger) {
    out
            << passenger.getId() << ' '
            << passenger.getFullName() << ' '
            << passenger.getEMail() << ' '
            << passenger.getPassword() << ' '
            << '\n';

    return out;
}


void operator >> (std::istream &in, passenger &passenger) {

    DB_ID tempID;
    std::string user_data;
    in >> tempID;
    passenger.setId(tempID);

    in >> user_data;
    passenger.setFullName();

    in >> user_data;
    passenger.setEMail(user_data);

    in >> user_data;
    passenger.setPassword(user_data);



}

















const std::string &passenger::getFirstName() const {
    return first_name;
}

void passenger::setFirstName(const std::string &firstName) {
    first_name = firstName;
    setFullName();
}

const std::string &passenger::getSurname() const {
    return surname;
}

void passenger::setSurname(const std::string &user_surname) {
    passenger::surname = user_surname;
    setFullName();
}

const std::string &passenger::getFatherName() const {
    return father_name;
}

void passenger::setFatherName(const std::string &fatherName) {
    father_name = fatherName;
    setFullName();
}

const std::string &passenger::getPassword() const {
    return password;
}

void passenger::setPassword(const std::string &user_password) {
    passenger::password = user_password;
}

const std::string &passenger::getEMail() const {
    return e_mail;
}

void passenger::setEMail(const std::string &eMail) {
    e_mail = eMail;
}

const std::string &passenger::getFullName() const {
    return full_name;
}

void passenger::setFullName() {
    full_name = getSurname() + "_" + getFirstName() + "_" + getFatherName();
}
