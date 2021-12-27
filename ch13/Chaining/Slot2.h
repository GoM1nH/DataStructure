#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

// Slot의 Status를 표시하기 위한 enum 선언이 사라졌다.
// 닫힌 어드레싱 방법의 경우에는 슬롯의 상태 정보를 표기할 이유가 없다. 어짜피 하나의 해쉬 값에 정보가 여러개 들어가니까.

typedef struct _slot
{
	Key key;
	Value val;
} Slot;

#endif