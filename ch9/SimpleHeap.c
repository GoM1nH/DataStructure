#include "SimpleHeap.h"

void HeapInit(Heap *ph) {
    ph->numOfData = 0;
}

int HIsEmpty(Heap *ph) {
    if (ph->numOfData == 0) {
        return TRUE;
    } else return FALSE;
}

int GetParantIDX(int idx) {
    return idx/2;
}

int GetLChildIDX(int idx) {
    return idx*2;
}

int GetRChildIDX(int idx) {
    return GetLChildIDX(idx)+1; // 2*idx+1
}

int GetHiChildIDX(Heap *ph, int idx) {

    if (GetLChildIDX(idx) > ph->numOfData) { // 자식 노드가 없다면
        return 0;
    } else if (GetLChildIDX(idx) == ph->numOfData) { // 자식 노드가 왼쪽 자식 노드 하나만 존재한다면
        return GetLChildIDX(idx); // 비교 대상이 없으니 그냥 니가 가라..
    } else { // 자식 노드 두개가 온전히 있다면
        if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr) { // 값이 작을수록 우선순위가 높다는걸 기억해라!
            return GetRChildIDX(idx);
        } else {
            return GetLChildIDX(idx);
        }
    }
}

void HInsert(Heap *ph, HData data, Priority pr) { // 새 노드를 삽입하는 과정이다.

    int idx = ph->numOfData + 1; // 맨 아래층의 맨 오른쪽에 새 노드를 추가한다
    HeapElem nelem = {pr, data}; // 추가된 새 노드의 우선순위와 데이터.

    while (idx != 1) {
        if (pr < ph->heapArr[GetParantIDX(idx)].pr) { // 만약 부모노드보다 우선순위가 높다면
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)]; // 부모노드가 한 자리 내려간다
            idx = GetParentIDX(idx);
        } else { // 부모노드보다 우선순위가 낮다면
            break; // 여기가 내자리다!
        }
    }

    ph->heapArr[idx] = nelem; // 배정받은 내 자리에 내 우선순위와 데이터를 깔고
    ph->numOfData += 1; // 새 노드가 추가되었으니 numOfData 가 하나 늘어난다
}


HData HDelete(Heap *ph) { // 맨 위의 Root Node를 삭제한다. 우선순위가 가장 높은 노드니까.
    HData rdata = (ph->heapArr[1]).data; // RootNode의 데이터. 즉 삭제할 데이터임.
    HeapElem lastElem = ph->heapArr[ph->numOfData]; // 맨 밑의 맨 오른쪽에 있는 Node. 즉 마지막 노드.

    int parentidx = 1; //맨 위 root node쪽의 idx값. 나중에는 마지막 노드가 저장될 위치 정보가 담긴다.
    int childidx;

    while (childidx = GetHiChildIDX(ph, parentidx)) { // 루트 노드의 아래 두 자녀노드의 idx값 중, 우선순위가 높은 노드의 idx값이 childidx
        if (lastElem.pr <= ph->heapArr[childidx].pr) { // 만약 lastElem보다 자녀노드의 우선순위가 낮다면
            break; // 자리 배정 완료
        }

        // 마지막 노드보다 우선순위가 높아서, 비교대상 노드의 위치를 한 레벨 올린다.
        ph->heapArr[parentidx] = ph->heapArr[childidx]; // 부모노드 자리를 자녀가 꿰찬다
        parentidx = childidx; // 부모노드 자리의 idx값을 자녀가 꿰찮다
    } // while이 깨지면 parentidx에는 최종적으로 마지막 노드가 갈 위치 정보가 저장된다.

    ph->heapArr[parentidx] = lastElem; // 자리 배정 완료 후, 해당 자리에 lastElem이 이사를 감
    ph->numOfData -= 1; // 데이터를 삭제했으니, 하나 없앤다
    return rdata; // 삭제한 데이터 반환

}