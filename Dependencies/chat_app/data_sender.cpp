#include "data_sender.h"

data_sender::data_sender()
{
}
    void
    data_sender::run(){
        try{
            face.processEvents();
        }
        catch (std::runtime_error& e) {

std::cout<<"Errorin data sender"<<std::endl;
             }
    }
