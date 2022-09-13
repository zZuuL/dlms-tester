#include "HdlcConnection.h"


#include "HdlcFrame.h"

//---------------------------------------------------------------------------//

HdlcConnection::HdlcConnection(QObject *pObj/* = 0*/)
    : QObject(pObj)
    , logic_device(1)
    , address_size(1)
    , client_id(10)
    , recive_window_size(1)
    , send_window_size(1)
    , send_frame_size(128)
    , recive_frame_size(128)
    , send_keep_alive(true)
    , inactivity_timeout(120)
{
    QObject::connect(&socket, &QTcpSocket::disconnected, &socket, &QObject::deleteLater);
    QObject::connect(&socket, &QTcpSocket::readyRead, this, &HdlcConnection::socketReadyRead);
}


//---------------------------------------------------------------------------//


void HdlcConnection::setSettings(const DeviceSetting &setting)
{
    logic_device       = setting.logic_device;
    address_size       = setting.address_size;
    client_id          = setting.client_id;
    recive_frame_size  = setting.recive_frame_size;
    send_frame_size    = setting.send_frame_size;
    recive_window_size = setting.recive_window_size;
    send_window_size   = setting.send_window_size;
    send_keep_alive    = setting.send_keep_alive;
    inactivity_timeout = setting.inactivity_timeout;
}


//---------------------------------------------------------------------------//


void HdlcConnection::socketReadyRead()
{
    QByteArray data;
    if (readDataFromSocket_i(data)) {
        proccessReadData_i(data);
    }
}


//---------------------------------------------------------------------------//


bool HdlcConnection::readDataFromSocket_i(QByteArray &data)
{
    QByteArray tmp;

    quint64 need_read_bytes = socket.bytesAvailable();

    while (need_read_bytes > 0) {

        char buffer[1024];
        const qint64 readed_bytes = socket.read((char*)&buffer, sizeof(buffer));

        switch (readed_bytes) {

        case -1:  {
                return false;
            }

        default:  {
                tmp.append(QByteArray((const char*)&buffer, readed_bytes));
                need_read_bytes -= readed_bytes;
                if (0 == need_read_bytes) {
                    need_read_bytes = socket.bytesAvailable();
                }
            }
        }
    }

    data = tmp;
    return true;
}


//---------------------------------------------------------------------------//


void HdlcConnection::proccessReadData_i(const QByteArray &data)
{

}


//---------------------------------------------------------------------------//


