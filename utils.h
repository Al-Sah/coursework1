//
// Created by al_sah on 03.05.20.
//

#ifndef ISE_UTILS_H
#define ISE_UTILS_H


#include <vector>
#include "class_main_system.h"
#include "class_ticket.h"
#include "class_train.h"
#include "class_station.h"
#include "class_route.h"

#define MY_DEBUG

enum {
    RET_FAILED,
    RET_OK,


};


void my_dbg(const char *str);

class StationsStorage {

    virtual std::vector<station> & all_stations() = 0;
    virtual DB_ID add_new_station(station station) = 0;
};

template <typename my_type>
void delete_object(my_type &sys, DB_ID obj_id);

void add_new_station(main_system & sys);
void delete_station(main_system &sys);
void edit_station(main_system &sys);
void get_station_information(main_system &sys);


void add_new_ticket(main_system & sys);
void edit_ticket(main_system &sys);
void delete_ticket(main_system &sys);
void get_ticket_information(main_system &sys);

void add_new_route(main_system &sys);
void delete_route(main_system &sys);
void edit_route(main_system &sys);
void get_route_information(main_system &sys);

void add_new_train(main_system &sys);
void delete_train(main_system &sys);
void edit_train(main_system &sys);
void get_train_information(main_system &sys);

#endif //ISE_UTILS_H
