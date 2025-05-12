#ifndef To_do_h
#define To_do_h


struct task{

    int id;

    char completion[sizeof("✓")+1]; 

    char *details;

    char time_added[100];
 
};

void add_task();

void view_tasks();


void Mark_task(int id);

void Delete_task(int id);



#endif