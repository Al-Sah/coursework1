#include <iostream>
#include <string>
#include <cstring>

#include "class_main_system.h"
#include "class_ticket.h"
#include "class_train.h"

#include "user_functions.h"

void front_end(main_system & vokzal) {



    std::cout << "next ticket id: " << vokzal.next_ticket_id() << std::endl;
    std::cout << "next train id: " << vokzal.next_train_id() << std::endl;
    std::cout << "next station id: " << vokzal.next_station_id() << std::endl;
    std::cout << "next route id: " << vokzal.next_route_id() << std::endl;
    std::cout << "next passenger id: " << vokzal.next_passenger_id() << std::endl;

    for (auto i = 0; i < 10; i++) {
        train t;
        t.setId(vokzal.next_train_id());
        t.setWagons(10);
        t.setWagonPlaces(50);
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
         ps.setEMail("me@gmail.com");
         ps.setPassword("hrp324+-F!g");
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

    add_new_station(vokzal);
    edit_station( vokzal);
    delete_station(vokzal);
    get_station_information(vokzal);
    edit_ticket(vokzal);


}

void add_t(main_system & vokzal) {
    std::cout << " Добавить билет\n";
    int temp_val;
    ticket z;

    z.setId(vokzal.next_ticket_id());
    std::cout << "ввод ";
    std::cin >> temp_val;
    z.setPassengerName("Коля");
    z.setState(static_cast<ticket::STATUS>(temp_val));
    vokzal.add_ticket(z);
    std::cout << z << " ";
}


int main() {
    std::cout << "Hello, World!" << std::endl;

    main_system vokz;

    front_end(vokz);
    test_user_func(vokz);
 //   add_t(vokz);


    return 0;
}

