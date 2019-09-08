#ifndef SHUFFLE_H
#define SHUFFLE_H

#include <vector>
#include <assert.h>
#include <stdlib.h>
using namespace std;

int randint(int a, int b) // a >= 0, b >= 0
{
    assert(b >= a);

    if(a == b)
    {
        return a;
    }
    else
    {
        return rand() % (b - a) + a;
    }
}

void shuffle(vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        int r = randint(0, i);
        
        int temp = arr[i];
        arr[i] = arr[r];
        arr[r] = temp;
    }
}

#endif