#include <stdio.h>
#include <string.h>
#include "headers/abonent.h"

int find_free_abonent(struct abonent abonents[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    struct abonent* abonent = &abonents[i];
    if (strcmp(abonent->name, "") == 0 && strcmp(abonent->second_name, "") == 0 
      && strcmp(abonent->second_name, "") == 0) {
      return i; 
    }
  }
  return -1;
}

int add_abonent(struct abonent abonents[SIZE], char name[STR_SIZE], 
                char second_name[STR_SIZE], char tel[STR_SIZE]) {
  int index = find_free_abonent(abonents);

  if (index == -1)
    return index;
  
  struct abonent* abonent = &abonents[index];

  strcpy(abonent->name, name);
  strcpy(abonent->second_name, second_name);
  strcpy(abonent->tel, tel);
  return 0;
}

void delete_abonent(struct abonent* abonent) {
  strcpy(abonent->name, "");
  strcpy(abonent->second_name, "");
  strcpy(abonent->tel, "");
}

void delete_abonent_by_params(struct abonent abonents[SIZE], char name[STR_SIZE], 
                              char second_name[STR_SIZE], char tel[STR_SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    if (strcmp(abonents[i].name, name) == 0 && strcmp(abonents[i].second_name, second_name) == 0 
      && strcmp(abonents[i].tel, tel) == 0) {
      delete_abonent(&abonents[i]);
    }  
  } 
}

void find_abonents_by_name(struct abonent abonents[SIZE], char name[STR_SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    if (strcmp(abonents[i].name, name) == 0) {
      print_abonent(&abonents[i]);
    }
  }
}

void print_abonent(struct abonent *abonent) {
  printf("___Abonent___\n");
  printf("Abonent name: %s\n", abonent->name);
  printf("Abonent second_name: %s\n", abonent->second_name);
  printf("Abonent tel: %s\n", abonent->tel);
  printf("\n");
}

void print_all_abonents(struct abonent abonents[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    struct abonent abonent = abonents[i];
    if (strcmp(abonent.name, "") != 0 && strcmp(abonent.second_name, "") != 0 
      && strcmp(abonent.second_name, "") != 0) {
      print_abonent(&abonent);
    }
  }
}
