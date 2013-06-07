//
//  Status.h 
//  Library header
//  ----------------------------------
//  Developed with embedXcode
//
//  Project Krydderino_008
//  Created by Haakon Storm Heen on 05.05.12
//  Copyright (c) 2012 Haakon Storm, Inc.
//

// Core library
#include "Arduino.h" // — for Arduino 0023
#include "MagicNumbers.h"

#ifndef Status_h
#define Status_h

class Status 
{
public:
	float     plant_temperature;
	float     plant_humidity;
	float     ph_level;
	int       water_ec;
	int       water_ph;
	float     water_level_instant;
	float     water_temperature;
	int       water_level_in_inches;
    WL_STATUS water_level;
private:
	
};

#endif
