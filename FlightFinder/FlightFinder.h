//
//  FlightFinder.h
//  FlightFinder
//
//  Created by Steve Michelini on 9/24/15.
//  Copyright © 2015 sdmichelini. All rights reserved.
//

#ifndef FlightFinder_h
#define FlightFinder_h

#include "Flight.h"
#include "BitMatrix.hpp"
#include <tuple>

#include <memory>
#include <cassert>

class FlightFinder{
public:
    FlightFinder();
    
    void AddFlight(Flight f);
    /**
     Load's the flight info from a text file
     
     @param filename
        Name of the containing the flights and their information
     @ret
        Number of flights loaded. 0 on error.
     */
    uint32_t LoadFlights(std::string filename);
    
    bool HasRoute(std::string origin, std::string dest);
    
    float RouteCost(std::string origin, std::string dest);
private:
    bool HasRouteList(uint32_t origin, uint32_t dest, std::vector<uint32_t> visited);
    
    uint32_t CityExists(std::string city);
    //Only traverse arry of cities once
    std::tuple<uint32_t, uint32_t>CitiesExist(std::string origin, std::string dest);
    
    std::vector<Flight> m_flights;
    std::vector<std::string> m_cities;
    std::unique_ptr<BitMatrix> m_bitMatrix;
    
};

#endif /* FlightFinder_h */
