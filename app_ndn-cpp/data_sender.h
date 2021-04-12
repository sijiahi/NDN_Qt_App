#ifndef DATA_SENDER_H
#define DATA_SENDER_H
#include <QThread>
#include "common.h"
class data_sender:QThread
{
public:
    data_sender();
    void run();
     ndn::Face face;
private:

    bool isSet;

};

#endif // DATA_SENDER_H
