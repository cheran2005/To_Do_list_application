#include <stdlib.h>
#include <stdio.h>
#include "To_do.h"
#include <stdbool.h>

int main(){
    int choice;//int variable to track user choices

    bool loop = true;//keep menue looping to user

    int id;//temporary int variable to track user input on task id
    
    
    while(loop){
        //print menue to user
        printf("\t\tTo-Do List App\n");
        printf("----------------------------------------------\n\n");
        printf("1. Add task\n");
        printf("2. View task\n");
        printf("3. Mark Task as Done\n");
        printf("4. Delete task\n");
        printf("5. Exit\n");

        //ask user for choice
        printf("Enter Choice Number: ");

        if (scanf("%d",&choice)==0){
            fprintf(stderr,"invalid input");
        }

        switch(choice){

            case 1:
                //Add Task
                printf("\t\tAdd Task\n");
                printf("--------------------------------\n\n");
                add_task();
                printf("\n");
                break;
            

            case 2:
                //View task
                printf("\t\tView Task\n");
                printf("--------------------------------\n\n");
                view_tasks();
                printf("\n");
                break;


            case 3:
                //Mark Task as Done
                printf("\t\tMarking Task\n");
                printf("--------------------------------\n\n");
                printf("Enter task number:");

                if (scanf("%d",&id)==0){//ask user for task number to then mark task in Mark_task function
                    fprintf(stderr,"Invalid task number");
                    break;
                }

                Mark_task(id);
                break;
            
                

            case 4:
                //Deleting Task
                printf("\t\tDelete task\n");
                printf("--------------------------------\n\n");
                printf("Enter task number:");

                if (scanf("%d",&id)==0){//ask user for task number to then user Delete_task function to delete task
                    fprintf(stderr,"Invalid task number");
                    break;
                }
    
                Delete_task(id);
                break;

                
            case 5:
                //Exit Application
                printf("\t\tExiting Application\n");
                printf("---------------------------------------------------------\n\n");
                loop = false;//End loop to exit application
                break;

        }
    }


    return 0;
}
