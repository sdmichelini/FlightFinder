//
//  main.cpp
//  FlightFinder
//
//  Created by Steve Michelini on 9/24/15.
//  Copyright © 2015 sdmichelini. All rights reserved.
//

#include <iostream>
#include "FlightFinder.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Sample Flight Finder\n";
    
    //Begin tests
    //Sample Flight Model
    std::string origin = "New York";
    std::string destination = "Los Angeles";
    float price = 69.78;
    uint32_t time = 300;
    
    Flight test1 = Flight(origin,destination,price,time);
    
    assert(test1.GetOrigin() == origin);
    assert(test1.GetDestination() == destination);
    assert(test1.GetPrice() == price);
    assert(test1.GetTime() == time);
    
    //Sample Bit Matrix
    bool bit1 = true;
    bool bit2 = false;
    bool bit3 = false;
    bool bit4 = true;
    
    BitMatrix test2 = BitMatrix();
    test2.AddColumn();
    test2.AddColumn();
    test2.AddRow();
    
    test2.SetDataAt(0, 0, bit1);
    test2.SetDataAt(0, 1, bit2);
    test2.SetDataAt(1, 0, bit3);
    test2.SetDataAt(1, 1, bit4);
    
    assert(test2.GetDataAt(0, 0));
    assert(!test2.GetDataAt(0, 1));
    assert(!test2.GetDataAt(1, 0));
    assert(test2.GetDataAt(1, 1));
    
    //Lets see if it can add to the vector dynamically
    test2.AddColumn();
    test2.AddColumn();
    
    test2.SetDataAt(1, 3, true);
    
    assert(test2.GetDataAt(1, 3));
    
    //Flight Finder Tests
    FlightFinder f = FlightFinder();
    
    f.AddFlight(Flight("Philadelphia","Boston",70.89,120));
    
    assert(f.HasRoute("Philadelphia", "Boston"));
    
    //More complex one
    
    f.AddFlight(Flight("Boston","New York",80.76,130));
    
    assert(f.HasRoute("Philadelphia", "New York"));
    assert(!f.HasRoute("New York", "Philadelphia"));
    
    std::cout<<"All Tests Passed"<<std::endl;
    return 0;
}
