//
//  FlightFinder.cpp
//  FlightFinder
//
//  Created by Steve Michelini on 9/25/15.
//  Copyright © 2015 sdmichelini. All rights reserved.
//

#include "FlightFinder.h"

FlightFinder::FlightFinder(){
    m_bitMatrix = nullptr;
    m_bitMatrix = std::unique_ptr<BitMatrix>(new BitMatrix());
}

void FlightFinder::AddFlight(Flight f){
    assert(m_bitMatrix != nullptr);
    uint32_t originPos = 0;
    uint32_t destPos = 0;
    
    std::tie(originPos,destPos) = CitiesExist(f.GetOrigin(), f.GetDestination());
    
    if(originPos == UINT32_MAX){
        m_cities.push_back(f.GetOrigin());
        m_bitMatrix->AddColumn();
        m_bitMatrix->AddRow();
        originPos = (uint32_t)m_cities.size() - 1;
    }
    if(destPos == UINT32_MAX){
        m_cities.push_back(f.GetDestination());
        m_bitMatrix->AddColumn();
        m_bitMatrix->AddRow();
        destPos = (uint32_t)m_cities.size() - 1;
    }
    
    m_bitMatrix->SetDataAt(originPos, destPos, true);
}

uint32_t FlightFinder::LoadFlights(std::string filename){
    return 0;
}

uint32_t FlightFinder::CityExists(std::string city){
    for(unsigned int i = 0; i < m_cities.size(); i++){
        if(city == m_cities[i]){
            return i;
        }
    }
    return 0;
}

std::tuple<uint32_t, uint32_t> FlightFinder::CitiesExist(std::string origin, std::string dest){
    uint32_t originPos = UINT32_MAX;
    uint32_t destPos = UINT32_MAX;
    for(unsigned int i = 0; i < m_cities.size(); i++){
        if(origin == m_cities[i]){
            originPos = i;
        }else if(dest == m_cities[i]){
            destPos = i;
        }
    }
    return std::make_tuple(originPos,destPos);
}

bool FlightFinder::HasRoute(std::string origin, std::string dest){
    uint32_t originPos = 0;
    uint32_t destPos = 0;
    
    std::tie(originPos,destPos) = CitiesExist(origin, dest);
    
    if((originPos == UINT32_MAX) || (destPos == UINT32_MAX)){
        return false;
    }
    return HasRouteList(originPos, destPos, std::vector<uint32_t>());
}


bool FlightFinder::HasRouteList(uint32_t origin, uint32_t dest, std::vector<uint32_t> visited){
    
    
    for(unsigned int i = 0; i < visited.size(); i++){
        if(visited[i] == origin){
            return false;
        }
    }
    
    if(m_bitMatrix->GetDataAt(origin, dest)){
        return true;
    }
    visited.push_back(origin);
    for(unsigned int i = 0; i < m_cities.size(); i++){
        int y = 0;
        y++;
        if(i != origin){
            if(m_bitMatrix->GetDataAt(i, dest)){
                int x = 0;
                x++;
                return HasRouteList(i, dest, visited);
            }
        }
    }
    return false;
}

float RouteCost(std::string origin, std::string dest){
    return 0.0f;
}



