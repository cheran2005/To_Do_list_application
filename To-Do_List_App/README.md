# TO-DO LIST APPLICATION

a simple command line software that adds,view, marks,and deletes tasks

#RUN:(commands to run)

make

./to_do



#Features 
    -Add Task
    -Delete Task
    -Mark Task
    -View Task

#Concepts used
    -File handling
    -Structs
    -Arrays
    -Pointers and dynamic memory

#Project Structure


To-Do_List_App/
├── src/ # .c source files
│ ├── Main.c
│ ├── Database.c
│ ├── To_do.c
│ └── Utils.c
│
├── include/ # .h header files
│ ├── Database.h
│ ├── To_do.h
│ └── Utils.h
│
├── todo.txt # Saved tasks
├── Makefile # Build instructions
└── README.md