#ifndef __Array_LIST_H_
#define __Array_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef struct __List List;
typedef struct __List {
	void *front;
	void *rear;
	int capacity;
	int length;
	int size;

	void(*DestroyList)(List *self);
	int(*AppendList)(List *self, void *data);
	int(*InsertList)(List *self, void *currentdata, void *data, int(*compare)(void *, void *));
	int(*InsertIndexList)(List *self, int currentindex, void *data);
	int(*DeleteList)(List *self, void *currentdata, int(*compare)(void *, void *));
	int(*DeleteIndexList)(List *self, int deleteindex);
	void(*DeleteAllList)(List *self);
	void(*SortList)(List *self, int(*compare)(void *, void *));
	int(*SearchList)(List *self, void *key, int(*compare)(void *, void *));
	void(*TraverseList)(List *self, void(*traverse)(void *));
	void(*GetData)(List *self, int index, void *data);
	void(*SetData)(List *self, int index, void *data);
	int(*GetCapacity)(List *self);
	int(*GetLength)(List *self);

} List;

void CreateList(List *self, int capacity, int size);
void DestroyList(List *self);
int AppendList(List *self, void *data);
int InsertList(List *self, void *currentdata, void *data, int(*compare)(void *, void *));
int InsertIndexList(List *self, int currentindex, void *data);
int DeleteList(List *self, void *currentdata, int(*compare)(void *, void *));
int DeleteIndexList(List *self, int deleteindex);
void DeleteAllList(List *self);
void SortList(List *self, int(*compare)(void *, void *));
int IntCompare(void *s, void *f);
int StrCompare(void *s, void *f);
int SearchList(List *self, void *key, int(*compare)(void *, void *));
void TraverseList(List *self, void(*traverse)(void *));
void TraverseInt(void *i);
void TraverseStr(void *s);
void GetData(List *self, int index, void *data);
void SetData(List *self, int index, void *data);
int GetCapacity(List *self);
int GetLength(List *self);

#endif