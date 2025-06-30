#include "sensor.h"

void Sensor_Init(Sensor *const me) {

}

void Sensor_Cleanup(Sensor *const me) {
	
}

int Sensor_getFilterFrequency(const Sensor *const me) {
	return me->filter_frequency;
}

void Sensor_setFilterFrequency(Sensor * const me, int p_filterFrequency) {
	me->filter_frequency = p_filterFrequency;
}

int Sensor_getUpdateFrequency(const Sensor *const me)
{
	return me->update_frequency;
}

void Sensor_setUpdateFrequency(Sensor * const me, int p_updateFrequency) {
	me->update_frequency = p_updateFrequency;
}

int Sensor_getValue(const Sensor *const me) {
	return me->value;
}

Sensor *Sensor_Create(void) {
	Sensor *me = (Sensor *)malloc(sizeof(Sensor));
	if (me != NULL) {
		Sensor_Init(me);
	}

	return me;
}

void Sensor_Destroy(Sensor *const me) {
	if (me != NULL) {
		Sensor_Cleanup(me);
	}

	free(me);
}