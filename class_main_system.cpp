//
// Created by al_sah on 28.03.20.
//

#include <fstream>
#include "class_main_system.h"
#include "class_ticket.h"
#include "class_train.h"
#include "class_station.h"
#include "utils.h"


main_system::main_system() : my_db_record() {

    open_tickets_file(tickets);
    my_dbg("deserialize : tickets ok");
    open_trains_file(trains);
    my_dbg("deserialize : trains ok");
    open_station_file(stations);
    my_dbg("deserialize : stations ok");
    open_routes_file(routes);
    my_dbg("deserialize : routes ok");
    // dump();
}

main_system::~main_system() {

    save_tickets_file(tickets);
    save_trains_file(trains);
    save_routes_file(routes);
    save_station_file(stations);
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


template<typename my_type>
DB_ID main_system::next_object_id(std::vector<my_type> &records) {
    int ret = 0;
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


template<typename my_type>
int main_system::find_index(std::vector<my_type> &records, DB_ID id) {
    for (int i = 0; i < records.size(); ++i) {
        my_type &obj = records[i];
        if (obj.getId() == id) {
            return i;
        }
    }
    return NOT_FOUND;
}

template<typename my_type>
DB_ID main_system::update(std::vector<my_type> &records, my_type updated_record, DB_ID id) {
    int idx = find_index(records, id);
    records[idx] = updated_record;

    return id;
}

template<typename my_type>
DB_ID main_system::delete_obj(std::vector<my_type> &records, DB_ID id) {
    int idx = find_index(records, id);
    if (idx == NOT_FOUND) {
        return RET_FAILED;
    }
    records.erase(records.begin() + idx);
    return RET_OK;
}

template<typename my_type>
my_type main_system::get_info(std::vector<my_type> &records, DB_ID id) {
    int idx = find_index(records, id);
    my_type &obj = records[idx];
    return obj;
}

template<typename my_type>
DB_ID main_system::add(std::vector<my_type> &records, my_type record) {
    record.setId(next_object_id(records));
    records.push_back(record);
    return 0;
}


station main_system::Get_station_info(DB_ID id) {
    return get_info(stations, id);
}

DB_ID main_system::add_station(station &station) {
    return add(stations, station);
}

DB_ID main_system::edit_station(station &edited_station, DB_ID id) {
    return update(stations, edited_station, id);
}

DB_ID main_system::delete_station(DB_ID id) {
    return delete_obj(stations, id);
}


ticket main_system::Get_ticket_info(DB_ID id) {
    return get_info(tickets, id);
}

DB_ID main_system::add_ticket(ticket &ticket) {
    return add(tickets, ticket);
}

DB_ID main_system::edit_ticket(ticket &edited_ticket, DB_ID id) {
    return update(tickets, edited_ticket, id);
}

DB_ID main_system::delete_ticket(DB_ID id) {
    return delete_obj(tickets, id);
}


route main_system::Get_route_info(DB_ID id) {
    return get_info(routes, id);
}

DB_ID main_system::add_route(route &route) {
    return add(routes, route);
}

DB_ID main_system::edit_route(route &edited_route, DB_ID id) {
    return update(routes, edited_route, id);
}

DB_ID main_system::delete_route(DB_ID id) {
    return delete_obj(routes, id);
}


train main_system::Get_train_info(DB_ID id) {
    return get_info(trains, id);
}

DB_ID main_system::add_train(train &train) {
    return add(trains, train);
}

DB_ID main_system::edit_train(train &edited_train, DB_ID id) {
    return update(trains, edited_train, id);
}

DB_ID main_system::delete_train(DB_ID id) {
    return delete_obj(trains, id);
}