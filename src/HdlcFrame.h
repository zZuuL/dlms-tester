#ifndef __HdlcFrame_H
#define __HdlcFrame_H

#include <QByteArray>

#include "HDLC.h"

//---------------------------------------------------------------------------//

class HdlcFrame
{
public:
    HdlcFrame(uint8_t size);
    HdlcFrame(uint8_t size, const QByteArray &data);

    QByteArray toData() const;

    void setFinal(bool final);
    bool isFinal() const;

    void setLogicalDevice(uint8_t value);
    uint16_t getLogicalDevice() const;

    void setDeviceid(uint8_t value);
    uint16_t getDeviceId() const;

    void setClientId(uint8_t value);
    uint16_t getClientId() const;

    bool isValid() const;

    void setInfo(const QByteArray &info);
    QByteArray getInfo() const;

    hdlc::ControlType type() const;

private:
    bool parseFrameData_i(const QByteArray &data);

private:
    bool    is_valid;
    uint8_t addr_size;
    
    uint16_t format;
    uint8_t  logical_device;
    uint8_t  device_id;
    uint8_t  client_id;
    uint8_t  control;

    QByteArray frame_info;
};

//---------------------------------------------------------------------------//


#endif /*__HdlcFrame_H*/
