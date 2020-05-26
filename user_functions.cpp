//
// Created by al_sah on 03.05.20.
//

#include "user_functions.h"
#include "utils.h"
#include <iostream>
#include <iomanip>
#include <codecvt>

#define CLR_NORMAL "\033[0m"
#define CLR_RED "\033[31;1;1m"
#define CLR_GREEN "\033[32;1;1m"

#define CLR_black "\033[30m "
#define CLR_green "\033[32m"
#define CLR_yellow "\033[33m"
#define CLR_blue "\033[34m"
#define CLR_magenta "\033[35m"
#define CLR_cyan "\033[36m"
#define CLR_grey "\033[37m"



DB_ID ask_route_id_from_user(main_system &sys) {
    DB_ID id;
    bool is_ok;
    route route;
    do {
        is_ok = true;
        std::cout << "Enter route id: ";
        id = input_id_check();
        try {
            route= sys.Get_route_info(id);
        } catch (char const *err) {
            std::cout << CLR_RED "err: " << err << std::endl << CLR_NORMAL;
            is_ok = false;
        }
    }while (!is_ok);
    return id;
}

DB_ID ask_train_id_from_user(main_system &sys) {
    DB_ID id;
    bool is_ok;
    train train;
    do {
        is_ok = true;
        std::cout << "Enter train id: ";
        id = input_id_check();
        try {
            train = sys.Get_train_info(id);
        } catch (char const *err) {
            std::cout << CLR_RED "err: " << err << std::endl << CLR_NORMAL;
            is_ok = false;
        }
    }while (!is_ok);
    return id;
}

DB_ID ask_station_id_from_user(main_system &sys) {
    DB_ID id;
    bool is_ok;
    station station;
    do {
        is_ok = true;
        std::cout << "Enter station id: ";
        id = input_id_check();
        try {
            station = sys.Get_station_info(id);
        } catch (char const *err) {
            std::cout << CLR_RED "err: " << err << std::endl << CLR_NORMAL;
            is_ok = false;
        }
    }while (!is_ok);
    return id;
}

DB_ID ask_trip_id_from_user(main_system &sys) {
    DB_ID id;
    bool is_ok;
    trip trip;
    do {
        is_ok = true;
        std::cout << "Enter trip id: ";
        id = input_id_check();
        try {
            trip = sys.Get_trip_info(id);
        } catch (char const *err) {
            std::cout << CLR_RED "err: " << err << std::endl << CLR_NORMAL;
            is_ok = false;
        }
    }while (!is_ok);
    return id;
}


DB_ID ask_passenger_id_from_user(main_system &sys) {
    DB_ID id;
    bool is_ok;
    passenger passenger;
    do {
        is_ok = true;
        std::cout << "Enter passenger id: ";
        id = input_id_check();
        try {
            passenger = sys.Get_passenger_info(id);
        } catch (char const *err) {
            std::cout << CLR_RED "err: " << err << std::endl << CLR_NORMAL;
            is_ok = false;
        }
    }while (!is_ok);
    return id;
}


DB_ID ask_ticket_id_from_user(main_system &sys) {
    DB_ID id;
    bool is_ok;
    ticket ticket;
    do {
        is_ok = true;
        std::cout << "Enter ticket id: ";
        id = input_id_check();
        try {
            ticket = sys.Get_ticket_info(id);
        } catch (char const *err) {
            std::cout << CLR_RED "err: " << err << std::endl << CLR_NORMAL;
            is_ok = false;
        }
    }while (!is_ok);
    return id;
}

void db_info(main_system &sys) {

    std::cout << CLR_cyan"\n*** Get data base info ***\n\n" CLR_NORMAL;
    std::cout << " | Next ticket id:    " << sys.next_ticket_id()
    << std::endl << " | Number of tickets: " << sys.Get_ticket_vector_size() << std::endl;

    std::cout  << "\n | Next train id:    " << sys.next_train_id()
            << std::endl << " | Number of trains: " << sys.Get_train_vector_size() << std::endl;

    std::cout << "\n | Next station id:    " << sys.next_station_id()
            << std::endl << " | Number of stations: " << sys.Get_station_vector_size() << std::endl;

    std::cout << "\n | Next route id:    " << sys.next_route_id()
            << std::endl << " | Number of routes: " << sys.Get_route_vector_size() << std::endl;

    std::cout <<"\n | Next trip id:    " << sys.next_trip_id()
            << std::endl << " | Number of trips: " << sys.Get_trip_vector_size() << std::endl;
}


// ** station Functions **     --------------------------------

DB_ID find_station_by_name(main_system &sys) {
    std::cout << "\n*** Find station by name ***\n";
    DB_ID station_id;
    std::string station_name;
    std::vector<station> stations;
    stations = sys.Get_station_vector();
    bool is_ok ;
    do{
        is_ok = false;
        std::cout << "Enter station name: ";
        std::cin >> station_name;
        for(const auto& station: stations){
            if(station.getName() == station_name){
                station_id = station.getId();
                is_ok = true;
                break;
            }
        }
        if(!is_ok){
            std::cout<< CLR_RED "Station not found, try again\n" CLR_NORMAL;
        }
    }while (!is_ok);

    return station_id;
}


std::vector<std::string> get_names_from_stations(main_system &sys, const std::vector<station>& stations) {
    std::vector<std::string> stations_names;
    stations_names.reserve(stations.size());
    for(const auto& station: stations){
        stations_names.push_back(station.getName());
    }
    return stations_names;
}





void get_station_information(main_system &sys, DB_ID st_id){
    station st;
    st = sys.Get_station_info(st_id);
    std::cout << "Station id:   " << st.getId() << "\nStation name: " << st.getName();
}

/**
 * получает от пользователя идентификатор станции для отображения
 * @param sys - Вокзал
 */

void get_station_information(main_system &sys){
    std::cout << CLR_cyan"\n    *** Get station info ***\n" CLR_NORMAL"What station id which info you want to see\n";
    DB_ID station_id = ask_station_id_from_user(sys);
    get_station_information(sys, station_id);
}

void set_station_information(station &new_st) {
    std::string name;
    name = ask_user("\nEnter new station name: " );
    new_st.setName(name);
}


void get_station_list(main_system &sys){
    std::cout << CLR_cyan "\n    *** Get station list ***" CLR_NORMAL;
    std::vector<station> stations;
    stations = sys.Get_station_vector();
    std::cout << "\nid station name\n";
    for(auto station : stations){
        std::cout << station;
    }
}

void add_new_station(main_system &sys)  {
    std::cout << CLR_cyan"\n    *** Creating new station ***" CLR_NORMAL;
    station new_st;
    set_station_information( new_st);
    sys.add_station(new_st);
}

void edit_station(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Edit station ***\n" CLR_NORMAL"What station id which info you want to edit\n";
    DB_ID station_id = ask_station_id_from_user(sys);
    station new_st;
    new_st = sys.Get_station_info(station_id);
    std::cout << "Old station information:\n";
    get_station_information(sys, station_id);
    set_station_information(new_st);
    sys.edit_station(new_st, station_id);
}


void delete_station(main_system &sys){
    std::cout << CLR_cyan"\n    *** Delete station ***\n" CLR_NORMAL"Enter station id which will be deleted\n";
    DB_ID station_id = ask_station_id_from_user(sys);
    delete_station(sys, station_id);

    std::vector<route> routes;
    std::vector<DB_ID> station_ids;
    routes = sys.Get_route_vector();
    std::cout << CLR_RED"\nWarning ! Station will be deleted from routes\n" CLR_NORMAL;
    for(auto& route: routes){
        station_ids = route.getStationIds();
        for(auto station_route_id: station_ids)
        if(station_route_id == station_id){
            route.deleteStation(station_id);
            continue;
        }
    }
}

void delete_station(main_system &sys, DB_ID st_id){
    sys.delete_station(st_id);
}


//ticket functions


void get_ticket_information(main_system &sys, DB_ID ticket_id){
    ticket ticket;
    ticket = sys.Get_ticket_info(ticket_id);
    std::cout
            << "\nTicket id: " << ticket.getId()
            << "\nTrip id: " << ticket.getTripId()
            << "\nState: " << ticket.getState()
            << "\nPrice: " << ticket.getPrice()
            << "\nWagon: " << ticket.getYourWagon()
            << "\nWg place: " << ticket.getPlaceNumber()
            << "\nDeparture station id: " << ticket.getDepartureStationId()
            << "\nArrival station id: " << ticket.getArrivalStationId()
            << "\nPassenger full name: " << ticket.getPassengerName();
}

void get_ticket_information(main_system &sys){
    std::cout << CLR_cyan"\n    *** Get ticket information***\n" CLR_NORMAL"Enter ticket id which info you want to see\n";
    DB_ID tic_id = ask_ticket_id_from_user(sys);
    get_ticket_information(sys, tic_id);

}
void buying_ticket(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Buying ticket ***\n" CLR_NORMAL;
    ticket ticket;
    std::vector<DB_ID> good_routes;
    DB_ID arrival_station, departure_station, trip_id;
    DATE date;
    std::cout << "\nFirstly enter arrival station and departure station\n";
    do {
         arrival_station = find_station_by_name(sys);
         departure_station = find_station_by_name(sys);

        good_routes = find_correct_routes_id_by_stations(sys, arrival_station, departure_station);
        if(good_routes.empty()){
            std::cout<< "No direct routes with such stations, change stations\n";
        }
    }while (good_routes.empty());

    bool is_ok;
    do {
        is_ok = true;
        date = ask_user_date();
        try {
            trip_id = find_correct_trip_id(sys, date, good_routes);
        } catch (char const *err) {
            std::cout << "err: " << err << std::endl;
            is_ok = false;
        }
        if(!is_ok){
            std::cout << "No trips with your date, choose another one\n";
        }
    }while (!is_ok);

    DB_ID ticket_id = find_correct_ticket(sys, trip_id);

    std::string passenger_name = ask_passenger_name();

    ticket = sys.Get_ticket_info(ticket_id);
    ticket.setState(ticket::SOLD);
    ticket.setArrivalStationId(arrival_station);
    ticket.setDepartureStationId(departure_station);
    ticket.setPassengerName(passenger_name);

    sys.edit_ticket(ticket, ticket_id);
    get_ticket_information(sys, ticket_id);

}
DB_ID find_correct_trip_id(main_system &sys, DATE date, std::vector<DB_ID> &good_routes) {

    std::vector<trip> trips;
    trips = sys.Get_trip_vector();
    DB_ID trip_id = -1;

    for(const auto& trip : trips){
       if(trip.getDate() == date){
           for(auto i: good_routes){
               if( trip.getRouteId() == i){
                   trip_id = trip.getId();
                   break;
               }
           }
       }
    }
    if(trip_id == NOT_FOUND){
        throw "Object not found";
    }
    return trip_id;
}


std::string ask_passenger_name() {
    std::string name, surname, father_name, full_passenger_name;

    std::cout << "Enter passenger name: ";         std::cin >> name;
    std::cout << "Enter passenger surname: ";      std::cin >> surname;
    std::cout << "Enter passenger father_name: ";  std::cin >> father_name;
    full_passenger_name = surname + "_" + name + "_" + father_name;
    return full_passenger_name;
}


DB_ID find_correct_ticket(main_system &sys, DB_ID trip_id) {

    DB_ID ticket_id = 0;
    std::vector<ticket> trip_tickets, free_trip_tickets;
    trip_tickets = get_trip_tickets_list(sys, trip_id);

        for(const auto& ticket: trip_tickets){
            if(ticket.getState() == 0){
                free_trip_tickets.push_back(ticket);
            }
        }


    DB_ID operation;
    std::cout << "\n1)Choose random ticket \n2)Choose certain ticket\nEnter(1/2): ";

    do{operation = operation_check();
    }while(!(operation == 1 || operation == 2));


    if(operation == 1){
        for(const auto& ticket: free_trip_tickets){
            ticket_id = ticket.getId();
        }
    }
    else{
        for(const auto& ticket: free_trip_tickets){
            DB_ID t_id = ticket.getId();
            get_ticket_information(sys, t_id);
        }
        bool is_ok;
        do {
            is_ok = false;
            std::cout << "Enter ticket id\n";
            ticket_id = ask_ticket_id_from_user(sys);
            for (const auto& ticket: free_trip_tickets) {
                if (ticket_id == ticket.getId()) {
                    is_ok = true;
                }
            }
            if(!is_ok){
                std::cout<< "Try again\n";
            }
        }while (!is_ok);
    }
    return ticket_id;
}

std::vector<ticket> get_trip_tickets_list(main_system &sys, DB_ID trip_id) {

    std::vector<ticket> tickets, trip_tickets;
    tickets = sys.Get_ticket_vector();
    for(const auto& ticket: tickets){
        if(ticket.getTripId() == trip_id){
            trip_tickets.push_back(ticket);
        }
    }
    return trip_tickets;
}


void set_ticket_information(main_system &sys, ticket &new_ticket){

    std::string full_passenger_name = ask_passenger_name();
    new_ticket.setPassengerName(full_passenger_name);

    new_ticket.setState(ticket::SOLD);

    DB_ID arrival_station = ask_station_id_from_user(sys);
    new_ticket.setArrivalStationId(arrival_station);

    DB_ID departure_station = ask_station_id_from_user(sys);
    new_ticket.setDepartureStationId(departure_station);

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
    std::cout << CLR_cyan"\n    *** Get ticket list ***" CLR_NORMAL;
    std::vector<ticket> tickets;
    tickets = sys.Get_ticket_vector();
    std::cout << "\nid ------------------\n";
    for(auto ticket : tickets){
        std::cout << ticket;
    }
}


void edit_ticket(main_system &sys){
    std::cout << CLR_cyan"\n    *** Edit ticket ***\n" CLR_NORMAL"Enter ticket id which info you want to edit\n";
    DB_ID tic_id = ask_ticket_id_from_user(sys);
    ticket new_tic;
    new_tic = sys.Get_ticket_info(tic_id);
    std::cout << "Old ticket information: ";
    get_ticket_information(sys, tic_id);
    set_ticket_information(sys,new_tic);
    sys.edit_ticket(new_tic, tic_id);
}


void delete_ticket(main_system &sys){
    std::cout << CLR_cyan"\n   *** Delete ticket ***\n" CLR_NORMAL"Enter ticket id which will be deleted\n";
    DB_ID ticket_id = ask_ticket_id_from_user(sys);
    delete_ticket(sys, ticket_id);
}
void delete_ticket(main_system &sys, DB_ID ticket_id){
    sys.delete_ticket(ticket_id);
}


// route functions ****


std::vector<DB_ID> find_correct_routes_id_by_stations(main_system &sys, DB_ID arrival_station, DB_ID departure_station) {

    std::vector<route> routes;
    std::vector<DB_ID> station_ids, good_routes;
    routes = sys.Get_route_vector();

    bool station_found;
    for(auto& route: routes) {
        station_found = false;
        station_ids = route.getStationIds();
        for (auto station_route_id: station_ids) {
            if (station_route_id == arrival_station) {
                station_found = true;
            }
            else if (station_route_id == departure_station){
                if(!station_found){
                    continue;
                }else{
                    good_routes.push_back(route.getId());
                }
            }
        }
    }
    return good_routes;
}

std::vector<DB_ID> route_arrival_station_and_departure_station_ids(main_system &sys) {
    std::cout << CLR_cyan"\n    *** get route arrival station and departure station ***" CLR_NORMAL;
    DB_ID route_id = ask_route_id_from_user(sys);
    return route_arrival_station_and_departure_station_ids(sys, route_id);
}

std::vector<DB_ID> route_arrival_station_and_departure_station_ids(main_system &sys, DB_ID route_id) {
    route route;
    route = sys.Get_route_info(route_id);
    std::vector<DB_ID> route_stations, arr_and_dep_st_ids;
    route_stations = route.getStationIds();
    arr_and_dep_st_ids.push_back(route_stations[0]);
    arr_and_dep_st_ids.push_back(route_stations[route_stations.size() - 1]);
    return arr_and_dep_st_ids;
}
std::vector<station> route_arrival_station_and_departure_station(main_system &sys, DB_ID route_id){
    route route;
    route = sys.Get_route_info(route_id);
    std::vector<station> route_stations, arr_and_dep_stations;
    route_stations = route.getStations(&sys);

    arr_and_dep_stations.push_back(route_stations[0]);
    arr_and_dep_stations.push_back(route_stations[route_stations.size() - 1]);

    return arr_and_dep_stations;
}

void add_new_route(main_system &sys){
    std::cout << CLR_cyan"\n   *** Creating new route ***" CLR_NORMAL;
    route route, revers_route;
    std::vector<DB_ID> st_ids;
    set_route_information(sys, route);
    sys.add_route(route);

    std::cout << "Add reverse route?";
    std::cout << "\n1)Yes\n2)No\nEnter(1/2): ";
    int operation;
    do {
        operation = operation_check();
    } while (!(operation == 1 || operation == 2));

    if(operation == 1){
        st_ids = route.getStationIds();
        std::reverse( st_ids.begin(), st_ids.end() );
        for(auto st_id: st_ids){
            revers_route.addStation(st_id);
        }
        sys.add_route(revers_route);
    }else{
        return;
    }
}

void set_route_information(main_system &sys,route &route) {

    DB_ID station_id, station_counter, operation;
    set_info_route_help();
    std::vector<DB_ID>station_ids;
    station_ids = route.getStationIds();

    do{
        std::cout << "\nEnter operation: ";
        operation = operation_check();

        switch (operation) {
            case 0:
                std::cout << "\n*Setting information finished\n";
                break;
            case 1:
                station_id = ask_station_id_from_user(sys);
                route.addStation(station_id);
                break;
            case 2:
                std::cout << "Enter number of station: ";
                std::cin >> station_counter;
                for(size_t i = 0; i < station_counter; ++i){
                    station_id = ask_station_id_from_user(sys);
                    route.addStation(station_id);
                }
                break;
            case 3:
                station_id = ask_station_id_from_user(sys);
                route.deleteStation(station_id);
                break;
            default:
                std::cout << "Wrong operation";
                break;
        }
    } while (operation != 0);

}
void get_route_list(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Get route list ***" CLR_NORMAL;
    std::vector<route> routes;
    routes = sys.Get_route_vector();
    std::cout << "\nid stations station_ids \n";
    for(auto route : routes){
        std::cout << route;
    }
}

void get_route_information(main_system &sys){
    std::cout << "\n    *** Get route info***\n" CLR_NORMAL"Enter route id which info you want to see\n";
    DB_ID route_id = ask_route_id_from_user(sys);
    get_route_information(sys, route_id);
}
void get_route_information(main_system &sys, DB_ID route_id){
    route route;
    route = sys.Get_route_info(route_id);
    std::vector<DB_ID> st_ids;
    st_ids = route.getStationIds();
    std::cout
        <<"\nRoute id: " << route.getId()
        <<"\nNumber of stations: " << route.getStationsNumber()
        <<"\nStation ids in route: ";
    for(auto id: st_ids){
        std::cout << id << " ";
    }

}

void delete_route(main_system &sys,  DB_ID route_id){
    sys.delete_route(route_id);
}


void delete_route(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Deleting route ***\n" CLR_NORMAL"Enter route id which will be deleted\n";
    DB_ID route_id = ask_route_id_from_user(sys);
    delete_route(sys,route_id);
}
void get_route_stations(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Get route stations ***\n" CLR_NORMAL;
    DB_ID route_id = ask_route_id_from_user(sys);
    get_route_stations(sys, route_id);
}


void get_route_stations(main_system &sys, DB_ID route_id) {
    route route;
    route = sys.Get_route_info(route_id);
    std::string sep;
    for(const auto& station : route.getStations(&sys)){
        std::cout << sep << station.getName() ;
        sep = " -> ";
    }
}


void edit_route(main_system &sys){
    std::cout << CLR_cyan"\n    *** Edit route ***\n" CLR_NORMAL"What route id which info you want to edit\n";
    DB_ID route_id = ask_route_id_from_user(sys);
    route new_route;
    new_route = sys.Get_route_info(route_id);
    std::cout << "Old station info: ";
    get_route_information(sys, route_id);
    set_route_information(sys, new_route);
    sys.edit_route(new_route, route_id);
}


// **  train functions  **     --------------------------------

void get_train_information(main_system &sys){
    std::cout << CLR_cyan "\n    *** Edit route ***\n" CLR_NORMAL"What train id which info you want to see\n";
    DB_ID train_id = ask_train_id_from_user(sys);
    get_train_information(sys, train_id);
}

void get_train_information(main_system &sys, DB_ID train_id) {
    train train;
    train = sys.Get_train_info(train_id);
    std::cout
    << "\nTrain id: " << train.getId()
    << "\nWagons: " << train.getWagons()
    << "\nPlaces in wagon: " << train.getWagonPlaces()
    << "\nTotal places: " << train.getTotalPlaces();

}

void set_train_information(train &train) {
    DB_ID counter;
    std::cout << "Enter number of wagons: " ; std::cin >> counter; train.setWagons(counter);
    std::cout << "Enter number of places in wagons: " ; std::cin >> counter; train.setWagonPlaces(counter);
    train.setTotalPlaces();

}

void get_train_list(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Get train list ***" CLR_NORMAL;
    std::vector<train> trains;
    trains = sys.Get_train_vector();
    std::cout << "\nid stations station_ids \n";
    for(auto train : trains){
        std::cout << train;
    }
}

void edit_train(main_system &sys){
    std::cout << CLR_cyan"\n    *** Edit train ***\n" CLR_NORMAL"Enter train id which will be deleted\n";
    DB_ID train_id = ask_train_id_from_user(sys);
    train new_train;
    new_train = sys.Get_train_info(train_id);
    std::cout << "Old train information: ";
    get_train_information(sys, train_id);
    set_train_information(new_train);
    sys.edit_train(new_train, train_id);

}

void add_new_train(main_system &sys){
    std::cout <<CLR_cyan "\n    *** Creating new train ***\n" CLR_NORMAL;
    train new_tr;
    set_train_information(new_tr);
    sys.add_train(new_tr);

}

void delete_train(main_system &sys){
    std::cout << CLR_cyan"\n    *** Delete train ***\n" CLR_NORMAL"Enter train id which will be deleted\n";
    DB_ID train_id = ask_train_id_from_user(sys);
    delete_train(sys,train_id);
}

void delete_train(main_system &sys, DB_ID train_id){
    sys.delete_train(train_id);
}



// **  passenger functions  **     --------------------------------

void set_new_passenger(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Set passenger full_name ***\n" CLR_NORMAL;
    passenger passenger;
    set_passenger_information(passenger);
    sys.add_passenger(passenger);
}

void delete_passenger(main_system &sys) {
    std::cout << "\n    *** Delete passenger ***\n" CLR_NORMAL"Enter passenger id which will be deleted\n";
    DB_ID passenger_id = ask_passenger_id_from_user(sys);
    delete_passenger(sys,passenger_id);
}

void delete_passenger(main_system &sys, DB_ID passenger_id) {
    sys.delete_passenger(passenger_id);
}

void edit_passenger(main_system &sys) {
    std::cout << "\n    *** Edit passenger ***\n" CLR_NORMAL"Enter passenger id which info you want to edit\n";
    DB_ID passenger_id = ask_passenger_id_from_user(sys);
    passenger passenger;
    passenger = sys.Get_passenger_info(passenger_id);
    std::cout << "Old passenger information: ";
    get_passenger_information(sys, passenger_id);
    set_passenger_information(passenger);
    sys.edit_passenger(passenger, passenger_id);
}

void get_passenger_list(main_system &sys) {
    std::cout << "\n    *** Get passenger list ***";
    std::vector<passenger> passengers;
    passengers = sys.Get_passenger_vector();
    std::cout << "\nid  passenger full_name\n";
    for(auto passenger : passengers){
        std::cout << passenger;
    }
}

void get_passenger_information(main_system &sys) {
    std::cout << "\n    *** Get passenger information ***\n" CLR_NORMAL"Enter passenger id which info you want to see\n";
    DB_ID passenger_id = ask_passenger_id_from_user(sys);
    get_passenger_information(sys, passenger_id);
}

void get_passenger_information(main_system &sys, DB_ID passenger_id) {
    passenger passenger;
    passenger = sys.Get_passenger_info(passenger_id);
    std::cout <<"passenger id: " << passenger.getId() <<
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
    std::cout << CLR_cyan"\n    *** Creating new trip ***" CLR_NORMAL;
    trip new_trip;
    set_trip_information(sys, new_trip);

    DB_ID trip_id = sys.add_trip(new_trip);
    generate_trip_tickets(sys, new_trip.getTrainId(), trip_id);
}

void delete_trip(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Delete trip ***\n" CLR_NORMAL"What trip id which will be deleted\n";
    DB_ID trip_id = ask_trip_id_from_user(sys);
    std::cout << CLR_RED"\nWarning! All tickets which are connected to trip will be deleted\n" CLR_NORMAL;
    delete_trip(sys, trip_id);
    std::vector<ticket> tickets;
    tickets = sys.Get_ticket_vector();
    for(const auto& ticket: tickets){
        if(ticket.getTripId() == trip_id){
            sys.delete_ticket(ticket.getId());
            //FIXME: много раз перезапишется файл
        }
    }
}

void delete_trip(main_system &sys, DB_ID trip_id) {
    sys.delete_trip(trip_id);
}

void edit_trip(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Edit trip ***\n" CLR_NORMAL"What trip id which info you want to edit\n";
    trip trip;
    DB_ID trip_id = ask_trip_id_from_user(sys);

    trip = sys.Get_trip_info(trip_id);
    std::cout << "Old trip information: ";
    get_trip_information(sys, trip_id);

    std::cout << "**Input new info**\nEnter new trip date ";
    DATE date = ask_user_date();
    trip.setDate(date);

    std::cout << "Enter new platform: ";
    PLATFORM_ID platformId;
    platformId = input_id_check();
    trip.setPlatformId(platformId);

    sys.edit_trip(trip, trip_id);
}

void get_trip_list(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Get trip list ***" CLR_NORMAL;
    std::vector<trip> trips;
    trips = sys.Get_trip_vector();
    std::cout << "\nid date platform route_id train_id\n";
    for(auto trip : trips){
        std::cout << trip;
    }
}

void get_trip_information(main_system &sys) {
    std::cout << CLR_cyan"\n    *** Get trip info ***\n" CLR_NORMAL"Enter trip id which info you want to see\n";
    DB_ID trip_id = ask_trip_id_from_user(sys);
    get_trip_information(sys, trip_id);
}

void get_trip_information(main_system &sys, DB_ID trip_id) {
    trip trip;
    trip = sys.Get_trip_info(trip_id);
    std::cout
    << "\nTrip id:  " << trip.getId()
    << "\nDate:     " << trip.getDate()
    << "\nTime:     " << trip.getTime()
    << "\nPlatform: " << trip.getPlatformId()
    << "\nRoute id: " << trip.getRouteId()
    << "\nTrain id: " << trip.getTrainId();

}

void set_trip_information(main_system &sys, trip &trip) {

    std::cout << "\nEnter trip date ";
    DATE date = ask_user_date();
    std::cout << "\nEnter trip time ";
    TIME time = ask_user_time();
    trip.setDate(date);
    trip.setTime(time);

    std::cout << "Enter platform: ";
    PLATFORM_ID platformId = input_id_check();
    trip.setPlatformId(platformId);

    DB_ID route_id = ask_route_id_from_user(sys);
    trip.setRouteId(route_id);

    DB_ID train_id = ask_train_id_from_user(sys);
    trip.setTrainId(train_id);

}


std::vector<trip> trips_on_certain_date(main_system &sys) {

    unsigned int trip_counter = 0;

    std::vector<trip> trips, trips_to_the_date;
    trips = sys.Get_trip_vector();
    DATE date;

    std::cout << "\nEnter date";
    date = ask_user_date();

    for (const auto &trip : trips) {
        if (trip.getDate() == date) {
            trips_to_the_date.push_back(trip);
            trip_counter++;
        }
    }
    if (trips_to_the_date.empty()) {
        std::cout << "No trips to " << date << std::endl;
    } else {
        std::cout << "\n* " << trip_counter << " trips to the " << date << std::endl;
        int counter = 0;
        for (const auto &trip: trips_to_the_date) {
            ++counter;
            std::cout << "Trip number: (" << counter << ") ";
            get_trip_information(sys, trip.getId()); std::cout << std::endl;
        }
    }
    return trips_to_the_date;
}

void free_places_on_certain_trip(main_system &sys, const std::vector<trip>& trips_to_the_date, std::vector<ticket> trip_tickets){
    DB_ID trip_id;
    bool is_ok;
    std::cout << "\nEnter trip id which you interested in: ";
    do{
        trip_id = input_id_check();
        is_ok = false;
        for(const auto& trip: trips_to_the_date){
            if(trip.getId() == trip_id){
                is_ok = true;
            }
        }
        if(!is_ok){
            std::cout << "Entered wrong trip id (No object found), try again\n";
        }
    }while (!is_ok);

    trip_tickets = get_trip_tickets_list(sys, trip_id);
    int counter = 0;
    for(const auto& ticket: trip_tickets){
        if(ticket.getState() == 0){
            counter++;
        }
    }
    std::cout << "\n" << counter << " free tickets to the your trip\n";
}
void free_places_list(main_system &sys, DB_ID trip_id) {

    std::vector<ticket> trip_tickets, free_trip_tickets;
    trip_tickets = get_trip_tickets_list(sys, trip_id);

    for(const auto& ticket: trip_tickets){
        if(ticket.getState() == 0){
            free_trip_tickets.push_back(ticket);
        }
    }
    std::cout << "\n List of free places to trip " << trip_id << std::endl;
    for(const auto& ticket: free_trip_tickets){

        std::cout
                << "\nTicket id: " << ticket.getId()
                << "\nWagon: " << ticket.getYourWagon()
                << "\nWg place: " << ticket.getPlaceNumber() << "\n-------\n";
    }
}


void trips_on_certain_date_report(main_system &sys) {
    std::cout << CLR_cyan"\n\n   *** Report: \"Trips on certain date\" *** \n" CLR_NORMAL;
    trips_on_certain_date(sys);
}

void free_places_on_certain_trip_report(main_system &sys) {
    std::cout << CLR_cyan"\n\n   *** Report: \"Free places on certain trip\" *** \n " CLR_NORMAL;

    std::vector<ticket> trip_tickets, free_trip_tickets;
    std::vector<trip> trips_to_the_date;
    DB_ID trip_id, operation;

    std::cout << "\n1)Search by id\n2)Search by date + route\nEnter(1/2): ";

    do {
        operation = operation_check();
    } while (!(operation == 1 || operation == 2));

    if (operation == 1) {
        trip_id = ask_trip_id_from_user(sys);
        trip_tickets = get_trip_tickets_list(sys, trip_id);
        int counter = 0;
        for (const auto &ticket: trip_tickets) {
            if (ticket.getState() == 0) {
                counter++;
            }
        }
        std::cout << "\n" << counter << " free tickets to the your trip\n";

    } else {
        trips_to_the_date = trips_on_certain_date(sys);
        free_places_on_certain_trip(sys, trips_to_the_date, trip_tickets);

    }

    std::cout<< "Show free places list ?\n1)Yes\n2)No\nYour choice: ";
    do {
        operation = operation_check();
    } while (!(operation == 1 || operation == 2));
    if (operation == 1) {
        free_places_list(sys, trip_id);
    } else{
        return;
    }
}

void routes_which_contain_certain_station_report(main_system &sys) {
    std::cout << CLR_cyan"\n\n   *** Report: \"Routes which contain certain station\" *** \n" CLR_NORMAL;

    std::vector<route> all_routes, good_routes;
    std::vector<DB_ID> stations_in_route;
    all_routes = sys.Get_route_vector();
    station station;

    DB_ID station_id = find_station_by_name(sys);

    for(auto& route: all_routes){
        stations_in_route = route.getStationIds();
        for(auto st_id: stations_in_route){
            if(st_id == station_id){
                good_routes.push_back(route);
                continue;
            }
        }
    }

    if(good_routes.empty()){
        std::cout << "Station is not used\n";
        return;
    } else{
        int i = 0;
        for(const auto& route: good_routes){
            stations_in_route = route.getStationIds();
            ++i;
            std::cout << CLR_yellow "\n* Route "  << i << ";" CLR_NORMAL;
            std::cout << "\n | Id: " << route.getId() <<
            "\n | Stations in route: "; get_route_stations(sys, route.getId());
            std::cout << "\n | Station ids:   ";
            for(auto st: stations_in_route ){
                std::cout << "    " << st;
            }
            std::cout << std::endl;
        }
    }
}

void routes_which_contain_many_stations_report(main_system &sys) {
    std::cout << CLR_cyan "\n\n   *** Report: \"Routes which contain many stations\" *** \n " CLR_NORMAL;

    std::vector<route> all_routes, good_routes;
    std::vector<DB_ID> stations_in_route, station_ids;
    all_routes = sys.Get_route_vector();
    station station;

    std::cout << "Enter number of stations: ";
    int counter = 0;
    counter = operation_check();
    for(int i = 0; i < counter; ++i){
        DB_ID station_id = find_station_by_name(sys);
        station_ids.push_back(station_id);
    }

    for(auto& route: all_routes){
        counter = 0;
        stations_in_route = route.getStationIds();
        for(auto st_route_id: stations_in_route){
            for(auto st_user_id: station_ids){
                if(st_route_id == st_user_id){
                    counter++;
                }
            }
            if(counter == station_ids.size()){
                good_routes.push_back(route);
            }
        }
    }

    if(good_routes.empty()){
        std::cout << "Station is not used\n";
        return;
    } else{
        int i = 0;
        for(const auto& route: good_routes){
            ++i;
            std::cout << "Route " << i << " : ";
            get_route_information(sys, route.getId());
        }
    }

}

void the_most_popular_route_report(main_system &sys) {
    std::cout << CLR_cyan "\n   *** Report: \"The most popular route\" *** \n" CLR_NORMAL;



}
DB_ID find_route_by_stations(main_system &sys){

    std::vector<route> all_routes, good_routes;
    std::vector<DB_ID> stations_in_route, station_ids;
    all_routes = sys.Get_route_vector();
    station station;
    DB_ID appropriate_route;

    std::cout << "Enter number of stations: ";
    int counter = 0;
    counter = operation_check();
    for(int i = 0; i < counter; ++i){
        DB_ID station_id = find_station_by_name(sys);
        station_ids.push_back(station_id);
    }
    for(auto& route: all_routes){
        counter = 0;
        stations_in_route = route.getStationIds();
        for(auto st_route_id: stations_in_route){
            for(auto st_user_id: station_ids){
                if(st_route_id == st_user_id){
                    counter++;
                }
            }
            if(counter == station_ids.size()){
                good_routes.push_back(route);
            }
        }
    }
    counter = 0;
    for(const auto& route: good_routes){
        if(good_routes.size() == 1){
           appropriate_route = route.getId();
           break;
        }
        ++counter;
        std::cout << "Trip number "<<counter<<" : ";
        get_route_information(sys, route.getId());

    }
    bool is_ok;
    do {
        is_ok = false;
        std::cout << "Enter route id\n";
        appropriate_route = ask_ticket_id_from_user(sys);
        for (const auto& route: good_routes) {
            if (appropriate_route == route.getId()) {
                is_ok = true;
            }
        }
        if(!is_ok){
            std::cout<< "Try again\n";
        }
    }while (!is_ok);

    return appropriate_route;



}

void trips_which_use_certain_route_report(main_system &sys) {
    std::cout << CLR_cyan "\n\n   *** Report: \"Route usages \" *** \n" CLR_NORMAL;

    std::vector<trip> all_trips, good_trips;
    all_trips = sys.Get_trip_vector();

    DB_ID operation, route_id;
    std::cout << "Firstly, find route)\n";
    std::cout << "\n1)Search by id\n2)Search by stations\nEnter(1/2): ";

    do {
        operation = operation_check();
    } while (!(operation == 1 || operation == 2));

    if(operation == 1){
        route_id = ask_route_id_from_user(sys);
    }else{
        route_id = find_route_by_stations(sys);
    }

    for(const auto& trip: all_trips){
        if(trip.getRouteId() == route_id){
            good_trips.push_back(trip);
        }
    }

    std::cout << "Yor route uses in " << good_trips.size() << " trips\n";
    int counter = 0;
    for(const auto& trip: good_trips){
        ++counter;
        std::cout << "\n* Trip number ("<<counter<<" ) ";

        get_trip_information(sys, trip.getId());
    }

}

template <typename my_type>
void my_shaker_stop_sort_temp_storage(std::vector<my_type> & records, size_t size) {
    int left, right;
    left = 1;
    right = size - 1;
    while (left <= right) {
        int counter = 0;
        for (int i = right; i >= left; i--) {
            if (records[i - 1] > records[i]) {
                auto tmp = records[i - 1];
                records[i - 1] = records[i];
                records[i]=tmp;
                ++counter;
            }
        }
        if (counter == 0) {
            return;
        }
        left++;
        for (int i = left; i <= right; i++) {
            if (records[i - 1] > records[i]) {
                auto tmp = records[i - 1];
                records[i - 1] = records[i];
                records[i]=tmp;
                ++counter;
            }
        }
        if (counter == 0) {
            return;
        }
        right--;
    }
}

void sort_stations_by_names(main_system &sys) {
    std::vector<station> stations;
    stations = sys.Get_station_vector();

   // std::sort(stations.rbegin(), stations.rend());
    my_shaker_stop_sort_temp_storage(stations, stations.size());
    for(const auto& station : stations){
        std::cout  << "\n" << station.getId() << " "<< station.getName() << " ";
    }
}




std::string padding_for_utf8_str(std::string & in, int column_wide, char filler = ' '){
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    std::wstring converted = converter.from_bytes(in);
    return std::string(column_wide - converted.size(),filler);
}

void get_detailed_trip_info(main_system &sys) {

}



void schedule_report(main_system &sys) {
    std::cout << CLR_cyan "\n\n   *** Report: \" Schedule \" *** \n" CLR_NORMAL;

    std::vector<trip> all_trips, good_trips;
    all_trips = sys.Get_trip_vector();
    std::vector<route> routes;
    routes = sys.Get_route_vector();
    std::vector<station> rt_stations;
    std::vector<std::string> rt_st_names;

    int parsed_date, temp_date;

    std::cout << "\n Enter the date after which the information will be displayed \n ";
    DATE date = ask_user_date();

    parsed_date = date_parser(date);

    for(const auto& trip: all_trips){
        temp_date = date_parser(trip.getDate());
        if(temp_date > parsed_date){
            good_trips.push_back(trip);
        }
    }

    if(good_trips.empty()){
        std::cout << " ! No trips on closest days\n";
    }
    else{
        my_shaker_stop_sort_temp_storage(good_trips, good_trips.size());
        int counter = 0;
        int z[2]={0,0};
//        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//        for(const auto& trip: good_trips){
//            rt_stations = route_arrival_station_and_departure_station(sys, trip.getRouteId());
//            rt_st_names = get_names_from_stations(sys, rt_stations);
//            std::wstring st_name1 = converter.from_bytes(rt_stations[0].getName());
//            std::wstring st_name2 = converter.from_bytes(rt_stations[1].getName());
//            if(st_name1.size()>z[0]){
//                z[0]=st_name1.size();
//            }
//            if(st_name2.size()>z[1]){
//                z[1]=st_name2.size();
//            }
//        }
        std::cout << "\n -------------------------------------------------------------------------------------------------------------------------";
        std::cout << "\n/    Id    | Platform |      Date      |  Time  |          Arrival Station          |          Departure station          \\";
        std::cout << "\n|-------------------------------------------------------------------------------------------------------------------------|\n";

      //  std::cout << std::setfill ( '^' );
        for(const auto& trip: good_trips){
            rt_stations = route_arrival_station_and_departure_station(sys, trip.getRouteId());
            rt_st_names = get_names_from_stations(sys, rt_stations);
//            std::wstring st_name1 = converter.from_bytes(rt_stations[0].getName());
//            std::wstring st_name2 = converter.from_bytes(rt_stations[1].getName());
            ++counter;

//            std::string st1_fill(2 + z[0] - st_name1.size(),' ');
            std::cout
            << "| " <<  std::setw(5) << trip.getId() << "    |"
            << std::setw(6) <<  trip.getPlatformId()  <<"    |"
            << std::setw(13) << trip.getDate() << "   |"
            << std::setw(6) << trip.getTime() << "  |" << std::setw(0)
            << padding_for_utf8_str(rt_st_names[0],28) << rt_st_names[0]  << "       | "
            << padding_for_utf8_str(rt_st_names[1],28) << rt_st_names[1]  << "        | ";

            std::cout << std::endl;
        }
        std::cout << "\\------------------------------------------------------------------------------------------------------------------------/\n";

    }


}





/*
 *
 * sta name => start sta id
 * sta name => end sta id
 * route list => trip list => trip id list
 *
 */