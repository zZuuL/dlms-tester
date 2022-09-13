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

    void setData(const QByteArray &data);
    QByteArray toData() const;

    void setFinal(bool final);
    bool isFinal() const;

    bool isValid() const;

    void setInfo(const QByteArray &info);
    QByteArray getInfo() const;

    hdlc::ControlType type() const;

private:
    bool parseFrameData_i(const QByteArray &data);

private:
    uint8_t addr_size;

    bool is_valid;
    bool is_final;
    QByteArray frame_data;
    QByteArray frame_info;
};

//---------------------------------------------------------------------------//


#endif /*__HdlcFrame_H*/
