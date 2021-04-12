#ifndef NFD_CHECKER_H
#define NFD_CHECKER_H

#include <QObject>
#include <common.h>

class nfd_checker
{
public:
    nfd_checker();
    bool
    check();
private:
    void
    onData(const Interest& interest, const Data& data);
    void
    onNack(const Interest& interest, const Nack& nack);
    void
    onTimeout(const Interest& interest);

    Face m_face;
};

#endif // NFD_CHECKER_H
