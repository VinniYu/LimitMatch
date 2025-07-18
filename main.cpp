
#include "SETTINGS.h"
#include "order/ORDER.h"
#include "event/EVENT.h"

using namespace std;



// forward declarations for main
void runOnce();
void runLoop();

// simulation parameters
int maxTimesteps = 100;

int main(int argc, char* argv[]) {

    // set up 
    runOnce();

    // run sim
    for (int i = 0; i < maxTimesteps; i++)      
        runLoop();
    
    return 0;
}

void runOnce() {
    // seed RNG
    srand(static_cast<unsigned>(time(nullptr)));

    Order o = createRandomOrder(0);

    OrderSubmittedEvent event(o);


    
    cout << "Event type: " << event.getType() << endl;
    event.getOrder().printOrder();
}

void runLoop() {

}