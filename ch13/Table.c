#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table * pt, HashFunc * f)
{
	int i;

	// 모든 슬롯을 초기화해준다.
	for(i=0; i<MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;

	pt->hf = f; // 해쉬함수를 테이블에 등록해준다.
}

void TBLInsert(Table * pt, Key k, Value v)
{
	int hv = pt->hf(k); // hv는 데이터를 저장할 index값이 된다.
	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table * pt, Key k)
{
	int hv = pt->hf(k);

	if((pt->tbl[hv]).status != INUSE) // 만약 아무것도 들어있지 않은 상태라면
	{
		return NULL;
	}
	else // DELETED나 EMPTY 상태라면
	{
		(pt->tbl[hv]).status = DELETED;
		return (pt->tbl[hv]).val;
	}
}

Value TBLSearch(Table * pt, Key k)
{
	int hv = pt->hf(k);

	if((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).val;
}