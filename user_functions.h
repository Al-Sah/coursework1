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

DB_ID ask_trip_id_from_user(main_system & sys);
DB_ID ask_route_id_from_user(main_system & sys);
DB_ID ask_train_id_from_user(main_system & sys);
DB_ID ask_ticket_id_from_user(main_system & sys);
DB_ID ask_station_id_from_user(main_system & sys);

void db_info(main_system &sys);

std::string return_station_name(main_system &sys, DB_ID station_id);
std::vector<std::string> get_names_from_stations(const std::vector<station>& stations);
DB_ID find_station_by_name(main_system & sys);
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
void set_ticket_information(main_system &sys, ticket &new_ticket);

void buying_ticket(main_system &sys);
void generate_trip_tickets(main_system &sys, DB_ID train_id, DB_ID trip_id);

void add_new_trip(main_system &sys);
void delete_trip(main_system &sys);
void delete_trip(main_system &sys, DB_ID id);
void edit_trip(main_system &sys);
void get_trip_list(main_system &sys);
void get_trip_information(main_system &sys);
void get_trip_information(main_system &sys, DB_ID trip_id);
void set_trip_information(main_system &sys, trip &trip);

std::vector<DB_ID> find_correct_routes_id_by_stations(main_system &sys, DB_ID arrival_station, DB_ID departure_station);
DB_ID find_correct_trip_id(main_system &sys, DATE date, std::vector<DB_ID>& good_routes);
DB_ID find_correct_ticket(main_system & sys, DB_ID trip_id);
std::string ask_passenger_name();
std::vector<ticket> get_trip_tickets_list(main_system &sys, DB_ID trip_id);

DB_ID find_route_by_stations(main_system &sys);
std::vector<DB_ID> route_arrival_station_and_departure_station_ids(main_system &sys);
std::vector<DB_ID> route_arrival_station_and_departure_station_ids(main_system &sys, DB_ID route_id);
std::vector<station> route_arrival_station_and_departure_station(main_system &sys, DB_ID route_id);
void add_new_route(main_system &sys);
void delete_route(main_system &sys);
void delete_route(main_system &sys, DB_ID id);
void edit_route(main_system &sys);
void get_route_list(main_system &sys);
void get_route_information(main_system &sys);
void get_route_stations(main_system &sys);
void get_route_stations(main_system &sys, DB_ID route_id);
void get_route_information(main_system &sys, DB_ID route_id);
void set_route_information(main_system &sys,route &route);


void add_new_train(main_system &sys);
void delete_train(main_system &sys);
void delete_train(main_system &sys, DB_ID id);
void edit_train(main_system &sys);
void get_train_list(main_system &sys);
void get_train_information(main_system &sys);
void get_train_information(main_system &sys, DB_ID train_id);
void set_train_information(train &train);


void free_places_on_certain_trip(main_system &sys, const std::vector<trip>& trips_to_the_date, std::vector<ticket> trip_tickets);
std::vector<trip> trips_on_certain_date(main_system &sys);
void free_places_list(main_system &sys, DB_ID trip_id);

template <typename my_type>
void my_shaker_stop_sort_temp_storage(std::vector<my_type> & records, size_t size);

void get_detailed_trip_info(main_system & sys);
void get_detailed_trip_info(main_system & sys, DB_ID trip_id);
void schedule_report(main_system &sys);
void sort_stations_by_names(main_system &sys);
void trips_on_certain_date_report(main_system &sys);
void free_places_on_certain_trip_report(main_system &sys);
void routes_which_contain_certain_station_report(main_system &sys);
void routes_which_contain_many_stations_report(main_system &sys);
void the_most_popular_route_report(main_system &sys);
void trips_which_use_certain_route_report(main_system &sys);


#endif //ISE_USER_FUNCTIONS_H

