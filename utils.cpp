//
// Created by al_sah on 10.05.20.
//


#include "utils.h"

void operation_check(int &operation) {
    while (!(std::cin >> operation)) {
        std::cout << "Input error, you need type: (unsigned int)\nEnter correct data:";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
}
void input_id_check(DB_ID &id) {
    while (!(std::cin >> id)) {
        std::cout << "Input error, you need type: (unsigned int)\nEnter correct data:";
        std::cin.clear();
        while (std::cin.get() != '\n');
    }
}

void input_date(std::string &date) {
    unsigned int d = 40, m = 15, y = 0;
    std::string day, month, year;
    std::cout << std::endl;

    while (d > 32){
        std::cout << "-Input day: ";
        input_id_check(d);
    }
    while (m > 12){
        std::cout << "-Input month: ";
        input_id_check(m);
    }
    while (1 > y){
        std::cout << "-Input year: ";
        input_id_check(y);
    }
    day = std::to_string(d);
    month = std::to_string(m);
    year = std::to_string(y);
    date = day + "." + month + "." + year;

}

std::string ask_user(const char *prompt){
    std::cout << prompt;
    std::string ret;
    std::cin >> ret;

    return ret;
}

DB_ID get_object_id(const char * prompt){
    DB_ID ret;
    std::cout << prompt;
    input_id_check(ret);

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


void set_info_route_help() {
    std::cout << "\n0. End setting info";
    std::cout << "\n1. Set one station";
    std::cout << "\n2. Set many stations";
    std::cout << "\n3. Delete station";
    std::cout << "\n4. Replace station";
    //std::cout << "\n5. ";

}


/*template<typename my_type, typename my_method >
void get_object_information(main_system &sys, my_class, const char *question) {

    DB_ID obg_id =get_object_id(question);
    auto obj = sys.my_method(obg_id);
    std::cout << obj;

}*/
