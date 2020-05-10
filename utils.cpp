//
// Created by al_sah on 03.05.20.
//

#include "utils.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <vector>


std::string ask_user(const char *prompt){
    std::cout << prompt;
    std::string ret;
    std::cin >> ret;
    std::cout << std::endl;
    return ret;
}

DB_ID get_object_id(const char * prompt){
    DB_ID ret;
    std::cout << prompt;
    std::cin >> ret;
    std::cout << std::endl;
    return ret;
}


void my_dbg(const char *str){
    std::chrono::time_point<std::chrono::system_clock> now;
    now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
#ifdef MY_DEBUG
    std::cout << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S") << " " << str << std::endl;
    std::flush(std::cout);
#endif

}

void add_new_station(main_system &sys)  {

    std::string new_st_name = ask_user("Creating new station\nEnter station name: ");
    station new_st;
    new_st.setName( new_st_name);
    sys.add_station(new_st);

}


void delete_station(main_system &sys){
    DB_ID st_id = get_object_id("Enter station id which will be deleted : ");
    sys.delete_station(st_id);
}

void edit_station(main_system &sys){
    DB_ID st_id = get_object_id("Enter station id which info you want to edit : ");
    station new_st;

    new_st = sys.Get_station_info(st_id);
    std::cout << "Old station info: "<< new_st << "\nEnter new info:";

    std::string name = ask_user("Set new name ");
    new_st.setName(name);
    std::cout << "New station info: "<< new_st.getId() << " " <<new_st.getName();
    sys.edit_station(new_st, st_id);
}

void get_station_information(main_system &sys){

    DB_ID st_id = get_object_id("Enter station id which info you want to see : ");
    station st;
    st = sys.Get_station_info(st_id);
    std::cout << st;

}

void edit_ticket(main_system &sys){
    DB_ID tic_id = get_object_id("Enter ticket id which info you want to edit : ");
    ticket new_tic;
    new_tic = sys.Get_ticket_info(tic_id);
    std::cout << "Old station info: "<< new_tic << "\nEnter new info:";
    std::cin >> new_tic;
    //TODO Ввод значений класса
    sys.edit_ticket(new_tic, tic_id);
}

void get_ticket_information(main_system &sys){
    DB_ID tic_id = get_object_id("Enter ticket id which info you want to see : ");
    ticket tic;
    tic = sys.Get_ticket_info(tic_id);
    std::cout << tic;

}


void delete_ticket(main_system &sys){
    DB_ID ticket_id = get_object_id("Enter ticket id which will be deleted  ");
    sys.delete_ticket(ticket_id);
}



void add_new_route(main_system &sys){

    unsigned int st_counter, st_id;

    st_counter = get_object_id("Enter number of stations in the route : ");
    route new_route;
    for (auto i = 0; i < st_counter; i++) {
        std::cout << "Enter " << i + 1 << " station id: "; std::cin >>st_id;
        new_route.addStation(st_id);
    }

    sys.add_route(new_route);
}


void get_route_information(main_system &sys){
    DB_ID route_id = get_object_id("Enter route id which info you want to see : ");
    route route;
    route = sys.Get_route_info(route_id);
    std::cout << route;
}

void delete_route(main_system &sys){
    DB_ID route_id = get_object_id("Enter route id which will be deleted  ");
    sys.delete_route(route_id);
}

void edit_route(main_system &sys){
    DB_ID tic_id = get_object_id("Enter route id which info you want to edit : ");
    route new_route;
    new_route = sys.Get_route_info(tic_id);
    std::cout << "Old station info: "<< new_route << "\nEnter new info:";
    std::cin >> new_route;
    //TODO Ввод значений класса
    sys.edit_route(new_route, tic_id);
}

void add_new_train(main_system &sys){

    //TODO AAA
    train new_tr;
    sys.add_train(new_tr);
}
void delete_train(main_system &sys){
    DB_ID train_id = get_object_id("Enter train id which will be deleted  ");
    sys.delete_train(train_id);
}

void edit_train(main_system &sys){
    DB_ID tr_id = get_object_id("Enter train id which info you want to edit : ");
    train new_train;
    new_train = sys.Get_train_info(tr_id);
    std::cout << "Old train info: " << new_train << "\nEnter new info:";
    std::cin >> new_train;
    //TODO Ввод значений класса
    sys.edit_train(new_train, tr_id);
}

void get_train_information(main_system &sys){
    DB_ID train_id = get_object_id("Enter train id which info you want to see : ");
    train train;
    train = sys.Get_train_info(train_id);
    std::cout << train;
}