#include "controllers/AppController.h"
#include "GimpApplication.h"


int main() {

    //Creates an instance of the main application controller
    AppController appController;

    //Creates an instance of the GimpApplication with the Observer pattern applied on the main controller
    GimpApplication gimpApplication(appController);

    //Gimp Application main loop
    gimpApplication.run();

    return 0;
}




