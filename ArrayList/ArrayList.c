#include "ArrayList.h"
void CreateList(List *self, int capacity, int size)
{
	self->front = malloc(size*capacity);
	self->rear = (char *)(self->front) + (capacity - 1)*size;
	self->capacity = capacity;
	self->length = 0;
	self->size = size;

	self->DestroyList = DestroyList;
	self->AppendList = AppendList;
	self->InsertList = InsertList;
	self->InsertIndexList = InsertIndexList;
	self->DeleteList = DeleteList;
	self->DeleteIndexList = DeleteIndexList;
	self->DeleteAllList = DeleteAllList;
	self->SortList = SortList;
	self->SearchList = SearchList;
	self->TraverseList = TraverseList;
	self->GetData = GetData;
	self->SetData = SetData;
	self->GetCapacity = GetCapacity;
	self->GetLength = GetLength;
}

void DestroyList(List *self)
{
	free(self->front);
	self->capacity = 0;
	self->length = 0;
	self->size = 0;
}

int AppendList(List *self, void *data)
{
	int ret;

	if (self->length < self->capacity) {
		(self->length)++;
		memcpy((char *)(self->front) + ((self->length) - 1)*(self->size), (char *)data, self->size);
		ret = 1;
	}
	else
		ret = -1; // ERROR
	return ret;
}

int InsertList(List *self, void *currentdata, void *data, int(*compare)(void *, void *))
{
	int i;
	int	currentindex = self->SearchList(self, currentdata, compare) + 1;
	if (self->length < self->capacity && currentindex) {
		for (i = (self->length) - 1; i >= currentindex; i--)
			memcpy((char *)(self->front) + (i + 1)*(self->size), (char *)(self->front) + i*(self->size), (self->size));
		memcpy((char *)(self->front) + currentindex*(self->size), (char *)data, (self->size));
		(self->length)++;
		return 1;
	}
	else
		return -1;

}


int InsertIndexList(List *self, int currentindex, void *data)
{
	int i;
	if ((self->length < self->capacity)
		&& (self->length > currentindex)
		&& (currentindex >= 0))
	{
		for (i = (self->length) - 1; i >= currentindex + 1; i--) {
			memcpy((char *)(self->front) + (i + 1)*(self->size), (char *)(self->front) + i*(self->size), (self->size));
		}
		memcpy((char *)(self->front) + (currentindex + 1)*(self->size), (char *)data, (self->size));
		(self->length)++;
		return 1;
	}
	else
		return -1;

}


int DeleteList(List *self, void *currentdata, int(*compare)(void *, void *))
{
	int i;
	int deleteindex = SearchList(self, currentdata, compare);
	if (self->length > 0 && deleteindex >= 0) {
		for (i = deleteindex; i < (self->length); i++) {
			memcpy((char *)(self->front) + i*(self->size), (char *)(self->front) + (i + 1)*(self->size), (self->size));
		}
		(self->length)--;
		return 1;
	}
	else
		return -1;
}


int DeleteIndexList(List *self, int deleteindex)
{
	int i;
	if (self->length > 0 && deleteindex < self->length) {
		for (i = deleteindex; i < (self->length); i++) {
			memcpy((char *)(self->front) + i*(self->size), (char *)(self->front) + (i + 1)*(self->size), (self->size));
		}
		(self->length)--;
		return 1;
	}
	else
		return -1;
}


void DeleteAllList(List *self)
{
	if (self->length > 0)
		self->length = 0;
}


void SortList(List *self, int(*compare)(void *, void *))
{
	int i, j;
	void *tmp = malloc(self->size);
	int iLoop = (self->length) - 1;
	int jLoop;
	int flag = 1;

	for (i = 0; i<iLoop; i++) {
		jLoop = (self->length) - i - 1;
		if (flag) {
			flag = 0;
			for (j = 0; j<jLoop; j++) {
				if (compare((char *)(self->front) + j*(self->size), (char *)(self->front) + (j + 1)*(self->size)) > 0) {
					memcpy(tmp, (char *)(self->front) + j*(self->size), (self->size));
					memcpy((char *)(self->front) + j*(self->size), (char *)(self->front) + (j + 1)*(self->size), (self->size));
					memcpy((char *)(self->front) + (j + 1)*(self->size), tmp, (self->size));
					flag = 1;
				}
			}
		}
		else
			break;
	}
}

int IntCompare(void *s, void *f) {
	return *((int *)s) - *((int *)f);
}
int StrCompare(void *s, void *f) {
	return strcmp(s, f);
}
int SearchList(List *self, void *key, int(*compare)(void *, void *))
{
	int i;
	for (i = 0; i<(self->length); i++) {
		if (compare((char *)(self->front) + i*(self->size), key) == 0)
		{
			return i;
		}
	}
	return -1;
}

void TraverseList(List *self, void(*traverse)(void *))
{
	int i;
	for (i = 0; i < (self->length); i++) {
		traverse((char *)(self->front) + i*(self->size));

	}
}
void TraverseInt(void *i)
{
	printf("%3d\t", *(int *)i);
}
void TraverseStr(void *s)
{
	printf("%s\t", (char *)s);
}

void GetData(List *self, int index, void *data)
{
	if ((self->length > 0)
		&& index >= 0
		&& index < self->length) {
		memcpy(data, (char *)(self->front) + index*(self->size), self->size);
	}
}

void SetData(List *self, int index, void *data)
{
	if (index >= 0 && index < self->length)
		memcpy((char *)(self->front) + index*(self->size), (char *)data, self->size);
}

int GetCapacity(List *self)
{
	return self->capacity;
}

int GetLength(List *self)
{
	return self->length;
}

