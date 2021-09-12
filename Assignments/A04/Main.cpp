/*****************************************************************************
*                    
*  Author:           Wesley Barron
*  Email:            wesley.e.barron@gmail.com
*  Label:            A04
*  Title:            Basic Project Organization
*  Course:           CMPS 2143
*  Semester:         Fall 2021
* 
*  Description:
*        This program implements a list data structure that links together nodes of integers. 
* 
*  Usage:
*       - This program does not require any non standard libraries.
* 
*  Files:            (list of all source files used in this program)
*  Main.cpp         : Driver Program
*****************************************************************************/
#include <iostream>

using namespace std;

//Creating class for a circular array queue

class CircularArrayQue {
//Creates private methods and variables

private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }
    // Checks if queue is full

    bool Full() {
        return CurrentSize == QueSize;
    }
//Creates public methods

public:
    //Constructor to create array queue

    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }
    //Creating dynamic size

    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }
    //Adds data to queue

    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }
    //Removes data from queue
    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }

    // friending ostream so it can access this classes private data members
    
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

// Overloading ostream so this array can be printed to stdout (or files)
// simply by using something similar to : cout << ClassInstance << endl;

ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}