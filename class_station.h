//
// Created by al_sah on 27.03.20.
//

#ifndef ISE_CLASS_STATION_H
#define ISE_CLASS_STATION_H

#include <iostream>
#include "class_my_db_record.h"



class station : public my_db_record {

private:
    std::string name;

public:

    friend bool operator > ( const station & A,  const station & B);

    const std::string &getName() const;
    void setName(const std::string &st_name);

};

std::ostream & operator << (std::ostream &out, station &station1);
void operator >> (std::istream &in, station &station1);


#endif //ISE_CLASS_STATION_H
