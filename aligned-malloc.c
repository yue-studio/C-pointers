#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void *aligned(int size, void **orig){
    void *mem;
    void *ptr;
    
    /* solution section begins*/
    mem = malloc(size + 0x100 - 1);
    ptr = (void *)(((uintptr_t)mem + 0x100) & ~(0xff));
    printf("0x%08" PRIXPTR ", 0x%08" PRIXPTR "\n", (uintptr_t)mem, (uintptr_t)ptr);
    
    *orig = mem;
    return ptr;
}

int main() {
 
    void *aligned_ptr;
    void *orig_ptr;

    aligned_ptr = aligned(1024, &orig_ptr);
    printf("return 0x%08" PRIXPTR "\n", (uintptr_t)aligned_ptr);
    /*solution section begins */
    printf("freeing 0x%08" PRIXPTR "\n", (uintptr_t)orig_ptr);
    free(orig_ptr);
}
