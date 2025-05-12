#include <stdio.h>
#include <stdlib.h>
#include "To_do.h"
#include "Utils.h"
#include "Database.h"
#include <time.h>
#include <string.h>


void add_task(){//Adds task to file


    struct task *a=NULL;//Initalize a struct task pointer to be NULL 

    char temp_task[301-(sizeof("✓")+1)];//Initalize a temp array to store the details of the task 

    int index = load_from_file(&a);//Load all previous tasks from the todo.txt file into the NULL struct task pointer

    if (index == -1){//If load_from_file returns error code, end function
        return;
    }
    
    struct task *temp_space_1 = realloc(a,sizeof(struct task)*(index+1));//Use a temporary struct task pointer to reallocate memory for pointer a and avoid any memory leak

    time_t current_time = time(NULL);//initalize a type time variable and setting up the time so when user adds tasks, date and time tracked
    struct tm *local = localtime(&current_time);

    if (temp_space_1 == NULL){//check for realloc error

        perror("Realloc error");
        Free_memory(&a,index);
        return;
        
    }

    a = temp_space_1;//set the temp space as the struct pointer which is now reallocated safely


    Clear_buffer();//clear any input buffer

    printf("Enter task: ");//ask user to enter new task
    fgets(temp_task,301-(sizeof("✓")+1),stdin);//store user response in a temp_task temporary char array

    temp_task[strcspn(temp_task,"\n")] = 0;//remove \n created after user presses enter in the response

    a[index].id = index+1;//add id of task

    char *temp_space = malloc(strlen(temp_task)+1);//Allocate memory for details

    if (temp_space == NULL){//check for malloc error
        perror("Malloc Error");
        Free_memory(&a,index);
        return;
    }

    a[index].details = temp_space;//set the temp space as the space for the details pointer in the struct task pointer a

    strcpy(a[index].details,temp_task);//copy information from the temporary char array to pointer a
    

    strcpy(a[index].completion, " ");//make the completion incomplete

    strftime(a[index].time_added,sizeof(a[index].time_added),"%Y-%m-%d %H:%M:%S",local);//initalize the time the task is added

    index++;//increase index to track how many tasks have been added

    save_to_file(&a,index);//save the new task to the file

    Free_memory(&a,index);//free the memory after saving to the todo.txt file

    return;





}



void view_tasks(){//Prints all tasks to user

    struct task *a = NULL;//Initalize a NULL struct task pointer

    int index = load_from_file(&a);//load the pointer with all the information from the todo.txt file

    if (index == -1){//If load_from_file returns error code, end function
        return;
    }

    for (int i = 0;i<index;i++){
        printf("%d. |[%s]|(%s)  %s\n",a[i].id,a[i].completion,a[i].details,a[i].time_added);//print tasks

    }

    Free_memory(&a,index);//free memory allocated from struct task pointer
    
    return;

   
}



void Mark_task(int id){//Marks task based on the task id

    struct task *a = NULL;//Initalize a NULL struct task pointer

    int index = load_from_file(&a);//load the pointer with all the information from the todo.txt file

    if (index == -1){//If load_from_file returns error code, end function
        return;
    }

    for (int i =0;i<index;i++){//checks if id exists in the now loaded struct tast *a pointer

        if (id == a[i].id){//if id exists, sets that task completed, saves this new change to the file and frees memory

            strcpy(a[i].completion,"✓");
            save_to_file(&a,index);
            Free_memory(&a,index);
            return;
            
        }


    }

    fprintf(stderr,"Invalid id\n");//if no id is found matching then the user gets an error for invalid id
    Free_memory(&a,index);//frees allocated memory from struct task pointer *a
    return;

}



void Delete_task(int id){//based on task id, deleted task

    struct task *a = NULL;//Initalize a NULL struct task pointer

    int index = load_from_file(&a);//load the pointer with all the information from the todo.txt file

    if (index == -1){//If load_from_file returns error code, end function
        return;
    }

    if (id == 1 && index == 1){//check if there is only one task and delete it
        free(a[0].details);
        free(a);
        
        a = NULL;

        save_to_file(&a,0);//save changes to file

        return;

    }


    for (int i =0;i<index;i++){//for loop to find matching id from *a pointer loaded by file with int id 

        
        if (id == a[i].id){//if id does match, move all values beisde the deleted task one index to the left
            
            for (int j = i;j<index-1;j++){

                strcpy(a[j].completion,a[j+1].completion);
                strcpy(a[j].time_added,a[j+1].time_added);
                free(a[j].details);
                a[j].details = malloc(strlen(a[j+1].details)+1);
                strcpy(a[j].details, a[j+1].details);

            }

            free(a[index-1].details);//free extra space left after deleting task

            index--;//lower amount of task by one

            struct task *temp_space = realloc(a,sizeof(struct task)*(index));//reallocate the entire *a pointer since a task has been deleted
            if (temp_space == NULL){
                perror("Realloc error");
                return;
            }
            a = temp_space;

            save_to_file(&a,index);//save changes to file

            Free_memory(&a,index);//free memory
            return;
            
        }


    }

    fprintf(stderr,"Invalid id\n");//if no id is found then output error in the terminal for invalid id

    Free_memory(&a,index);//free memory from *a pointer

    return;



}




