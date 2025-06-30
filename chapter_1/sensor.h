#ifndef _SENSOR_H
#define _SENSOR_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* polymorphism the hard way */
typedef enum {
	MEMORY_MAPPED = 0,
	PORT_MAPPED
} SensorTypes;

/*## Class Sensor */
typedef struct Sensor Sensor;

struct Sensor {
	int filter_frequency;
	int update_frequency;
	int value;
	SensorTypes whatKindOfInterface; /* polymorphism the hard way */
};

// Note about const Sensor *const me : 
// First part (Const Sensor *) means that data pointed
// by the pointer is read only.
// Second part (const me) means the 'me' pointer cannot be changed
// to point to another data within the function.
// Essentially, this parameter introduces a read-only Sensor object and a constant pointer to the said object
int Sensor_getFilterFrequency(const Sensor *const me);
void Sensor_setFilterFrequency(Sensor *const me, int p_filterFrequency);
int Sensor_getUpdateFrequency(const Sensor *const me);
void Sensor_setUpdateFrequency(Sensor *const me, int p_updateFrequency);
int Sensor_getValue(const Sensor *const me);
/* polymorphism the hard way */
int acquireValue(Sensor *me);

Sensor *Sensor_Create(void);
void Sensor_Destroy(Sensor *const me);

#endif 