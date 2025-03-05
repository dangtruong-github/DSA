#include <stdio.h>
#include <stdlib.h>

void mallocExample () {
    /*
        Malloc: create memory space
    */
    int size_ptr_malloc = 4;
    int* ptr_malloc;

    ptr_malloc = (int*) malloc (size_ptr_malloc * sizeof(int));

    if (ptr_malloc == NULL) {
        printf("Memory not allocated\n");
    } else {
        for (int i = 0; i < size_ptr_malloc; i++) {
            ptr_malloc[i] = i * 3;
        }

        for (int i = 0; i < size_ptr_malloc; i++) {
            printf("%d ", ptr_malloc[i]);
        }
        printf("\n");
    }
}


void callocExample () {
    /*
        Calloc: create memory space
    */
    
}


void freeExample () {
    /*
        Free: free up memory space
    */
}


void reallocExample () {
    /*
        Realloc: Reallocate space, change array size, etc.
    */
}


int main() {
    printf("\n\n");

    mallocExample();

    return 0;
}