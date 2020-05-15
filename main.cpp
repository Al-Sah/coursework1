#include <iostream>
#include <string>
#include <cstring>

#include "class_main_system.h"
#include "class_ticket.h"
#include "class_train.h"

#include "user_functions.h"

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
        int st_numb = rand() % 10;
        rt.setId(vokzal.next_route_id());
        for(int j = 1; j < st_numb; ++j){
            rt.addStation(j);
        }
        vokzal.add_route(rt);
    }
}

void test_user_func(main_system & vokzal){

    //std::cout << "\ncheck trip functions\n";

    //add_new_trip(vokzal);

    std::cout << "\ncheck station functions\n";
    add_new_station(vokzal);
    get_station_list(vokzal);
    edit_station( vokzal);
    delete_station(vokzal);
    get_station_information(vokzal);

    std::cout << "\n\ncheck route functions\n\n";
    add_new_route(vokzal);
    //edit_route(vokzal);
    delete_route(vokzal);
    get_route_information(vokzal);

    std::cout << "\n\ncheck train functions\n\n";
    add_new_train(vokzal);
    edit_train(vokzal);
    delete_ticket(vokzal);
    get_train_information(vokzal);

    std::cout << "\n\ncheck passenger functions\n\n";
    get_passenger_list(vokzal);
    set_new_passenger(vokzal);
    edit_passenger( vokzal);
    delete_passenger(vokzal);
    get_passenger_information(vokzal);

}


int main() {
    std::cout << "Hello, World!" << std::endl;

    main_system vokz;

    generation_data(vokz);
    test_user_func(vokz);

    return 0;
}

