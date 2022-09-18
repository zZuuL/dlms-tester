#ifndef __HdlcConnection_H
#define __HdlcConnection_H

#include <QByteArray>
#include <QTcpSocket>

#include "DeviceSetting.h"

//---------------------------------------------------------------------------//


class HdlcConnection : public QObject
{
    Q_OBJECT

public:
    explicit HdlcConnection(int id, QObject *pObj = 0);
    void setSettings(const DeviceSetting &setting);
    bool connect();
    bool disconnect();

private:
    bool readDataFromSocket_i(QByteArray &data);
    void proccessReadData_i(const QByteArray &data);

private slots:
    void socketReadyRead();

private:
    QTcpSocket socket;

    QByteArray read_buffer;
    QByteArray write_buffer;

    uint16_t logic_device;
    uint8_t  address_size;
    uint8_t  client_id;
    uint16_t recive_frame_size;
    uint16_t send_frame_size;
    uint8_t  recive_window_size;
    uint8_t  send_window_size;
    bool     send_keep_alive;
    uint16_t inactivity_timeout;
};

//---------------------------------------------------------------------------//


#endif /*__HdlcConnection_H*/
