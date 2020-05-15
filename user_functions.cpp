//
// Created by al_sah on 03.05.20.
//

#include "user_functions.h"
#include "utils.h"
#include <iostream>


void check_route_exist(main_system &sys, DB_ID &id) {
    bool is_ok;
    route route;
    do {
        is_ok = true;
        std::cout << "Enter route id: ";
        input_id_check(id);
        try {
            route= sys.Get_route_info(id);
        } catch (char const *err) {
            std::cout << "err: " << err << std::endl;
            is_ok = false;
        }
    }while (!is_ok);
}

void check_train_exist(main_system &sys, DB_ID &id) {
    bool is_ok;
    train train;
    do {
        is_ok = true;
        std::cout << "Enter train id: ";
        input_id_check(id);
        try {
            train = sys.Get_train_info(id);
        } catch (char const *err) {
            std::cout << "err: " << err << std::endl;
            is_ok = false;
        }
    }while (!is_ok);
}

void check_station_exist(main_system &sys, DB_ID &id) {
    bool is_ok;
    station station;
    do {
        is_ok = true;
        std::cout << "Enter station id: ";
        input_id_check(id);
        try {
            station = sys.Get_station_info(id);
        } catch (char const *err) {
            std::cout << "err: " << err << std::endl;
            is_ok = false;
        }
    }while (!is_ok);
}



// ** station Functions **     --------------------------------


void get_station_information(main_system &sys, DB_ID st_id){
    station st;
    st = sys.Get_station_info(st_id);
    std::cout << "Station id: " << st.getId() << "\nStation name: " << st.getName();
}

/**
 * получает от пользователя идентификатор станции для отображения
 * @param sys - Вокзал
 */

void get_station_information(main_system &sys){
    std::cout << "\n*** Get station info ***\n";
    DB_ID st_id = get_object_id("Enter station id which info you want to see: ");
    try {
        get_station_information(sys, st_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}

void set_station_information(station &new_st) {
    std::string name;
    name = ask_user("\nEnter new station name: ");
    new_st.setName(name);
}


void get_station_list(main_system &sys){
    std::cout << "\n*** Get station list ***";
    std::vector<station> stations;
    stations = sys.Get_station_vector();
    std::cout << "\nid station name\n";
    for(auto station : stations){
        std::cout << station;
    }
}

void add_new_station(main_system &sys)  {
    std::cout << "\n*** Creating new station ***";
    station new_st;
    set_station_information( new_st);
    sys.add_station(new_st);
}

void edit_station(main_system &sys) {
    std::cout << "\n*** Edit station ***\n";
    DB_ID st_id = get_object_id("Enter station id which info you want to edit: ");
    station new_st;
    try {
        new_st = sys.Get_station_info(st_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
    std::cout << "Old station information:\n";
    get_station_information(sys, st_id);
    set_station_information(new_st);
    sys.edit_station(new_st, st_id);
}


void delete_station(main_system &sys){
    std::cout << "\n*** Delete station ***\n";
    DB_ID st_id = get_object_id("Enter station id which will be deleted: ");
    try {
        delete_station(sys, st_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }

}

void delete_station(main_system &sys, DB_ID st_id){
    sys.delete_station(st_id);
}


//ticket functions


void get_ticket_information(main_system &sys, DB_ID ticket_id){
    ticket tic;
    tic = sys.Get_ticket_info(ticket_id);
    std::cout << tic;
}

void get_ticket_information(main_system &sys){
    DB_ID tic_id = get_object_id("Enter ticket id which info you want to see: ");
    try {
        get_ticket_information(sys, tic_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}
void set_ticket_information(ticket &new_ticket){
    std::string name, surname, father_name, full_passenger_name;

    std::cout << "Enter passenger name: ";         std::cin >> name;
    std::cout << "Enter passenger surname: ";      std::cin >> surname;
    std::cout << "Enter passenger father_name: ";  std::cin >> father_name;
    full_passenger_name = surname + "_" + name + "_" + father_name;
    new_ticket.setPassengerName(full_passenger_name);

//TODO Логику для админа и обычного пользователя
}

void add_default_ticket(main_system &sys, size_t wagon, size_t wg_place, DB_ID trip_id ) {
    ticket ticket;
    ticket.setPassengerName("NONAME");
    ticket.setState(ticket::FREE);
    ticket.setYourWagon(wagon);
    ticket.setPlaceNumber(wg_place);
    ticket.setDepartureStationId(0);
    ticket.setArrivalStationId(0);
    ticket.setPrice(55.5);
    ticket.setTripId(trip_id);
    sys.add_ticket(ticket);
}
void get_ticket_list(main_system &sys) {
    std::cout << "\n*** Get ticket list ***";
    std::vector<ticket> tickets;
    tickets = sys.Get_ticket_vector();
    std::cout << "\nid ------------------\n";
    for(auto ticket : tickets){
        std::cout << ticket;
    }
}


void edit_ticket(main_system &sys){
    DB_ID tic_id = get_object_id("Enter ticket id which info you want to edit: ");
    ticket new_tic;
    try {
        new_tic = sys.Get_ticket_info(tic_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
    std::cout << "Old ticket information: ";
    get_ticket_information(sys, tic_id);
    set_ticket_information(new_tic);
    sys.edit_ticket(new_tic, tic_id);
}


void delete_ticket(main_system &sys){
    DB_ID ticket_id = get_object_id("Enter ticket id which will be deleted:  ");
    try {
        delete_ticket(sys, ticket_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}
void delete_ticket(main_system &sys, DB_ID ticket_id){
    sys.delete_ticket(ticket_id);
}



void add_new_route(main_system &sys){
    std::cout << "\n*** Creating new route ***";
    route new_route;
    set_route_information(new_route);
    sys.add_route(new_route);
}

void set_route_information(route &route) {
    int operation;
    DB_ID station_id, station_counter;
    set_info_route_help();

    do{
        std::cout << "\nВведите номер операции: ";
        operation_check(operation);

        switch (operation) {
            case 0:
                std::cout << "\n*** Setting information finished ***\n";
                break;
            case 1:
                std::cout << "Enter station id: ";
                std::cin >> station_id;
                route.addStation(station_id);
                break;
            case 2:
                std::cout << "Enter number of station: ";
                std::cin >> station_counter;
                for(size_t i = 0; i < station_counter; ++i){
                    std::cout << "Enter station id: ";
                    std::cin >> station_id;
                    route.addStation(station_id);
                }
                break;
            case 3:
                std::cin >> station_id;
                route.deleteStation(station_id);
                break;
            case 4:
                std::cin >> station_id;
                break;
            default:
                std::cout << "Такой операции нет";
                break;
        }
    } while (operation != 0);

}
void get_route_list(main_system &sys) {
    std::cout << "\n*** Get route list ***";
    std::vector<route> routes;
    routes = sys.Get_route_vector();
    std::cout << "\nid stations station_ids \n";
    for(auto route : routes){
        std::cout << route;
    }
}

void get_route_information(main_system &sys){
    DB_ID route_id = get_object_id("Enter route id which info you want to see: ");
    try {
        get_route_information(sys, route_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}
void get_route_information(main_system &sys, DB_ID route_id){
    route route;
    route = sys.Get_route_info(route_id);
    std::cout << route;
}

void delete_route(main_system &sys,  DB_ID route_id){
    sys.delete_route(route_id);
}


void delete_route(main_system &sys) {
    DB_ID route_id = get_object_id("Enter route id which will be deleted:  ");
    try {
        delete_route(sys,route_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}


void get_route_stations(main_system &sys, DB_ID route_id) {
    std::cout << "\n*** Get route stations ***";
    route route;
    //route.getStations();

    }


void edit_route(main_system &sys){
    DB_ID route_id = get_object_id("Enter route id which info you want to edit: ");
    route new_route;
    try {
        new_route = sys.Get_route_info(route_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
    std::cout << "Old station info: ";
    get_route_information(sys, route_id);
    set_route_information(new_route);
    sys.edit_route(new_route, route_id);
}


// **  train functions  **     --------------------------------

void get_train_information(main_system &sys){
    DB_ID train_id = get_object_id("Enter train id which info you want to see: ");
    try {
        get_train_information(sys, train_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}

void get_train_information(main_system &sys, DB_ID train_id) {
    train train;
    train = sys.Get_train_info(train_id);
    std::cout << train;
}

void set_train_information(train &train) {
    unsigned int counter;
    std::cout << "\nEnter number of wagons: " ; std::cin >> counter; train.setWagons(counter);
    std::cout << "\nEnter number of places in wagons: " ; std::cin >> counter; train.setWagonPlaces(counter);
    train.setTotalPlaces();

}

void get_train_list(main_system &sys) {
    std::cout << "\n*** Get train list ***";
    std::vector<train> trains;
    trains = sys.Get_train_vector();
    std::cout << "\nid stations station_ids \n";
    for(auto train : trains){
        std::cout << train;
    }
}

void edit_train(main_system &sys){
    DB_ID tr_id = get_object_id("Enter train id which info you want to edit: ");
    train new_train;
    try {
        new_train = sys.Get_train_info(tr_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
    std::cout << "Old train information: ";
    get_train_information(sys, tr_id);
    set_train_information(new_train);
    sys.edit_train(new_train, tr_id);

}

void add_new_train(main_system &sys){
    std::cout << "\n*** Creating new train ***\n";
    train new_tr;
    set_train_information(new_tr);
    sys.add_train(new_tr);

}
void delete_train(main_system &sys){
    DB_ID train_id = get_object_id("Enter train id which will be deleted:  ");
    try {
        delete_train(sys,train_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}

void delete_train(main_system &sys, DB_ID train_id){
    sys.delete_train(train_id);
}



// **  passenger functions  **     --------------------------------

void set_new_passenger(main_system &sys) {
    std::cout << "\n*** Set passenger full_name ***\n";
    passenger passenger;
    set_passenger_information(passenger);
    sys.add_passenger(passenger);
}

void delete_passenger(main_system &sys) {
    std::cout << "\n*** Delete passenger ***\n";
    DB_ID passenger_id = get_object_id("Enter passenger id which will be deleted:  ");
    try {
        delete_passenger(sys,passenger_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}

void delete_passenger(main_system &sys, DB_ID passenger_id) {
    sys.delete_passenger(passenger_id);
}

void edit_passenger(main_system &sys) {
    std::cout << "\n*** Edit passenger ***\n";
    DB_ID passenger_id = get_object_id("Enter passenger id which info you want to edit: ");
    passenger passenger;
    try {
        passenger = sys.Get_passenger_info(passenger_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
    std::cout << "Old passenger information: ";
    get_passenger_information(sys, passenger_id);
    set_passenger_information(passenger);
    sys.edit_passenger(passenger, passenger_id);
}

void get_passenger_list(main_system &sys) {
    std::cout << "\n*** Get passenger list ***";
    std::vector<passenger> passengers;
    passengers = sys.Get_passenger_vector();
    std::cout << "\nid passenger  full name\n";
    for(auto passenger : passengers){
        std::cout << passenger;
    }
}

void get_passenger_information(main_system &sys) {
    DB_ID passenger_id = get_object_id("Enter passenger id which info you want to see: ");
    try {
        get_passenger_information(sys, passenger_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}

void get_passenger_information(main_system &sys, DB_ID passenger_id) {
    passenger passenger;
    passenger = sys.Get_passenger_info(passenger_id);
    std::cout <<
       "passenger id: " << passenger.getId() <<
    "\nPassenger full_name: " << passenger.getFullName();
}

void set_passenger_information(passenger &passenger) {

    std::string user_data;
    std::cout << "\nEnter passenger name: ";
    std::cin >> user_data;  passenger.setFirstName(user_data);
    std::cout << "Enter passenger surname: ";
    std::cin >> user_data;  passenger.setSurname(user_data);
    std::cout << "Enter passenger father_name: ";
    std::cin >> user_data;  passenger.setFatherName(user_data);
    passenger.setFullName();


}


// ** trip functions ****** ---=------------------------------------=


void generate_trip_tickets(main_system &sys, DB_ID train_id, DB_ID trip_id) {
    train train;
    train = sys.Get_train_info(train_id);
    ticket ticket;

    for(size_t wagons = 1; wagons <= train.getWagons(); ++wagons){
        for(size_t wagon_place = 1; wagon_place <= train.getWagonPlaces(); ++wagon_place){
            //FIXME: много раз перезапишется файл
            add_default_ticket(sys, wagons, wagon_place, trip_id);
        }
    }
}

void add_new_trip(main_system &sys) {
    std::cout << "\n*** Creating new trip ***";
    trip new_trip;
    set_trip_information(sys, new_trip);

    DB_ID trip_id = sys.add_trip(new_trip);
    generate_trip_tickets(sys, new_trip.getTrainId(), trip_id);
}

void delete_trip(main_system &sys) {
    std::cout << "\n*** Delete trip ***\n";
    DB_ID trip_id = get_object_id("Enter trip id which will be deleted: ");
    try {
        delete_trip(sys, trip_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}

void delete_trip(main_system &sys, DB_ID trip_id) {
    sys.delete_trip(trip_id);


}

void edit_trip(main_system &sys) {
    std::cout << "\n*** Edit trip ***\n";
    DB_ID trip_id = get_object_id("Enter trip id which info you want to edit: ");
    trip trip;
    try {
        trip = sys.Get_trip_info(trip_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
    std::cout << "Old trip information: ";
    get_trip_information(sys, trip_id);
    set_trip_information(sys,trip);
    sys.edit_trip(trip, trip_id);
}

void get_trip_list(main_system &sys) {
    std::cout << "\n*** Get trip list ***";
    std::vector<trip> trips;
    trips = sys.Get_trip_vector();
    std::cout << "\nid date platform route_id train_id\n";
    for(auto trip : trips){
        std::cout << trip;
    }
}

void get_trip_information(main_system &sys) {
    DB_ID trip_id = get_object_id("Enter trip id which info you want to see : ");
    try {
        get_trip_information(sys, trip_id);
    } catch (char const *err) {
        std::cout << "err: " << err << std::endl;
        return;
    }
}

void get_trip_information(main_system &sys, DB_ID trip_id) {
    trip trip;
    trip = sys.Get_trip_info(trip_id);
    std::cout  << trip;

}

void set_trip_information(main_system &sys, trip &trip) {
    DATE date;
    DB_ID temp_id = 0;

    std::cout << "\nEnter trip date ";
    input_date(date);
    trip.setDate(date);

    std::cout << "Enter platform: ";
    input_id_check(temp_id);
    trip.setPlatformId(temp_id);

    check_route_exist(sys, temp_id);
    trip.setRouteId(temp_id);

    check_train_exist(sys, temp_id);
    trip.setTrainId(temp_id);

}



void admin_switch(main_system &sys) {

    std::cout << "***** Welcome *****\nYou are an administrator of this system !";

    int operation;

    do {
        operation_check(operation);
        switch (operation) {
            case 0:
                std::cout << "\n|---------------------------------------------------|";
                std::cout << "\n|*** You have completed work as an administrator ***|";
                std::cout << "\n|---------------------------------------------------|\n";
                break;
            case 1:
                station_functions_switch(sys);
                break;
            case 2:
                break;
            default:
                std::cout<<"Wrong options, try again";
                break;
        }
    }while (operation != 0 );
}

void common_user_switch(main_system &sys) {


}

void station_functions_switch(main_system &sys) {

}




/*
 *
 * sta name => start sta id
 * sta name => end sta id
 * route list => trip list => trip id list
 *
 */