//
//  Flight.cpp
//  FlightFinder
//
//  Created by Steve Michelini on 9/24/15.
//  Copyright © 2015 sdmichelini. All rights reserved.
//

#include "Flight.h"


Flight::Flight(std::string origin, std::string destination, float price, uint32_t time){
    m_origin = origin;
    m_destination = destination;
    m_price = price;
    m_time = time;
}