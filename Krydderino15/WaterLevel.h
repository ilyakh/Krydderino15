
// Technical details
// https://www.adafruit.com/products/464

#ifndef water_level_h
#define water_level_h

#include "MagicNumbers.h"
#include "Arduino.h"

class WaterLevel
{
  public:	
	float   water_level_reading[WL_NUMBER_OF_READINGS];
	int     water_level_buffer_counter;
	float   averaged_water_level;	// public level

	WaterLevel(void);
	float       read_sensor();
	int         balanced_level();
	void        init();
	float       get_averaged_water_level();
	int         water_level_in_inches();
	WL_STATUS   humanized_level();
  private:		
};

#endif

