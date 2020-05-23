#include <iostream>
#include <string>
#include <cstring>

#include "class_main_system.h"
#include "user_functions.h"
#include "user_menus.h"

void generation_data(main_system & vokzal) {



    std::cout << "next ticket id: " << vokzal.next_ticket_id() << std::endl;
    std::cout << "next train id: " << vokzal.next_train_id() << std::endl;
    std::cout << "next station id: " << vokzal.next_station_id() << std::endl;
    std::cout << "next route id: " << vokzal.next_route_id() << std::endl;
    std::cout << "next passenger id: " << vokzal.next_passenger_id() << std::endl;

    for (auto i = 0; i < 10; i++) {
        train t;
        t.setId(vokzal.next_train_id());
        t.setWagons(2);
        t.setWagonPlaces(10);
        vokzal.add_train(t);
    }

     for (auto i = 0; i < 10; i++) {
        ticket z;
        z.setId(vokzal.next_ticket_id());
        if((i % 2) != 0){
        z.setState(ticket::SOLD);
        }else{
            z.setState(ticket::USED);
        }
        z.setYourWagon(5);
        z.setPlaceNumber(i+i*10);
        z.setPrice( 1000 );
        z.setTripId(80021);
        z.setArrivalStationId(101);
        z.setDepartureStationId(121);
        z.setPassengerName("Василий_і_і");
        vokzal.add_ticket(z);
    }

     for (auto i = 0; i < 10; i++){
         passenger ps;
         ps.setId(vokzal.next_passenger_id());
         ps.setSurname("Корявый");
         ps.setFirstName("Олег");
         ps.setFatherName("Петрович");
         ps.setFullName();
         vokzal.add_passenger(ps);
     }


    for (auto i = 0; i < 10; i++) {

        station st;
        st.setId(vokzal.next_station_id());
        st.setName("Мальдивы_fff_i");

        vokzal.add_station(st);
    }
    for (auto i = 0; i < 10; i++) {
        srand(time(NULL));
        route rt;
        int st_numb = rand() % 15;
        rt.setId(vokzal.next_route_id());
        for(int j = 1; j < st_numb; ++j){
            rt.addStation(j);
        }
        vokzal.add_route(rt);
    }
}

void test_user_func(main_system & vokzal){

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

    //generation_data(vokz);
    //test_user_func(vokz);


    DB_ID operation;

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
            },
            { }
    };

   draw_menu("System", main_system_menu, " * Main menu * ", vokz);





    do {
        std::cout <<"\nEnter 0 to finish work\nEnter 1 if you an administrator\nEnter 2 if you a passenger\nInput:";
        operation = operation_check();
        switch (operation) {
            case 0:
                std::cout << "\n|--------------------------|";
                std::cout << "\n|***   Work finished    ***|";
                std::cout << "\n|--------------------------|\n";
                break;
            case 1:
                admin_switch(vokz);
                break;
            default:
                std::cout<<"Wrong options, try again";
        }
    }while (operation != 0 );

    return 0;
}


