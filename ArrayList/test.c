#include "ArrayList.h"

int main()
{
	List a,b;

	int number[] = { 10, 8, 5, 3, 100, 9, 1, 15, 7 };
	char str[][10] = { "banana", "apple", "melon" };
	int data;
	char dataStr[10];

	CreateList( &a, 5, sizeof(int) );
	CreateList( &b, 3, sizeof(str[0]) );
	printf( "Create List - a\tCapacity[%d]\tLength[%d]\n", a.GetCapacity(&a), a.GetLength(&a) );
	printf( "Create List - a\tCapacity[%d]\tLength[%d]\n", b.GetCapacity(&b), b.GetLength(&b) );

	a.AppendList(&a, &number[0]);
	printf("Append : ");	a.TraverseList(&a, TraverseInt);	printf("\n");
	printf("Linear List Length = %d\n\n", a.GetLength(&a));
	a.AppendList( &a, &number[1] );
	printf( "Append : " );	a.TraverseList( &a, TraverseInt );	printf( "\n" );
	printf( "Linear List Length = %d\n\n", a.GetLength( &a ) );
	a.AppendList(&a, &number[2]);
	printf("Append : ");	a.TraverseList(&a, TraverseInt);	printf("\n");
	printf("Linear List Length = %d\n\n", a.GetLength(&a));
	a.SortList(&a, IntCompare);
	printf("Sort : ");	a.TraverseList(&a, TraverseInt);	printf("\n");


	b.AppendList( &b, &str[0] );	
	printf( "Append : " );	b,TraverseList( &b, TraverseStr );	printf( "\n" );
	printf( "Linear List Length = %d\n\n", b.GetLength( &b ) );
	b.AppendList(&b, &str[1]);
	printf("Append : ");	b, TraverseList(&b, TraverseStr);	printf("\n");
	printf("Linear List Length = %d\n\n", b.GetLength(&b));
	a.SortList(&b, StrCompare);
	printf("Sort : ");	b.TraverseList(&b, TraverseStr);	printf("\n");


	a.DeleteAllList( &a );	printf( "DeleteAll()\n" );
	printf( "Linear List Capacity = %d\n", a.GetCapacity( &a ) );
	printf( "Linear List Length = %d\n", a.GetLength( &a ) );

	a.DestroyList( &a );

	return 0;
}
