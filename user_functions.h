//
// Created by al_sah on 03.05.20.
//

#ifndef ISE_USER_FUNCTIONS_H
#define ISE_USER_FUNCTIONS_H


#include <vector>
#include "class_main_system.h"
#include "class_ticket.h"
#include "class_train.h"
#include "class_station.h"
#include "class_route.h"
#include "utils.h"

#define MY_DEBUG

enum {
    RET_FAILED,
    RET_OK,
};

class StationsStorage {

    virtual std::vector<station> & all_stations() = 0;
    virtual DB_ID add_new_station(station station) = 0;
};

void add_new_station(main_system & sys);
void delete_station(main_system &sys);
void delete_station(main_system &sys, DB_ID st_id);
void edit_station(main_system &sys);
void get_station_information(main_system &sys);
void get_station_information(main_system &sys, DB_ID id);
void set_station_information(station new_st);


void add_default_ticket(main_system & sys);
void delete_ticket(main_system &sys);
void delete_ticket(main_system &sys, DB_ID id);
void edit_ticket(main_system &sys);
void get_ticket_information(main_system &sys);
void get_ticket_information(main_system &sys, DB_ID ticket_id);
void set_ticket_information(ticket new_ticket);


void add_new_route(main_system &sys);
void delete_route(main_system &sys);
void delete_route(main_system &sys, DB_ID id);
void edit_route(main_system &sys);
void get_route_information(main_system &sys);
void get_route_information(main_system &sys, DB_ID route_id);
void set_route_information(route route);


void add_new_train(main_system &sys);
void delete_train(main_system &sys);
void delete_train(main_system &sys, DB_ID id);
void edit_train(main_system &sys);
void get_train_information(main_system &sys);
void get_train_information(main_system &sys, DB_ID train_id);
void set_train_information(train train);

#endif //ISE_USER_FUNCTIONS_H