#include <iostream>
#include "./Mazo.h"
#include "./Mano.h"


using namespace std;
int main(){
    
    srand(time(0));
    Mazo mazo1;
    mazo1.mostrar();

    mazo1.barajar();
    cout<<" "<<endl;
    mazo1.mostrar();

    Mano mano;
    

    mazo1.repartir();
    //mano.mostrar();
    
    return 0;
}
