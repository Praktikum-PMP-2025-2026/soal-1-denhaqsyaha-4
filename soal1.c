/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 4 - Dynamic Structures
 *   Hari dan Tanggal    : Senin, 4 Mei 2026
 *   Nama (NIM)          : Nahidl Denhaq Syaha
 *   Nama File           : Soal 1.c
 *   Deskripsi           : Menambah, menghapus, dan mencari data pada linked list sebanyak input pengguna
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int n;
    struct list* next;
    struct list* prev;
} list;

void pushlBack (list** head, int x);

void pushFront (list** head, int x);

void deltData (list** head, int x);

void findData (list** head, int x);

int main (void) {
    int loop;
    scanf("%d", &loop);
    int arr[loop*2];
    for (int i = 0; i < loop*2; i++) {
        scanf("%d", &arr[i]);
    }

    list* head = NULL;
    for (int i = 0; i < loop*2; i = i + 2) {
        if (arr[i] == 1) {
            pushFront (&head, arr[i + 1]);
        } else if (arr[i] == 2) {
            pushlBack (&head, arr[i + 1]);
        } else if (arr[i] == 3) {
            deltData (&head, arr[i + 1]);
        } else if (arr[i] == 4) {
            findData (&head, arr[i + 1]);
        }
    }
    list* temp = head;
    printf("LIST");
    if (temp != NULL) {
        while (temp != NULL) {
            printf(" %d", temp->n);
            temp = temp->next;
        }
    } else {
        printf(" EMPTY");
    }
}

void pushlBack (list** head, int x) {
    list* temp = *head;
    list* newl = (list*)malloc(sizeof(list));
    newl->n = x;
    newl->next = NULL;

    if (temp == NULL) {
        newl->prev = NULL;
        *head = newl;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newl->prev = temp;
        temp->next = newl;
    }
}

void pushFront (list** head, int x) {
    list* temp = *head;
    list* newl = (list*)malloc(sizeof(list));
    newl->n = x;
    newl->prev = NULL;

    if (temp == NULL) {
        newl->next = NULL;
        *head = newl;
    } else {
        newl->next = temp;
        temp->prev = newl;
        *head = newl;
    }
}

void deltData (list** head, int x) {
    list* temp = *head;
    int idx = 0;
    int sum = 0;
    while (temp != NULL) {
        sum++;
        temp = temp->next;
    }
    while (temp != NULL) {
        idx++;
        if (temp->n == x) {
            break;
        }
        temp = temp->next;
    }
    temp = *head;
    if (sum == 1 && idx == 1) {
        free(temp);
        *head = NULL;
    } else if (sum != 1 && idx == sum) {
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        list* dumy = temp->next;
        temp->next = NULL;
        free(dumy);
    } else if (sum != 1 && idx  ==  1) {
        *head = temp->next;
        temp->next = NULL;
        free(temp);
    } else if (sum != 1) {
        int count = 1;
            while ((idx - 1) != count) {
            temp = temp->next;
            count++;
        }
        list* delt = temp->next;
        list* aftr = delt->next;
        temp->next = aftr;
        delt->next = NULL;
        free(delt);
    }
}

void findData (list** head, int x) {
    list* temp = *head;
    int idx = -1;
    int con = -1;

    while (temp != NULL) {
        con++;
        if (temp->n == x) {
            idx = con;
            break;
        }
        temp = temp->next;
    }
    if (idx == -1) {
        printf("NOT FOUND\n");
    } else {
        printf("FOUND %d\n", idx);
    }
}
