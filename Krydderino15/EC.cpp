//
//  EC.cpp
//  Krydderino_008
//
//  Created by Haakon Storm Heen on 21.05.12.
//  Copyright (c) 2012 Haakon Storm, Inc. All rights reserved.
//

#include "EC.h"
#include "MagicNumbers.h"
#include <string.h>

EC::EC()
{
}

int EC::initialize_ec_sensor(void)
{
	Serial2.begin(EC_BAUD_RATE);
	last_samples_counter = 0;

	return 0; // OK
}

void EC::rotate_last_samples_counter(void)
{
	if (last_samples_counter < EC_NUM_OF_SAMPLES)
		last_samples_counter++;
	else
		last_samples_counter = 0;
}

int EC::read_sensor(void)
{
	String sensorstring;
    int ppm = -1;
    
    sensorstring.reserve(30);
    char tmp_sensorstring[40] = {'\0', '\0', '\0', '\0', '\0', '\0'};
    
    Serial2.print("r\r"); // \r == carriage return character
    delay( 2000 );
    
    while (Serial2.available() > 0) {
        read = (char)Serial2.read();
        sensorstring += read;
    }
    
    sensorstring.toCharArray( tmp_sensorstring, 6 );
    tmp_sensorstring[5] = '\0';
	ppm = atof(tmp_sensorstring);
    
    // Serial.print("Sensorstring: ");
    // Serial.println( sensorstring );
    // Serial.print("float ppm:");
    // Serial.println( ppm );
    
	// ppm = convert_ppm( ppm );
    
    return ppm;
}

/*
int EC::convert_ppm( int ppm )
{
 
    char *token[5];
    int i = 0;
    token[0]= strtok( sensorstring, "," );
    
    while (token[i] != NULL) 
    {
        i++;
        token[i] = strtok(NULL, ",");
        Serial.print( "Token " );
        Serial.print( i );
        Serial.print( ": " );
        serial.println( token[i] );
    }
    
    int ppmInt;
    ppmInt = atoi(token[1]);
	
    return ppmInt; 
    
    return ppm;
}
*/


int EC::averaged_reading(void)
{
	int total_samples[EC_NUM_OF_SAMPLES];
	int i;
	int ec_sum = 0;
	int rounded_average = 1;
	
	for (i=0; i < EC_NUM_OF_SAMPLES; i++)
	{
		total_samples[i] = read_sensor();
	}
    
	for (i=0; i < EC_NUM_OF_SAMPLES; i++)
	{
		ec_sum += total_samples[i];
	}
    

	
	rounded_average = (int)( ec_sum / EC_NUM_OF_SAMPLES );
    
	last_average = rounded_average;
    
    // Serial.print("Rounded average: ");
    // Serial.println(last_average);
    // Serial.print("As (int): ");
    // Serial.println((int)last_average);
    
	return rounded_average;
}
