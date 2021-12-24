#ifndef __TABLE_H__
#define __TABLE_H__

#include "Slot.h" 

#define MAX_TBL     100

typedef int (* HashFunc)(Key k); // 해쉬함수와 관련된 함수 포인터

typedef struct _table
{
	Slot tbl[MAX_TBL];
	HashFunc * hf;
}Table;


// 테이블 초기화
void TBLInit(Table * pt, HashFunc * f);

// 테이블에 key, value 저장
void TBLInsert(Table * pt, Key k, Value v);

// key로 데이터를 탐색하여 데이터 삭제
Value TBLDelete(Table * pt, Key k);

// key로 데이터를 탐색
Value TBLSearch(Table * pt, Key k);

#endif