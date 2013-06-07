//
//  EC.h
//  Krydderino_008
//
//  Created by Haakon Storm Heen on 21.05.12.
//  Copyright (c) 2012 Haakon Storm, Inc. All rights reserved.
//

#ifndef Krydderino_008_EC_h
#define Krydderino_008_EC_h

	// Core library
#include "Arduino.h" // — for Arduino 0023
#include "MagicNumbers.h"

class EC
{
public:	
	int last_average;
	int last_samples[EC_NUM_OF_SAMPLES];
	int last_samples_counter;
    
	
	char* sensorstring;
    char read;
	
    bool input_stringcomplete;
	bool sensor_stringcomplete;
    
	EC(void);
    // int convert_ppm(int §ppm);
	int read_sensor(void);
	int initialize_ec_sensor(void);
    int averaged_reading(void);
	void rotate_last_samples_counter(void);
	
private:		
};


#endif
