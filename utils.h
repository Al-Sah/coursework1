//
// Created by al_sah on 10.05.20.
//

#ifndef ISE_UTILS_H
#define ISE_UTILS_H
#include <iostream>
#include <string>

#include "class_main_system.h"
#include <chrono>

enum {
    NOT_FOUND = -1,
    RET_FAILED = -2,
    RET_OK,
};

DB_ID operation_check();
DB_ID input_id_check();
void set_info_route_help();
DATE ask_user_date();
TIME ask_user_time();

namespace Alex_Utils{

    template<typename my_type>
    int find_index(std::vector<my_type> &records, DB_ID id) {
        for (size_t i = 0; i < records.size(); ++i) {
            my_type &obj = records[i];
            if (obj.getId() == id) {
                return i;
            }
        }
        return NOT_FOUND;
    }
}


void my_dbg(const char *str);
std::string ask_user(const char *prompt);
int date_parser(const DATE& date);
int time_parser(const DATE & date);

template <typename my_type>
void get_object_information(main_system &sys);


#endif //ISE_UTILS_H
