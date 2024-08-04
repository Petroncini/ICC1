#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct book {
    char *title;
    char *author;
    int year;
    int quantity;
};

int in_catalog(char* title, struct book* catalog, int n);
void enter_catalog(struct book** catalog, int n, int *unique_books);
void print_catalog(struct book* catalog, int unique_books);
void free_memory(struct book* catalog, int unique_books);

int main(void){
    

    int n;
    scanf("%d", &n);
    getchar();
    getchar();

    struct book *catalog = malloc(sizeof(struct book));
    int unique_books = 0;

    enter_catalog(&catalog, n, &unique_books);
    print_catalog(catalog, unique_books);
    free_memory(catalog, unique_books);
    
}

void enter_catalog(struct book** catalog, int n, int *unique_books){
    for (int i = 0; i < n; i++)
    {   
        char line[300], title[100], author[100];
        int year;

        if (fgets(line, sizeof(line), stdin) == NULL) {
            fprintf(stderr, "Erro.\n");
            return;
        }
        
        
        line[strcspn(line, "\n")] = 0;

        sscanf(line, " %[^,], %[^,], %d", title, author, &year);

        if(in_catalog(title, *catalog, *unique_books)){
            continue;
        }
        if (unique_books > 0){
           *catalog = realloc(*catalog, (*unique_books + 1) * sizeof(struct book));
        }

        (*catalog)[*unique_books].title = malloc(sizeof(char) * (strlen(title)+1));
        strcpy((*catalog)[*unique_books].title, title);

        (*catalog)[*unique_books].author = malloc(sizeof(char) * (strlen(author)+1));
        strcpy((*catalog)[*unique_books].author, author);

        (*catalog)[*unique_books].year = year;

        (*catalog)[*unique_books].quantity = 1;

        (*unique_books)++;
    }
}

int in_catalog(char* title, struct book* catalog, int n){
    //printf("\n\nComparing %s:\n", title);
    for (int i = 0; i < n; i++)
    {
        //printf("and %s: %d\n", catalog[i].title, strcmp(title, catalog[i].title));
        if(strcmp(title, catalog[i].title) == 0){
            //printf("\nRead it: %s\n", title);
            catalog[i].quantity++;
            //printf("\n\n");
            return 1;
        }
    }
    //printf("\n\n");
    return 0;
}

void print_catalog(struct book* catalog, int unique_books){
    printf("Catalogo de Livros:\n");
     
    for (int i = 0; i < unique_books; i++)
    {
        printf("Livro %d:\n", i + 1);
        printf("Titulo: %s\n", catalog[i].title);
        printf("Autor: %s\n", catalog[i].author);
        printf("Ano: %d\n", catalog[i].year);
        printf("Quantidade: %d\n", catalog[i].quantity);

        if(i != unique_books - 1){
            printf("\n");
        }
    }
}

void free_memory(struct book* catalog, int unique_books){
    for (int i = 0; i < unique_books; i++)
    {
        free(catalog[i].title);
        free(catalog[i].author);
    }
    free(catalog);
}
