#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//int* arr;
	//
	//int size;
	//scanf_s("%d", &size);
	//
	//arr = (int*)malloc(size * sizeof(int));
	//
	//for (int i = 0; i < size; i++)
	//	arr[i] = i;
	//
	//for (int i = 0; i <= size; i++)
	//	printf("%d\n", arr[i]);
	//
	//free(arr);

	//int sizeX, sizeY;
	//scanf_s("%d %d", &sizeX, &sizeY);
	//
	//int** arr;
	//arr = (int**)malloc(sizeof(int*) * sizeX);
	//
	//for (int i = 0; i < sizeX; i++)
	//	arr[i] = (int*)malloc(sizeof(int) * sizeY);
	//
	//for (int i = 0; i < sizeX; i++)
	//{
	//	for (int j = 0; j < sizeY; j++)
	//		printf("%d", i + j);
	//	printf("\n");
	//}
	//
	//for (int i = 0; i < sizeX; i++)
	//	free(arr[i]);
	//
	//free(arr);

	//char temp[100];
	//
	//printf("Name : ");
	//gets_s(temp, sizeof(temp));
	//
	//char* name = (char*)malloc(strlen(temp) + 1);
	//
	//if (name)
	//	strcpy_s(name, strlen(temp) + 1, temp);
	//
	//printf("%s\n", name);
	//
	//free(name);
}

/*
* 동적할당
*	- 데이터 영역과 스택 영역에 할당되는 메모리의 크기는 컴파일 타임에 미리 결정됨
*	- 힙 영역의 크기는 프로그램이 실행되는 도중인 런 타임에 사용자가 직접 결정하게 됨
*	- 이렇게 런 타임에 메모리를 할당받는 것을 메모리 동적할당 이라고 함
*/