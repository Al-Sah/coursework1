//
// Created by al_sah on 27.03.20.
//

#ifndef ISE_CLASS_ROUTE_H
#define ISE_CLASS_ROUTE_H

#include <vector>
#include "class_my_db_record.h"
#include "class_station.h"
#include "interfaces.h"


class route : public  my_db_record {

private:

    std::vector<DB_ID> station_ids;

public:

    int getStationsNumber() const;
    const std::vector<DB_ID> &getStationIds() const;

    bool addStation(DB_ID station_id);
    bool deleteStation(DB_ID station_id);

    std::vector<station> getStations(StationsStorage * sys);

};

std::ostream & operator << (std::ostream &out, route &route1);
void operator >> (std::istream &in, route &route1);


#endif //ISE_CLASS_ROUTE_H
