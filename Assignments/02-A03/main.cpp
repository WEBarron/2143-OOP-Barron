/*****************************************************************************
 *
 *  Author:           Wes Barron
 *  Email:            wesley.e.barron@gmail.com
 *  Label:            A03
 *  Title:            Basic Project Organization
 *  Course:           CMPS 2143
 *  Semester:         Fall 2022
 *
 *  Description:
 *        This program tests the implementation of a class that creates a circular
 *        array queue.
 *
 *  Usage:
 *        Run program to see the values pushed to the queue printed on the screen.
 *
 *  Files:
 *        main.cpp    : Driver program
 *        banner.txt  : Cover page to be turned in with program
 *****************************************************************************/

#include <iostream>

using namespace std;

/**
 * CircularArrayQue
 *
 * Description:
 *        The class overloads the "<<" (output operator) to allow for
 *        printing the contents of the array queue. It also creates a function to
 *        initialize the parameters of the array.
 *
 * Public Methods:
 *      
 *
 * Private Methods:
 *      void            _init
 *      bool            _Full
 *
 * Usage:
 *      
 *
 */

class CircularArrayQue
{
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
    void init(int size = 0)
    {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    bool Full()
    {
        return CurrentSize == QueSize;
    }

public:
    CircularArrayQue()
    {
        Container = new int[10];
        init(10);
    }

    CircularArrayQue(int size)
    {
        Container = new int[size];
        init(size);
    }

    void Push(int item)
    {
        if (!Full())
        {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        }
        else
        {
            cout << "FULL!!!!" << endl;
        }
    }

    int Pop()
    {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }

    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

ostream &operator<<(ostream &os, const CircularArrayQue &other)
{

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize)
    {
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
int main()
{
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