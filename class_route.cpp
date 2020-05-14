//
// Created by al_sah on 27.03.20.
//

#include "class_route.h"
#include "utils.h"
#include <algorithm>


std::ostream & operator << (std::ostream &out, route &route1) {
    std::vector<DB_ID> station_ids = route1.getStationIds();
    out
            << route1.getId() << ' '
            << route1.getStationsNumber();
            for(auto sta_id: station_ids){
                out << " "<< sta_id ;
            }
    out << '\n';

    return out;
}


void operator >> (std::istream &in, route &route1) {

    DB_ID tempID;
    DB_ID station;
    int st_numb;
    in >> tempID;
    route1.setId(tempID);

    if(!in.good()){
        return;
    }

    in >> st_numb;

    for(int i=0; i< st_numb;i++){
        if(!in.good()){
            break;
        }
        in >> station;
        route1.addStation(station);
    }

}

int route::getStationsNumber() const {
    return station_ids.size();
}

const std::vector<DB_ID> &route::getStationIds() const {
    return station_ids;
}

bool route::deleteStation(DB_ID station_id) {
    std::vector<DB_ID>::iterator sta;
    sta = std::find(station_ids.begin(), station_ids.end(), station_id);
    if(sta == station_ids.end()){
        return false;
    }
    station_ids.erase(sta);
    return true;
}

bool route::addStation(DB_ID station_id) {
    std::vector<DB_ID>::iterator sta;
    sta = std::find(station_ids.begin(), station_ids.end(), station_id);
    if(sta != station_ids.end()){
        return false;
    }
    station_ids.push_back(station_id);
    return true;
}


std::vector<station> route::getStations(StationsStorage * sys) {
    std::vector<station> all_stations = sys->Get_station_vector();
    std::vector<station> my_stations;
    for(DB_ID st_id: station_ids){
        int idx = Alex_Utils::find_index(all_stations, st_id);
        if(idx == NOT_FOUND){
            continue;
        }
        my_stations.push_back(all_stations[idx]);
    }
    return my_stations;
}