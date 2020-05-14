//
// Created by al_sah on 27.03.20.
//

#ifndef ISE_CLASS_PASSENGER_H
#define ISE_CLASS_PASSENGER_H

#include <iostream>
#include "class_my_db_record.h"

class passenger: public my_db_record {

private:

    std::string full_name, first_name, surname, father_name;

public:

    const std::string &getFullName() const;
    void setFullName();

    const std::string &getFirstName() const;
    void setFirstName(const std::string &firstName);

    const std::string &getSurname() const;
    void setSurname(const std::string &user_surname);

    const std::string &getFatherName() const;
    void setFatherName(const std::string &fatherName);

};
std::ostream & operator << (std::ostream &out, passenger &passenger);
void operator >> (std::istream &in, passenger &passenger);

#endif //ISE_CLASS_PASSENGER_H
