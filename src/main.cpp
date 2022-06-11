#include "controllers/AppController.h"
#include "GimpApplication.h"
#include "memento/Caretaker.h"


int main() {

    //Creates an instance of the main application controller
    AppController appController;

    //Creates an instance of the GimpApplication with the Observer pattern applied on the main controller
    GimpApplication gimpApplication(appController);

    //Implements the Memento pattern in an Observer way on the main controller
    Caretaker caretaker(appController, &gimpApplication);

    //Gimp Application main loop
    gimpApplication.run();

    return 0;
}




