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


void add_new_station(main_system & sys);
void delete_station(main_system &sys);
void delete_station(main_system &sys, DB_ID st_id);
void edit_station(main_system &sys);
void get_station_list(main_system &sys);
void get_station_information(main_system &sys);
void get_station_information(main_system &sys, DB_ID id);
void set_station_information(station &new_st);


void add_default_ticket(main_system & sys, size_t wagon, size_t wg_place, DB_ID trip_id);
void delete_ticket(main_system &sys);
void delete_ticket(main_system &sys, DB_ID id);
void edit_ticket(main_system &sys);
void get_ticket_list(main_system &sys);
void get_ticket_information(main_system &sys);
void get_ticket_information(main_system &sys, DB_ID ticket_id);
void set_ticket_information(ticket &new_ticket);

void generate_trip_tickets(main_system &sys, DB_ID train_id, DB_ID trip_id);
void set_new_trip(main_system &sys);
void delete_trip(main_system &sys);
void delete_trip(main_system &sys, DB_ID id);
void edit_trip(main_system &sys);
void get_trip_list(main_system &sys);
void get_trip_information(main_system &sys);
void get_trip_information(main_system &sys, DB_ID trip_id);
void set_trip_information(trip &trip);

void add_new_route(main_system &sys);
void delete_route(main_system &sys);
void delete_route(main_system &sys, DB_ID id);
void edit_route(main_system &sys);
void get_route_list(main_system &sys);
void get_route_information(main_system &sys);
void get_route_stations(main_system &sys, DB_ID route_id);
void get_route_information(main_system &sys, DB_ID route_id);
void set_route_information(route &route);


void add_new_train(main_system &sys);
void delete_train(main_system &sys);
void delete_train(main_system &sys, DB_ID id);
void edit_train(main_system &sys);
void get_train_list(main_system &sys);
void get_train_information(main_system &sys);
void get_train_information(main_system &sys, DB_ID train_id);
void set_train_information(train &train);

void set_new_passenger(main_system &sys);
void delete_passenger(main_system &sys);
void delete_passenger(main_system &sys, DB_ID id);
void edit_passenger(main_system &sys);
void get_passenger_list(main_system &sys);
void get_passenger_information(main_system &sys);
void get_passenger_information(main_system &sys, DB_ID passenger_id);
void set_passenger_information(passenger &passenger);

#endif //ISE_USER_FUNCTIONS_H
