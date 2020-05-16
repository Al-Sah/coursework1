//
// Created by al_sah on 28.03.20.
//

#include <fstream>
#include "class_main_system.h"
#include "class_ticket.h"
#include "class_train.h"
#include "class_station.h"
#include "user_functions.h"


main_system::main_system() : my_db_record() {

    open_tickets_file(tickets);
    open_trains_file(trains);
    open_station_file(stations);
    open_routes_file(routes);
    open_passengers_file(passengers);
    open_trip_file(trips);
}

main_system::~main_system() {

    save_tickets_file(tickets);
    save_trains_file(trains);
    save_routes_file(routes);
    save_station_file(stations);
    save_passengers_file(passengers);
    save_trip_file(trips);

}


void main_system::dump() {
#if 1 || DEBUG
    for (auto train : trains) {
        std::cout << "IMPORT CHECK" << train;
    }
#endif
}


template<typename my_type>
void main_system::save_file(const std::vector<my_type> &records, const char *file_name) {
    std::ofstream records_file(file_name);
    for (auto obj : records) {
        records_file << obj;
    }
}

void main_system::save_station_file(const std::vector<station> &stations, const char *file_name) {
    save_file(stations, file_name);
}

void main_system::save_trains_file(const std::vector<train> &trains, const char *file_name) {
    save_file(trains, file_name);
}

void main_system::save_tickets_file(const std::vector<ticket> &tickets, const char *file_name) {
    save_file(tickets, file_name);
}

void main_system::save_routes_file(const std::vector<route> &routes, const char *file_name) {
    save_file(routes, file_name);
}
void main_system::save_passengers_file(const std::vector<passenger> &passengers, const char *file_name) {
    save_file(passengers, file_name);
}
void main_system::save_trip_file(const std::vector<trip> &trips, const char *file_name) {
    save_file(trips, file_name);
}



template<typename my_type>
void main_system::open_file(std::vector<my_type> &records, const char *file_name) {
    std::ifstream records_file(file_name);
    while (records_file.good()) {
        my_type obj;
        records_file >> obj;
        if (records_file.good()) {
            records.push_back(obj);
        }
    }
}


void main_system::open_station_file(std::vector<station> &stations, const char *file_name){
    open_file(stations, file_name);
}

void main_system::open_trains_file(std::vector<train> &trains, const char *file_name) {
    open_file(trains, file_name);
}

void main_system::open_tickets_file(std::vector<ticket> &tickets, const char *file_name) {
    open_file(tickets, file_name);
}

void main_system::open_routes_file(std::vector<route> &routes, const char *file_name) {
    open_file(routes, file_name);
}

void main_system::open_passengers_file(std::vector<passenger> &passengers, const char *file_name) {
    open_file(passengers, file_name);
}
void main_system::open_trip_file(std::vector<trip> &trips, const char *file_name) {
    open_file(trips, file_name);
}



template<typename my_type>
DB_ID main_system::next_object_id(std::vector<my_type> &records) {
    DB_ID ret = 0;
    for (auto &some_object: records) {
        if (some_object.getId() >= ret) {
            ret = some_object.getId();
        }
    }
    return ret + 1;
}

DB_ID main_system::next_ticket_id() {
    return next_object_id(tickets);
}

DB_ID main_system::next_train_id() {
    return next_object_id(trains);
}

DB_ID main_system::next_station_id() {
    return next_object_id(stations);
}

DB_ID main_system::next_route_id() {
    return next_object_id(routes);
}
DB_ID main_system::next_passenger_id() {
    return next_object_id(passengers);
}
DB_ID main_system::next_trip_id() {
    return next_object_id(trips);
}




template<typename my_type>
DB_ID main_system::update(std::vector<my_type> &records, my_type updated_record, DB_ID id) {
    int idx = Alex_Utils::find_index(records, id);
    if(idx == NOT_FOUND){
        throw "Object not found";
    }
    records[idx] = updated_record;
    return id;
}

template<typename my_type>
DB_ID main_system::delete_obj(std::vector<my_type> &records, DB_ID id) {
    int idx = Alex_Utils::find_index(records, id);
    if(idx == NOT_FOUND){
        throw "Object not found";
    }
    records.erase(records.begin() + idx);
    return RET_OK;
}

template<typename my_type>
my_type main_system::get_info(std::vector<my_type> &records, DB_ID id) {
    int idx = Alex_Utils::find_index(records, id);
    if(idx == NOT_FOUND){
        throw "Object not found";
    }
    my_type &obj = records[idx];
    return obj;
}

template<typename my_type>
DB_ID main_system::add(std::vector<my_type> &records, my_type record) {
    record.setId(next_object_id(records));
    records.push_back(record);
    return record.getId();
}


station main_system::Get_station_info(DB_ID id) {
    return get_info(stations, id);
}

std::vector<station> main_system::Get_station_vector(){
    return stations;
}

DB_ID main_system::add_station(station &station) {
    DB_ID ret = add(stations, station);
    save_station_file(stations);
    return ret;
}

DB_ID main_system::edit_station(station &edited_station, DB_ID id) {
    DB_ID ret = update(stations, edited_station, id);
    save_station_file(stations);
    return ret;
}

DB_ID main_system::delete_station(DB_ID id) {
    DB_ID ret = delete_obj(stations, id);
    save_station_file(stations);
    return ret;
}


ticket main_system::Get_ticket_info(DB_ID id) {
    return get_info(tickets, id);
}
std::vector<ticket> main_system::Get_ticket_vector() {
    return tickets;
}

DB_ID main_system::add_ticket(ticket &ticket) {
    DB_ID ret = add(tickets, ticket);
    save_tickets_file(tickets);
    return ret;

}

DB_ID main_system::edit_ticket(ticket &edited_ticket, DB_ID id) {
    DB_ID ret = update(tickets, edited_ticket, id);
    save_tickets_file(tickets);
    return ret;
}

DB_ID main_system::delete_ticket(DB_ID id) {
    DB_ID ret = delete_obj(tickets, id);
    save_tickets_file(tickets);
    return ret;
}


route main_system::Get_route_info(DB_ID id) {
    return get_info(routes, id);
}

std::vector<route> main_system::Get_route_vector() {
    return routes;
}

DB_ID main_system::add_route(route &route) {
    DB_ID ret = add(routes, route);
    save_routes_file(routes);
    return ret;
}

DB_ID main_system::edit_route(route &edited_route, DB_ID id) {
    DB_ID ret = update(routes, edited_route, id);
    save_routes_file(routes);
    return ret;
}

DB_ID main_system::delete_route(DB_ID id) {
    DB_ID ret = delete_obj(routes, id);
    save_routes_file(routes);
    return ret;
}


train main_system::Get_train_info(DB_ID id) {
    return get_info(trains, id);
}
std::vector<train> main_system::Get_train_vector() {
    return trains;
}

DB_ID main_system::add_train(train &train) {
    DB_ID ret = add(trains, train);
    save_trains_file(trains);
    return ret;
}

DB_ID main_system::edit_train(train &edited_train, DB_ID id) {
    DB_ID ret = update(trains, edited_train, id);
    save_trains_file(trains);
    return ret;
}

DB_ID main_system::delete_train(DB_ID id) {
    DB_ID ret = delete_obj(trains, id);
    save_trains_file(trains);
    return ret;
}

passenger main_system::Get_passenger_info(DB_ID id) {
    return get_info( passengers, id);
}
std::vector<passenger> main_system::Get_passenger_vector() {
    return passengers;
}

DB_ID main_system::add_passenger(passenger &passenger) {
    DB_ID ret = add(passengers, passenger);
    save_passengers_file(passengers);
    return ret;
}

DB_ID main_system::edit_passenger(passenger &edited_passenger, DB_ID id) {
    DB_ID ret = update(passengers, edited_passenger, id);
    save_passengers_file(passengers);
    return ret;
}

DB_ID main_system::delete_passenger(DB_ID id) {
    DB_ID ret = delete_obj( passengers, id);
    save_passengers_file(passengers);
    return ret;
}



trip main_system::Get_trip_info(DB_ID id) {
    return get_info( trips, id);
}

std::vector<trip> main_system::Get_trip_vector() {
    return trips;
}

DB_ID main_system::add_trip(trip &trip) {
    DB_ID ret = add(trips, trip);
    save_trip_file(trips);
    return ret;
}

DB_ID main_system::edit_trip(trip &edited_trip, DB_ID id) {
    DB_ID ret = update(trips, edited_trip, id);
    save_trip_file(trips);
    return ret;

}

DB_ID main_system::delete_trip(DB_ID id) {
    DB_ID ret = delete_obj( trips, id);
    save_trip_file(trips);
    return ret;
}
