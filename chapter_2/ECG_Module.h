#ifndef ECG_MODULE_H
#define ECG_MODULE_H

#include <stdio.h>
#include "ECPkg.h"

struct TMDQueue;

/* class ECG_Module */
typedef struct ECG_Module ECG_Module;

struct ECG_Module {
	int dataNum;

	int lead1;

	int lead2;

	struct TMDQueue* itsTMDQueue;
};

/* constructors and destructors */
void ECG_Module_acquireValue(ECG_Module *const me);
void ECG_Module_setLeadPair(ECG_Module *const me, int l1, int l2);
void ECG_Module_setItsTMDQueue(ECG_Module *const me, struct TMDQueue *p_TMDQueue);
ECG_Module *ECG_Module_Create(void);
void ECG_Module_Destroy(ECG_Module *const me);

#endif