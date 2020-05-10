//
// Created by al_sah on 28.03.20.
//

#ifndef ISE_CLASS_MAIN_SYSTEM_H
#define ISE_CLASS_MAIN_SYSTEM_H


#include <vector>
#include "class_ticket.h"
#include "class_train.h"
#include "class_station.h"
#include "class_route.h"
#include "class_passenger.h"


#define NOT_FOUND -1



class main_system : public my_db_record {

public:
    main_system();
    ~main_system();

    static void save_station_file(const std::vector<station>& stations, const char *file_name="stations.txt");
    static void save_trains_file(const std::vector<train>& trains, const char *file_name="trains.txt");
    static void save_tickets_file(const std::vector<ticket>& tickets, const char *file_name="tickets.txt");
    static void save_routes_file(const std::vector<route>& routes, const char *file_name="routes.txt");
    static void save_passengers_file(const std::vector<passenger>& passengers, const char *file_name="passengers.txt");

    static void open_station_file( std::vector<station> &stations, const char *file_name="stations.txt");
    static void open_trains_file( std::vector<train> &trains, const char *file_name="trains.txt");
    static void open_tickets_file( std::vector<ticket> &tickets, const char *file_name="tickets.txt");
    static void open_routes_file( std::vector<route> &routes, const char *file_name="routes.txt");
    static void open_passengers_file( std::vector<passenger>& passengers, const char *file_name="passengers.txt");

    DB_ID next_ticket_id();
    DB_ID next_train_id();
    DB_ID next_station_id();
    DB_ID next_route_id();
    DB_ID next_passenger_id();

private:
    std::vector<ticket> tickets;
    std::vector<trip> trips;
    std::vector<passenger> passengers;
    std::vector<train> trains;
    std::vector<station> stations;
    std::vector<route> routes;

    template <typename my_type>
    static void save_file(const std::vector<my_type> &records, const char *file_name);

    template <typename my_type>
    static void open_file(std::vector<my_type> &records, const char *file_name);

    template <typename my_type>
    int find_index(std::vector<my_type> &records, DB_ID id);

    template <typename my_type>
    DB_ID add(std::vector<my_type> & records, my_type record);

    template <typename my_type>
    DB_ID update(std::vector<my_type> & records, my_type record, DB_ID id);

    template <typename my_type>
    DB_ID delete_obj(std::vector<my_type> &records, DB_ID id);

    template <typename my_type>
    my_type get_info(std::vector<my_type> &records, DB_ID id);

    template <typename my_type>
    DB_ID next_object_id(std::vector<my_type> &records);

public:


    station Get_station_info(DB_ID id);
    DB_ID add_station(station &station);
    DB_ID edit_station(station &edited_station, DB_ID id);
    DB_ID delete_station(DB_ID id);

    ticket Get_ticket_info(DB_ID id);
    DB_ID add_ticket(ticket &ticket);
    DB_ID edit_ticket(ticket &edited_ticket, DB_ID id);
    DB_ID delete_ticket(DB_ID id);

    route Get_route_info(DB_ID id);
    DB_ID add_route(route &route);
    DB_ID edit_route(route &edited_route,  DB_ID id);
    DB_ID delete_route(DB_ID id);

    train Get_train_info(DB_ID id);
    DB_ID add_train(train &train);
    DB_ID edit_train(train &edited_train,  DB_ID id);
    DB_ID delete_train(DB_ID id);

    passenger Get_passenger_info(DB_ID id);
    DB_ID add_passenger(passenger &passenger);
    DB_ID edit_passenger(passenger &edited_passenger,  DB_ID id);
    DB_ID delete_passenger(DB_ID id);


    void dump();
};


#endif //ISE_CLASS_MAIN_SYSTEM_H
