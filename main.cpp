#include "Sorts.h"
int main()
{
    Sorts s(5);
    s.append(8);
    s.append(5);
    s.append(7);
    s.append(3);
    s.append(2);
    s.bubbleSort();
    s.bubbleSort();
    s.show();
    return 0;
}
