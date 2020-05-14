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
    NOT_FOUND,
    RET_FAILED,
    RET_OK,
};

void operation_check(int &operation){
    while (!(std::cin >> operation)) {
        std::cout << "Ошибка ввода, нужен int\n";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
}
void set_info_route_help(){
    std::cout << "\n0. End setting info";
    std::cout << "\n1. Set one station";
    std::cout << "\n2. Set many stations";
    std::cout << "\n3. Delete station";
    std::cout << "\n4. Replace station";
    //std::cout << "\n5. ";

}


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
DB_ID get_object_id(const char * prompt);

template <typename my_type>
void get_object_information(main_system &sys);


#endif //ISE_UTILS_H
