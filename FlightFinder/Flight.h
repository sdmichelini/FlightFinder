//
//  Flight.h
//  FlightFinder
//
//  Created by Steve Michelini on 9/24/15.
//  Copyright © 2015 sdmichelini. All rights reserved.
//

#ifndef Flight_h
#define Flight_h

#include <string>

class Flight{
public:
    /**
     Create's a flight object
     
     @param origin
        Origin city of the flight
     @param destination
        Destination city of the flight
     @param price
        Price in USD of the flight
     @param time
        Time in minutes of the flight
     */
    Flight(std::string origin, std::string destination, float price, uint32_t time);
    
    std::string GetOrigin() const {
        return m_origin;
    }
    
    std::string GetDestination() const {
        return m_destination;
    }
    
    float GetPrice() const {
        return m_price;
    }
    
    uint32_t GetTime() const {
        return m_time;
    }
    
private:
    std::string m_origin;
    std::string m_destination;
    float m_price;
    uint32_t m_time;
};



#endif /* Flight_h */
