#ifndef ABONENT_H
#define ABONENT_H

#define SIZE 100
#define STR_SIZE 10

struct abonent {
  char name[STR_SIZE];
  char second_name[STR_SIZE];
  char tel[STR_SIZE];
};

int add_abonent(struct abonent abonents[SIZE], char name[STR_SIZE], char second_name[STR_SIZE], char tel[STR_SIZE]);
void delete_abonent_by_params(struct abonent abonents[SIZE], char name[STR_SIZE], char second_name[STR_SIZE], char tel[STR_SIZE]); 
void find_abonents_by_name(struct abonent abonents[SIZE], char name[STR_SIZE]);
void print_abonent(struct abonent *abonent);
int find_free_abonent(struct abonent abonents[SIZE]);
void print_all_abonents(struct abonent abonents[SIZE]);
void delete_abonent(struct abonent* abonent);

#endif // !ABONENT_H
