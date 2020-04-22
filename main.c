#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main (){
    list *l;
    l=create_list();
    add_init(l , 0, 1);
    add_end(l , 3,1);
    print_list(l);
    serach_data(l,3);
    delete_init(l,1);
    delete_data(l);
    l=NULL;
    return 0;


}
