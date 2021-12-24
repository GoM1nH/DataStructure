#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

enum SlotStatus {EMPTY, DELETED, INUSE}; // Slot의 상태를 나타내는 상수들
// EMPTY 비어있다, DELTETED 데이터가 저장되었었으나 현재는 비워져있다, INUSE 데이터 저장되어있다

typedef struct _slot
{
	Key key;
	Value val;
	enum SlotStatus status;
}Slot;

#endif