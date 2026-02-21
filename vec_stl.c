#include<stdio.h>
#include<stdlib.h>

typedef struct vec{
    int *arr;
    size_t size;
    size_t capacity;
}vec;

void vec_init(vec* v){
    v->size = 0;
    v->capacity = 2;

    v->arr = (int*) malloc(v->capacity * sizeof(int));
    if(v->arr == NULL){
        printf("failed");
        exit(1);
    }
}


void push_back(vec* v, int x){

    if(v->size == v-> capacity){
        v->capacity *= 2;
        int* temp = realloc(v->arr,v->capacity * sizeof(int));

        if(temp == NULL){
            printf("Memory allocation failed");
            return;
        }

        v->arr = temp;
    }
    v->arr[v->size] = x;
    v->size++;
}

void display(vec* v){
    for(size_t i = 0;i<v->size;i++){
        printf("%d\n",*(v->arr + i));
    }
}

void pop_back(vec* v){
    if(v->size > 0){
        size_t x = v->arr[v->size];
        v->size--;
    }
    else printf("Vector is empty");
}

void free_vec(vec* v){
    free(v->arr);
    v->arr = NULL;
    v->size = 0;
    v->capacity = 0;
    printf("memory freed");
}

int main(){
    vec v;
    vec_init(&v);
    push_back(&v, 5);
    push_back(&v, 15);
    push_back(&v, 25);

    display(&v);
    pop_back(&v);
    printf("updated\n");
    display(&v);
    free_vec(&v);

}