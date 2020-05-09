//
// Created by al_sah on 27.03.20.
//

#include "class_my_db_record.h"

DB_ID my_db_record::getId() const {
    return id;
}

void my_db_record::setId(DB_ID id) {
    my_db_record::id = id;
}
