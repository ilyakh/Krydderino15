
// WATER LEVEL SENSOR LIBRARY
// for the Krydderino INF1510 project
// INF1510 V-2012 
// (c) Haakon Storm Heen
// v0.1 23.03.2012

#include "MagicNumbers.h"
#include "WaterLevel.h"


// Constructor for Water Level sensor
WaterLevel::WaterLevel()
{
	water_level_buffer_counter = 0;
}

	// public averaged water level 
float WaterLevel::get_averaged_water_level()
{
	// sum the n number of readings
	float sum = 0;
	int i;
	for (i = 0; i < WL_NUMBER_OF_READINGS; i++)
		sum = sum + water_level_reading[i];
		
	// find the average reading
	averaged_water_level = (sum+1) / WL_NUMBER_OF_READINGS;
	
	return (int) averaged_water_level;	
}


void WaterLevel::init(void)
{
	// read water level n amount of times, with 
	int i;
	for (i = 0; i < WL_NUMBER_OF_READINGS; i++)
	{
		water_level_reading[i] = read_sensor();
		delay(WL_WATER_LEVEL_DELAY);
	}	
	
	// sum the n number of readings
	float sum = 0;
	for (i = 0; i < WL_NUMBER_OF_READINGS; i++)
		sum = sum + water_level_reading[i];
		
	// find the average reading and init buffer with this
	float avg;
	avg = (sum+1) / WL_NUMBER_OF_READINGS;
	for (i = 0; i < WL_NUMBER_OF_READINGS; i++)
		water_level_reading[i] = avg;	
}

float WaterLevel::read_sensor(void)
{
	float reading;
	reading = analogRead(WL_SENSOR_PIN);

  	// convert the value to resistance
/*	reading = (1023 / reading)  - 1;
	reading = WL_SERIESRESISTOR / reading;
*/	
	// put in ring buffer and update ring buffer counter
	water_level_reading[water_level_buffer_counter] = reading;
	water_level_buffer_counter++;
	if (water_level_buffer_counter == WL_NUMBER_OF_READINGS)
		water_level_buffer_counter = 0;
		
	return (int)reading;
}

	// return water level in inches
int WaterLevel::water_level_in_inches(void)
{
	// get the average water level
	int avg = (int)get_averaged_water_level();
	if (avg < WL_1_INCHES) return 0;
	else if (avg < WL_2_INCHES) return 1;
	else if (avg < WL_3_INCHES) return 2;
	else if (avg < WL_4_INCHES) return 3;
	else if (avg < WL_5_INCHES) return 4;
	else if (avg < WL_6_INCHES) return 5;
	else if (avg < WL_7_INCHES) return 6;
	else if (avg < WL_8_INCHES) return 7;
	else if (avg < WL_9_INCHES) return 8;
	else if (avg < WL_10_INCHES) return 9;
	else if (avg < WL_11_INCHES) return 10;
	else if (avg >= WL_11_INCHES) return 11;
	else return 12;
}

	// Returns the water level in humanized (token) form.
	// returns WL_EMPTY, WL_LOW etc based on magic TRESH values
WL_STATUS WaterLevel::humanized_level(void)
{
	// find the water level in inches
	int inches = water_level_in_inches();
	
	// tokenize level
	if (inches <= WL_EMPTY_THRESH) return WL_EMPTY;
	if (inches <= WL_LOW_THRESH) return WL_LOW;
	if (inches <= WL_NORMAL_THRESH) return WL_NORMAL;
	if (inches > WL_NORMAL_THRESH) return WL_TOO_HIGH;
}

