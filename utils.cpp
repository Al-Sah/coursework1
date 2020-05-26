//
// Created by al_sah on 10.05.20.
//


#include "utils.h"
#include <sstream>

DB_ID operation_check() {
    DB_ID operation;
    while (!(std::cin >> operation)) {
        std::cout << "Input error, you need type: (unsigned int)\nEnter correct data:";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    return operation;
}
DB_ID input_id_check() {
    DB_ID id;
    while (!(std::cin >> id)) {
        std::cout << "Input error, you need type: (unsigned int)\nEnter correct data:";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
    return id;
}

DATE ask_user_date() {
    DATE date;
    unsigned int d = 40, m = 15, y = 0;
    std::string day, month, year;
    std::cout << std::endl;

    while (d == 0 || d > 32){
        std::cout << "-Input day (from 1 to 32): ";
        d = input_id_check();
    }
    while (m == 0 || m > 12){
        std::cout << "-Input month (from 1 to 12): ";
        m = input_id_check();
    }
    while (1 > y){
        std::cout << "-Input year: ";
        y = input_id_check();
    }
    day = std::to_string(d);
    month = std::to_string(m);
    year = std::to_string(y);
    date = day + "." + month + "." + year;
    return date;

}

std::string ask_user(const char *prompt){
    std::cout << prompt;
    std::string ret;
    std::cin >> ret;

    return ret;
}





void set_info_route_help() {
    std::cout << "\n0. End setting info";
    std::cout << "\n1. Set one station";
    std::cout << "\n2. Set many stations";
    std::cout << "\n3. Delete station";

}

int date_parser(const DATE & date) {

    int day = -1, month = -1, year = -1, parsed_date;
    std::string temp_variable;
    for (char i : date) {
        if (i == '.') {
            if (day == -1) {
                std::istringstream(temp_variable) >> day;
                temp_variable.clear();
            } else if (month == -1) {
                std::istringstream(temp_variable) >> month;
                temp_variable.clear();
            }
        } else {
            temp_variable.push_back(i);
        }
    }
    std::istringstream(temp_variable) >> year;
    temp_variable.clear();
    parsed_date = year* 10000 + month * 100 + day;
    return parsed_date;

}

TIME ask_user_time() {
    TIME time;
    unsigned int min = 70, hour = 115;
    std::string minutes, hours;
    std::cout << std::endl;

    while (hour > 24){
        std::cout << "-Input hours (from 0 to 24): ";
        hour = input_id_check();
    }
    while (min > 60){
        std::cout << "-Input minutes (from 0 to 60): ";
        min = input_id_check();
    }

    minutes = std::to_string(min);
    hours = std::to_string(hour);

    time = hours + ":" + minutes;
    return time;
}

int time_parser(const DATE & date) {

    int hour = -1, min = -1, parsed_time;
    std::string temp_variable;
    for (char i : date) {
        if (i == '.') {
            if (hour == -1) {
                std::istringstream(temp_variable) >> hour;
                temp_variable.clear();
            }
        } else {
            temp_variable.push_back(i);
        }
    }
    std::istringstream(temp_variable) >> min;
    temp_variable.clear();
    parsed_time = hour * 100 + min;
    return parsed_time;

}






/*template<typename my_type, typename my_method >
void get_object_information(main_system &sys, my_class, const char *question) {

    DB_ID obg_id =get_object_id(question);
    auto obj = sys.my_method(obg_id);
    std::cout << obj;

}*/
