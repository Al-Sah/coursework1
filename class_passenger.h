//
// Created by al_sah on 27.03.20.
//

#ifndef ISE_CLASS_PASSENGER_H
#define ISE_CLASS_PASSENGER_H

#include <iostream>

class passenger {

private:
    std::string full_name;
    int passenger_id;
    std::string password;
public:
    const std::string &getPassword() const;
    void setPassword(const std::string &password);
    const std::string &getFullName() const;
    void setPassengerId(int passengerId);
    int getPassengerId() const;
    void setFullName(const std::string &fullName);


};


#endif //ISE_CLASS_PASSENGER_H
