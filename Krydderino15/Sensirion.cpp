//
//  Sensirion.cpp
//  Krydderino_008
//
//  Created by Haakon Storm Heen on 29.04.12.
//  Copyright (c) 2012 Haakon Storm, Inc. All rights reserved.
//

//#include <iostream>
#include "SHT1x.h"			// Sensirion Humidity Sensor 11 library	
#include "MagicNumbers.h"
#include "Sensirion.h"

SHT1x sht1x(SENSIRION_DATA_PIN, SENSIRION_CLOCK_PIN);

Sensirion::Sensirion() {}

// @return  temperature in celsius
float Sensirion::read_temperature(void)
{
	float temp_c;
	
    // Read values from the sensor
	temp_c = sht1x.readTemperatureC();
	return temp_c; // in celcius
}	

// @return  _percentage_ of relative humidity
float Sensirion::read_humidity(void) 
{
	float humidity;
	
    // Read values from the sensor
	humidity = sht1x.readHumidity();
    
	return humidity; // in %
}	

