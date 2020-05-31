//
// Created by al_sah on 27.03.20.
//

#ifndef ISE_CLASS_MY_DB_RECORD_H
#define ISE_CLASS_MY_DB_RECORD_H

#include "ise.h"

class main_system;

class my_db_record {
private:
    DB_ID id;

public:
    my_db_record():id(0){}
    DB_ID getId() const;
    void setId(DB_ID id);
};

#endif //ISE_CLASS_MY_DB_RECORD_H
