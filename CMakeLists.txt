cmake_minimum_required(VERSION 3.15)
project(ISE)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-Wall -Wextra -pedantic )
#add_compile_options(-Wall -Wextra -pedantic -Wno-unused-parameter -Wno-unused-variable  -Werror)

add_executable(ISE main.cpp class_ticket.cpp class_ticket.h class_train.cpp class_train.h class_my_db_record.cpp class_my_db_record.h class_station.cpp class_station.h class_route.cpp class_route.h ise.h class_main_system.cpp class_main_system.h class_trip.cpp class_trip.h user_functions.cpp user_functions.h utils.cpp utils.h interfaces.h user_menus.cpp user_menus.h)