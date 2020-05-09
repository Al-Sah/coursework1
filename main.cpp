#include <iostream>
#include <string>
#include <cstring>

#include "class_main_system.h"
#include "class_ticket.h"
#include "class_train.h"

#include "utils.h"

void front_end(main_system & vokzal) {



    std::cout << "next ticket id: " << vokzal.next_ticket_id() << std::endl;
    std::cout << "next train id: " << vokzal.next_train_id() << std::endl;
    std::cout << "next station id: " << vokzal.next_station_id() << std::endl;

    for (auto i = 0; i < 10; i++) {
        train t;
        t.setId(vokzal.next_train_id());
        t.setWagons(10);
        t.setWagonPlaces(50);
        vokzal.add_train(t);
    }
my_dbg("train ok");
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
        z.setPassengerName("Василий");
        vokzal.add_ticket(z);
    }
    my_dbg("tickets ok");

    for (auto i = 0; i < 10; i++) {

        //add_new_station(vokzal);

        station st;
        st.setId(vokzal.next_station_id());
        st.setName("Мальдивы_fff_i");

        vokzal.add_station(st);
    }
    my_dbg("stations ok");
    get_station_information(vokzal);
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
    my_dbg("routes ok");

    //add_new_route(vokzal);
    //delete_station( vokzal);
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
 //   add_t(vokz);


    return 0;
}

