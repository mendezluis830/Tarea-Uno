#include "list.h"
#include <stdio.h>
#include <stdlib.h>

list* create_list(){
    list *t;
    t = (list*)malloc(sizeof(list));
    t->head = NULL;
    t->num = 0;
    return t;
}

void delete_list(list *l){
    node *t1 = l->head;
    while(t1->next!=NULL){    
        node* t;
        for(t = l->head; t->next->next!=NULL; t= t->next);
        delete_node(t->next);
        t->next = NULL;
    }
    delete_node(t1);
    l->num =0;
    free(l);
}

// Funciones para agregar a la lista
bool add_init(list *l, DATA data){
    if(l == NULL) return false;
    if(l->head == NULL){
        l->head = create_node(data);
        l->num = 1;
        return true;
    }else{
        node *t = create_node(data);
        t->next = l->head;
        l->head = t;
        l->num++;
        return true;
    }
    return false;
}
bool add_end(list *l, DATA data){
    if(l==NULL) return false;
    node* t;
    for(t = l->head; t->next!=NULL; t= t->next);
    t->next = create_node(data);
    l->num++;
    return true;
}
bool add(list *l, DATA data, int pos){
    if(l==NULL) return false;
    if(pos == 0){
        return add_init(l, data);
    }else if(pos==l->num){
        return add_end(l, data);
    }else if( pos >0 && pos <l->num){
       node *t, *t1, *t2;
       int i;
       for(i=1, t = l->head; i<pos-1; i++,t= t->next); 
       t1 = t->next;
       t2 = create_node(data);
       t->next = t2;
       t2->next = t1;
       l->num++;
       return true;
    }else 
        return false;
}

// Función para eliminar un dato
bool remove_data(list *l, DATA data){
    if(l==NULL) return false;
    node *t = l->head, *t1, *t2;
    while(t!=NULL){
        if(t->next->data == data){
            break;
        }
        t= t->next;
    }
    t1 = t->next;//Nodo a borrar
    t2 = t1->next; //Siguiente del nodo a borrar
    t1->next = NULL;
    delete_node(t1);
    t->next = t2;
    return true;
}

// Funciones para eliminar por posición
DATA delete_init(list *l){
    if(l==NULL) return -1;
    if(l->head != NULL){
        node *t = l->head;
        int d = t->data;
        l->head = l->head->next;
        free(t);
        l->num--;
        return d;
    }
    return -1;
}

DATA delete_end(list *l){
    if(l==NULL) return -1;
    if(l->head != NULL){
        node *t = l->head;
        while(t->next !=NULL) t= t->next;
        int d = t->data;        
        free(t);
        l->num--;
        return d;
    }
    return -1;
}
DATA delete_data(list*l,int pos){
    int d;
    if(l==NULL) return -1;
    if(pos == 0){
        return delete_init(l);
    }else if(pos==l->num){
        return delete_end(l);
    }else if( pos >0 && pos <l->num){
       node *t, *t1, *t2;
       int i;
       for(i=1, t = l->head; i<pos-1; i++,t= t->next); 
       t1 = t->next;
       t2 = t1->next;
       t->next = t2;
       d = t1->data;
       free(t1);
       l->num--;
       return d;
    }else 
        return -1;
}

// Funciones para buscar
/*
 * @return la posición de un dato en la lista
 */
int search_data(list *l, DATA data){
    int pos;
    node *t;
    for(pos=0, t =l->head; data != t->data && t->next!=NULL; pos++,t=t->next);
    if(pos >=l->num) return -1;
    return pos;
}

DATA search_pos(list *l, int pos){
    node *t;
    int i;
    for(i=1, t = l->head; i==pos; i++,t= t->next); 
    if(t!=NULL) return t->data;
    return -1;
}
node *serch_node(list *l, DATA data);
