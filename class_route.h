//
// Created by al_sah on 27.03.20.
//

#ifndef ISE_CLASS_ROUTE_H
#define ISE_CLASS_ROUTE_H

#include <vector>
#include "class_my_db_record.h"
#include "class_station.h"

class route : public  my_db_record {

private:



public:


    int getStationsNumber() const;


    std::vector<DB_ID> station_ids;

    const std::vector<DB_ID> &getStationIds() const;
    void addStation(DB_ID station_id);
    void addStation(const station & station);
    void deleteStation(DB_ID station_id);
    void deleteStation(const station & station);

//    std::vector<>
    std::vector<station> getStations();

};

std::ostream & operator << (std::ostream &out, route &route1);
void operator >> (std::istream &in, route &route1);


#endif //ISE_CLASS_ROUTE_H
