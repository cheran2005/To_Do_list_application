#include <stdio.h>
#include <stdlib.h>
#include "Utils.h"
#include "To_do.h"


void Clear_buffer(){//Clears input buffer so remaining values inside input buffer does not interfere with application
    int c;

    while ((c = getchar())!='\n' && c != EOF);//A while loop to keep clearing input bufer until there is nothing left

}


void Free_memory(struct task **a, int index){//Frees the memory from the struct task pointer

    for (int i = 0;i<index;i++){//For the amount of tasks inside the struct task pointer, free the detail pointers

        free((*a)[i].details);
    }

    
    free(*a);//Free entire allocated memory inside the pointer


}