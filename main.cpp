#include <iostream>
#include <string>
#include <cstring>

#include "class_main_system.h"
#include "user_functions.h"
#include "user_menus.h"



void test_user_func(main_system & vokzal){

    //get_trip_list(vokzal);
    //get_route_stations(vokzal, 11);
    schedule_report(vokzal);
   // sort_stations_by_names(vokzal);

   std::cout << "\ncheck trip functions\n";

    add_new_trip(vokzal);
    get_trip_list(vokzal);
    edit_trip( vokzal);
    delete_trip(vokzal);

    get_trip_information(vokzal);


    trips_which_use_certain_route_report(vokzal);
    routes_which_contain_many_stations_report(vokzal);
    routes_which_contain_certain_station_report(vokzal);
    free_places_on_certain_trip_report(vokzal);
    trips_on_certain_date_report(vokzal);

    edit_station( vokzal);
    buying_ticket(vokzal);

    std::cout << "\ncheck station functions\n";
    find_station_by_name(vokzal);
    add_new_station(vokzal);
    get_station_list(vokzal);
    edit_station( vokzal);
    delete_station(vokzal);
    get_station_information(vokzal);


    std::cout << "\ncheck route functions\n";
    add_new_route(vokzal);
    edit_route(vokzal);
    delete_route(vokzal);
    get_route_list(vokzal);
    get_route_stations(vokzal);
    get_route_information(vokzal);


    std::cout << "\n\ncheck train functions\n\n";
    add_new_train(vokzal);
    edit_train(vokzal);
    delete_train(vokzal);
    get_train_list(vokzal);
    get_train_information(vokzal);

    std::cout << "\n\ncheck passenger functions\n\n";
    get_passenger_list(vokzal);
    set_new_passenger(vokzal);
    edit_passenger( vokzal);
    delete_passenger(vokzal);
    get_passenger_information(vokzal);

    get_ticket_list(vokzal);
    edit_ticket( vokzal);
    delete_ticket(vokzal);
    get_ticket_information(vokzal);

}


extern MenuItem admin_menu[];
extern MenuItem user_menu[];


int main() {
    main_system vokz;

    //test_user_func(vokz);

    DB_ID operation;

    //for(int i = 0; i < 10; ++i){
        //add_new_route(vokz);
        //add_new_train(vokz);
        //add_new_trip(vokz);
   // }


    MenuItem main_system_menu[] = {
            {
                    .caption { "Admin menu" },
                    .cmd{"admin"},
                    .next {admin_menu},
                    .description {"menu for Good"}
            },
            {
                    .caption { "User menu"},
                    .cmd { "user" },
                    .next {user_menu},
                    .description  {"menu for usual person"}
            },{}
    };

   draw_menu("System", main_system_menu, " * Main menu * ", vokz);


    std::cout << "\n|--------------------------|";
    std::cout << "\n|***   Work finished    ***|";
    std::cout << "\n|--------------------------|\n";

    return 0;
}


