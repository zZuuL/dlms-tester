#ifndef __HdlcConnectionPool_H
#define __HdlcConnectionPool_H

#include <QMap>
#include <QObject>

#include "DeviceSetting.h"
#include "HdlcConnection.h"

class HdlcConnectionPool : public QObject
{
    Q_OBJECT

    typedef QMap<int, HdlcConnection*> Connection_m;

public:
    HdlcConnectionPool();
    int addConnection(const DeviceSetting& setting);
    void modifyConnection(int id, const DeviceSetting& setting);
    bool removeConnection(int id);
    bool connect(int id);
    bool disconnect(int id);

private:
    Connection_m connections;
};


#endif /*__HdlcConnectionPool_H*/
