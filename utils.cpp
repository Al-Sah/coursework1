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

    std::string new_st_name = ask_user("Enter station name: ");
    station new_st;
    new_st.setName( new_st_name);
    sys.add_station(new_st);

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

void delete_station(main_system &sys){
    DB_ID st_id = get_object_id("Enter station id which will be deleted : ");
    sys.delete_station(st_id);
}

void edit_station(main_system &sys){
    DB_ID st_id = get_object_id("Enter station id which info you want to edit : ");
    station new_st;

    new_st = sys.Get_station_info(st_id);
    std::cout << "Old station info: "<< new_st.getId() << " " <<new_st.getName() << "\nEnter new info:";

    std::string name = ask_user("Set new name ");
    new_st.setName(name);
    std::cout << "New station info: "<< new_st.getId() << " " <<new_st.getName();
    sys.edit_station(new_st, st_id);
}

void get_station_information(main_system &sys){

    DB_ID st_id = get_object_id("Enter station id which info you want to see : ");
    station st;
    st = sys.Get_station_info(st_id);
    std::cout << st.getId() << " " <<st.getName() << std::endl;
}
