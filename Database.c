#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "Database.h"
#include "To_do.h"


int load_from_file(struct task **a){//Function that takes a NULL struct task pointer and loads information from the todo.txt file

    FILE *fptr = fopen("todo.txt","r");//Open todo.txt file on read mode

    int index = 0;//Initalize int index variable to 0,keeping track how many tasks are being added to struct task pointer

    char temp[301];//A temp char array to read store information read from todo.txt file

    
    char temp_task[301-(sizeof("✓")+1)];//A temp char array to store task information

    while(fgets(temp,301,fptr)!=NULL){//Continue looping until file stops reading information

        struct task *temp_space = realloc(*a,sizeof(struct task)*(index+1));//expand the memory when reading a new task

        if (temp_space == NULL){//check for any realloc error
                perror("Realloc error");
                fclose(fptr);
                return -1;
            }
        *a = temp_space;


        sscanf(temp,"%d. |[%[^]]]|(%[^)])  %[^\n]",&(*a)[index].id,(*a)[index].completion,temp_task,(*a)[index].time_added);//Read file and store info into pointer


        char *temp_space_2  = malloc(strlen(temp_task)+1);//initalize memory space for task details in struct task pointer

        if (temp_space_2 == NULL){//check for malloc error
            perror("malloc error");
            fclose(fptr);
            return -1;

        }

        (*a)[index].details = temp_space_2;

        strcpy((*a)[index].details,temp_task);//copy information from the temp char array to the struct task pointer details variable

        index++;
        
    }

    

    fclose(fptr);//close file
    
    return index;
    

}




void save_to_file(struct task **a, int index){//Stores information from struct task **a into todo.txt file

    FILE *fptr = fopen("todo.txt.tmp","w");//Opens todo.txt.temp file on writing mode


    for (int i = 0; i<index;i++){
        fprintf(fptr,"%d. |[%s]|(%s)  %s\n",(*a)[i].id,(*a)[i].completion,(*a)[i].details,(*a)[i].time_added);//print info from struct task pointer into the todo.txt.temp file
    }

    if (fflush(fptr)!=0){//flush temporary text file to kernel
        perror("fflush error");
        return;
    }

    if (fsync(fileno(fptr))!=0){//fsync temporary text file to disc
        perror("fsync error");
        return;
    }

    if (rename("todo.txt.tmp","todo.txt")!=0){//rename the temp file to the todo.txt file used throughout the system
        perror("Rename error");
        return;
    }

    fclose(fptr);//close file
    return;



}