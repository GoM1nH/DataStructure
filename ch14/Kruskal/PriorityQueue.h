#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "RealHeap.h"

typedef Heap PQueue;
typedef HData PQData;

void PQueueInit(PQueue *q, Prioritycomp pc);
int PQIsEmpty(PQueue *q);

void Enqueue(PQueue *q, PQData data);
int Dequeue(PQueue *q);

#endif