//
// Created by al_sah on 28.03.20.
//

#ifndef ISE_CLASS_TRIP_H
#define ISE_CLASS_TRIP_H

#include "class_my_db_record.h"

class trip: public my_db_record {
    DATE date;
    PLATFORM_ID platform_id;
    DB_ID train_id;
};


#endif //ISE_CLASS_TRIP_H
