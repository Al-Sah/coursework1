//
// Created by al_sah on 23.05.20.
//

#include "user_menus.h"
#include "user_functions.h"

void boom(void *) {
    std::cout << "БУУУМ !!!! " << std::endl;
}

void baam(void *) {
    std::cout << "БАААМ !!!!!!" << std::endl;
}

void tram(void *) {
    std::cout << "ТРАММ !!!!!!" << std::endl;
}

void draw_menu(std::string caption, MenuItem * items, const char *description, main_system &sys){


    while(true) {
        int zi=0;
        std::cout << std::endl << caption << "\n";
        std::cout  << description << std::endl;
        std::map<std::string, int> cmds;
        //отрисовать

        std::cout << zi <<"( q ) = quit"<<std::endl;
        cmds["q"] = zi;
        for (MenuItem *current_menu_item = items; current_menu_item->caption; current_menu_item++) {
            zi++;
            std::cout << zi << "( " << current_menu_item->cmd << " ) = " << current_menu_item->caption << (current_menu_item->next ? " >>" : "") << std::endl;
//            std::cout << z->cmd << " = " << z->caption << (z->next ? " >>" : "") << std::endl;
            cmds[current_menu_item->cmd] = zi;

        }

//        std::cout << "q = баста"<<std::endl;
        int cnt = zi, option;
        std::string optionStr;

        do {
            //задать вопрос
            std::cout << "Enter operation: ";
            std::cin >> optionStr;
            option = -1;
            std::map<std::string, int>::iterator zzz = cmds.find(optionStr);
            if(zzz != cmds.end()){
                option = zzz->second;
            } else {
                try {
                    option = std::stoi(optionStr);
                } catch(...){
                    option = -1;
                }
            }
        } while (option < 0 || option > cnt);

        //
        if(option == 0){
            return;
        }

        option--;
        if (items[option].next) {
            draw_menu(caption + " / " +items[option].caption, items[option].next,  items[option].description, sys);
        }

        if (items[option].func) {
            items[option].func(sys);
        }
    }

}
/*

void next_menu(void *) {
    std::cout<< "sdfs dfsdf sdf ";
    MenuItem zzz[]={
            { caption: "bububu",
                    cmd: "bubu",
                    func: boom
            },
            {}

    };
    draw_menu("jhgj  ghjhg jh", zzz, "ug jyg uyfu tf tyftytf tyfy");
}

*/



MenuItem stations_menu[] = {
        {
                .caption {"See station information"},
                .cmd { "info"},
                func: get_station_information,
        },
        {
                .caption {"Get station list"},
                .cmd { "list"},
                func: get_station_list,
        },
        {
                .caption {"Edit station"},
                .cmd { "edit"},
                func: edit_station,
        },
        {
                .caption {"Delete station"},
                .cmd { "del"},
                func: delete_station,
        },
        {
                .caption {"Add station"},
                .cmd { "add"},
                func: add_new_station,
        },
        {}
};
MenuItem routes_menu[] = {
        {
                .caption {"See route information"},
                .cmd { "info"},
                func: get_route_information,
        },
        {
                .caption {"Get route stations"},
                .cmd { "r_st"},
                func: get_route_information,
        },
        {
                .caption {"Get route list"},
                .cmd { "list"},
                func: get_route_list,
        },
        {
                .caption {"Edit route"},
                .cmd { "edit"},
                func: edit_route,
        },
        {
                .caption {"Delete route"},
                .cmd { "del"},
                func: delete_route,
        },
        {
                .caption {"Add route"},
                .cmd { "add"},
                func: add_new_route,
        },{}
};

MenuItem trains_menu[] = {
        {
                .caption {"See train information"},
                .cmd { "info"},
                func: get_train_information,
        },
        {
                .caption {"Get train list"},
                .cmd { "list"},
                func: get_train_list,
        },
        {
                .caption {"Edit train"},
                .cmd { "edit"},
                func: edit_train,
        },
        {
                .caption {"Delete train"},
                .cmd { "del"},
                func: delete_train,
        },
        {
                .caption {"Add train"},
                .cmd { "add"},
                func: add_new_train,
        },{}
};

MenuItem trips_menu[] = {
        {
                .caption {"See trip information"},
                .cmd { "info"},
                func: get_trip_information,
        },
        {
                .caption {"Get trip list"},
                .cmd { "list"},
                func: get_trip_list,
        },
        {
                .caption {"Edit trip"},
                .cmd { "edit"},
                func: edit_trip,
        },
        {
                .caption {"Delete trip"},
                .cmd { "del"},
                func: delete_trip,
        },
        {
                .caption {"Add trip"},
                .cmd { "add"},
                func: add_new_trip,
        },{}
};
MenuItem tickets_menu[] = {
        {
                .caption {"See ticket information"},
                .cmd { "info"},
                func: get_ticket_information,
        },
        {
                .caption {"Get ticket list"},
                .cmd { "list"},
                func: get_ticket_list,
        },
        {
                .caption {"Edit ticket"},
                .cmd { "edit"},
                func: edit_ticket,
        },{}
};


MenuItem reports_menu[] = {
        {
                .caption {"Trips on date"},
                .cmd { "tr_d"},
                func: trips_on_certain_date_report,
        },
        {
                .caption {"Free places to the trip"},
                .cmd { "free"},
                func: free_places_on_certain_trip_report,
        },
        {
                .caption {"Routes with contain entered station"},
                .cmd { "st"},
                func: routes_which_contain_certain_station_report,
        },
        {
                .caption {"Routes with contain many entered stations"},
                .cmd { "sts"},
                func: routes_which_contain_many_stations_report,
        },
        {
                .caption {"Trips with contain entered route"},
                .cmd { "rt"},
                func: trips_which_use_certain_route_report,
        },{}
};

MenuItem user_menu[] = {
        {
                .caption {"Buy ticket"},
                .cmd { "buy"},
                func: buying_ticket,
        },
        {
                .caption {"Reports menu"},
                .cmd { "report"},
                .next {reports_menu},
                .description {"Menu for communication with reports "}
        },
        {}
};


MenuItem admin_menu[] = {
        {
                .caption {"Stations menu"},
                .cmd { "station"},
                .next {stations_menu},
                .description {"Menu for communication with stations "}
        },
        {
                .caption {"Routes menu"},
                .cmd { "route"},
                .next {routes_menu},
                .description {"Menu for communication with routes "}
        },
        {
                .caption {"Trains menu"},
                .cmd { "train"},
                .next {trains_menu},
                .description {"Menu for communication with trains "}
        },
        {
                .caption {"Trips menu"},
                .cmd { "trip"},
                .next {trips_menu},
                .description {"Menu for communication with trips "}
        },
        {
                .caption {"Tickets menu"},
                .cmd { "ticket"},
                .next {tickets_menu},
                .description {"Menu for communication with tickets "}
        },
        {
                .caption {"Reports menu"},
                .cmd { "report"},
                .next {reports_menu},
                .description {"Menu for communication with reports "}
        },{}
};


