//
// Created by al_sah on 10.05.20.
//


#include "utils.h"


std::string ask_user(const char *prompt){
    std::cout << prompt;
    std::string ret;
    std::cin >> ret;

    return ret;
}

DB_ID get_object_id(const char * prompt){
    DB_ID ret;
    std::cout << prompt;
    std::cin >> ret;

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


/*template<typename my_type, typename my_method >
void get_object_information(main_system &sys, my_class, const char *question) {

    DB_ID obg_id =get_object_id(question);
    auto obj = sys.my_method(obg_id);
    std::cout << obj;

}*/
