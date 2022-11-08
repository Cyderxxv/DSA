#include <iostream>

using namespace std;

struct DNODE {
    int key;
    DNODE* pNext;
    DNODE* pPrev;
};

struct DList {
    DNODE* pHead;
    DNODE* pTail;
};

DNODE* createNode(int data) {
    DNODE* p = new DNODE;
    p -> key = data;
    p -> pNext = NULL;
    p -> pPrev = NULL;
    return p;
}

DList* createList(DNODE* p_node) {
    DList* list = new DList;
    list -> pHead = p_node;
    list -> pTail = p_node;
    return list;
}

void printList(DList*& L) {
    L = new DList;
    L -> pHead = NULL;
    L -> pTail = NULL;
}

bool addHead(DList* &L, int data) {
    DNODE* temp = createNode(data);
    if(temp == NULL) {
        return false;
    }
    if(L -> pHead == NULL) {
        L = createList(temp);
    }
    else {
        L -> pTail -> pNext = temp;
        temp -> pPrev = L -> pTail;
        L -> pTail = temp;
    }
    return true;
 }

bool addTail(DList*& L, int data) {
	DNODE* temp = createNode(data);
	if (temp == NULL) {
		return false;
	}
	if (L -> pHead == NULL) {
		L = createList(temp);
	}
	else {
		L -> pTail -> pNext = temp;
		temp -> pPrev = L -> pTail;
		L -> pTail = temp;
	}
	return true;
}

void removeHead(DList* &L) {
    if(L -> pHead == NULL) {
        return;
    }
    if(L -> pHead == L -> pTail) {
        delete L -> pHead;
        L -> pHead == NULL;
        L -> pTail == NULL;
        return;
    }
    DNODE* temp = L -> pHead;
    L -> pHead = L -> pHead -> pNext;
    L -> pHead -> pPrev == NULL;
    delete temp;
}

void removeTail(DList*& L) {
    if(L -> pHead == NULL) {
        return;
    }
    if(L -> pHead == L -> pTail) {
        delete L -> pHead;
        L -> pHead == NULL;
        L -> pTail == NULL;
        return;
    }
    DNODE* temp = L -> pTail;
    L -> pTail = L -> pTail -> pNext;
    L -> pTail -> pNext == NULL;
    delete temp;
}

void removeBefore(DList*& L, int val) {
    if (L -> pHead == NULL) {
		return;
	}
	if (L -> pHead == L -> pTail) {
		return;
	}
	DNODE* temp = L -> pHead -> pNext;
	while (temp != NULL && temp -> key != val) {
		temp = temp -> pNext;
	}
	if (temp == NULL) {
		return;
	}
	DNODE* temp1 = temp->pPrev;
	if (temp1 == L->pHead) {
		removeHead(L);
		return;
	}
	temp1 -> pPrev -> pNext = temp;
	temp -> pPrev = temp1 -> pPrev;
	delete temp1;
}

void removeAfter(DList*& L, int val) {
	if (L -> pHead == NULL) {
		return;
	}
	if (L -> pHead == L -> pTail) {
		return;
	}
	DNODE* temp = L -> pHead;
	while (temp -> pNext != NULL && temp -> key != val) {
		temp = temp -> pNext;
	}
	if (temp -> pNext == NULL) {
		return;
	}
	DNODE* temp1 = temp->pNext;
	if (temp1 == L -> pTail) {
		removeTail(L);
		return;
	}
	temp -> pNext = temp1 -> pNext;
	temp1 -> pNext -> pPrev = temp;
	delete temp1;
}

bool addPos(DList*& L, int data, int pos) {
	if (pos < 0) {
		cout << "Invalid position ";
		return false;
	}

	DNODE* flag = L -> pHead;
	while (--pos) {
		if (pos == -1) break;
		flag = flag -> pNext;
		if (flag == NULL) {
			return false;
		}
	}
	if (pos == -1) {
		addHead(L, data);
	}
	else if (flag == L -> pTail) {
		addTail(L, data);
	}
	else {
		DNODE* temp = createNode(data);
		temp -> pNext = flag -> pNext;
		flag -> pNext -> pPrev = temp;
		flag -> pNext = temp;
		temp -> pPrev = flag;
	}
	return true;
}

void removePos(DList*& L, int pos) {
	if (pos < 0) {
		cout << "Invalid position ";
	}

	DNODE* flag = L -> pHead;
	while (--pos) {
		if (pos == -1) 
            break;
		flag = flag -> pNext;
		if (flag -> pNext == NULL) {
			return;
		}
	}

	if (pos == -1 || L -> pHead == L -> pTail) {
		removeHead(L);
	}
	else if (flag -> pNext == L -> pTail) {
		removeTail(L);
	}
	else {
		DNODE* temp = flag -> pNext;
		flag -> pNext = temp -> pNext;
		temp -> pNext -> pPrev = flag;
		delete temp;
	}
}

bool addBefore(DList*& L, int data, int val) {
	if (L -> pHead == NULL) {
		return false;
	}
	if (L -> pHead -> key == val) {
		addHead(L, data);
		return true;
	}
	else {
		DNODE* flag = L -> pHead;
		for (flag; flag -> pNext != NULL; flag = flag -> pNext) {
			if (flag -> pNext -> key == val) {
				DNODE* temp = createNode(data);
				temp -> pNext = flag -> pNext;
				flag -> pNext -> pPrev = temp;
				flag -> pNext = temp;
				temp -> pPrev = flag;
				return true;
			}
		}
	}
	return false;
}

bool addAfter(DList*& L, int data, int val) {
	if (L -> pHead == NULL) {
		return false;
	}
	if (L -> pTail -> key == val) {
		addTail(L, data);
		return true;
	}
	else {
		DNODE* flag = L -> pHead;
		for (flag; flag != NULL; flag = flag -> pNext) {
			if (flag -> key == val) {
				DNODE* temp = createNode(data);
				temp -> pNext = flag -> pNext;
				flag -> pNext -> pPrev = temp;
				flag -> pNext = temp;
				temp -> pPrev = flag;
				return true;
			}
		}
	}
	return false;
}

int countElements(DList* L) {
	DNODE* temp = L -> pHead;
	int count = 0;
	while(temp) {
		count++;
		temp = temp -> pNext;
	}
	return count;
}

DList* reverseList(DList* L) {
	DNODE* temp = L -> pHead;	
	DNODE* head = createNode(L -> pHead -> key);
	DList* reverse = createList(head);
	temp = temp -> pNext;
	while(temp) {
		addHead(reverse, temp -> key);
		temp = temp -> pNext;
	}
	return reverse;
}

void removeDuplicate(DList*& L) {

}

int main() {
    DList* L;
    printList(L);

    // for(int i = 0; i < 10; i++) {
    //     addHead(L, i + 1);
    // }

    // for(int i = 0; i < 10; i++) {
    //     addTail(L, i + 1);
    // } q
    // removeHead(L);
    // removeTail(L);
    // removeBefore(L, 2);
    // removeAfter(L, 7);

    // addPos(L, 100, 11);
    // removePos(L, 0);

    // addBefore(L, 100, 11);
    // addAfter(L, 100, 10);
    cout << endl;
    return 0;
}