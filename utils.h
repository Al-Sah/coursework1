//
// Created by al_sah on 10.05.20.
//

#ifndef ISE_UTILS_H
#define ISE_UTILS_H
#include <iostream>
#include <string>
#include "class_main_system.h"
#include <chrono>

void my_dbg(const char *str);
std::string ask_user(const char *prompt);
DB_ID get_object_id(const char * prompt);

template <typename my_type>
void get_object_information(main_system &sys);


#endif //ISE_UTILS_H
