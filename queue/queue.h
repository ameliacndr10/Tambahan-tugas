#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct infotype {
    string namaDok;
    string namaPengguna;
    int hal; 
};

typedef struct elmQ *address;
struct elmQ {
    infotype info;
    address next;
};

// Type queue
struct queue {
    address head;
    address tail;
};

address createNewElm(infotype x);

void createQueue(queue &Q);
bool isEmpty(queue Q);
void enqueue(queue &Q, address p);
void dequeue(queue &Q, address &p);


int countUserDocs(queue Q, string nama);


void antriPrinter(queue &Q, infotype doc);

void simulasiCetak(queue &Q, int &kertas);

void displayQueue(queue Q);

#endif