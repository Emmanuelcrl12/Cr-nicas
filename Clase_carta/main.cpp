#include <iostream>
#include "./mazo.h"

int main()
{
     srand(time(0));
    mazo mazo1;
mazo1.mostrar();

mazo1.barajar();
cout<<" "<<endl;
mazo1.mostrar();
    return 0;
}
