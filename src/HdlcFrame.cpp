#include "HdlcFrame.h"
#include "crc.h"

namespace Internal {

//===========================================================================//


inline size_t getMinimalPacketSize(uint8_t size)
{
    static const uint8_t min_size = 10;

    if (size == 2)
        return min_size + 1;
    return min_size;
}


//---------------------------------------------------------------------------//


inline bool chekCrc16(const QByteArray &data, size_t size)
{
    const char* begin = std::next(data.data());
    const char* end   = std::next(data.data(), size - 3);
    const uint16_t crc = hdlc::makeCrc(begin, end);

    const char* tmp = std::next(data.begin(), size - 3);
    uint16_t orig_crc = 0x0000;
    orig_crc |= (0xFF & *tmp++) << 8;
    orig_crc |= 0xFF & *tmp;

    return crc == orig_crc;
}


//---------------------------------------------------------------------------//


inline bool checkHCSandFCS(size_t minimal_size, const QByteArray &data)
{
    bool result = false;

    if (data.size() >= minimal_size) {
        result = chekCrc16(data, minimal_size);
        if (result && data.size() > minimal_size)  {
            result = chekCrc16(data, data.size());
        }
    }

    return result;
}


//===========================================================================//

}

//---------------------------------------------------------------------------//

HdlcFrame::HdlcFrame(uint8_t size)
    : is_valid(true)
    , addr_size(size)
    , format(0)
    , logical_device(0)
    , device_id(0)
    , client_id(0)
    , control(0)
{}


//---------------------------------------------------------------------------//


HdlcFrame::HdlcFrame(uint8_t size, const QByteArray &data)
    : HdlcFrame(size)
{
    is_valid = parseFrameData_i(data);
}


//---------------------------------------------------------------------------//


void HdlcFrame::setLogicalDevice(uint8_t value)
{
    logical_device = value;
}


//---------------------------------------------------------------------------//


uint16_t HdlcFrame::getLogicalDevice() const
{
    return logical_device;
}


//---------------------------------------------------------------------------//


void HdlcFrame::setDeviceid(uint8_t value)
{
    device_id = value;
}


//---------------------------------------------------------------------------//


uint16_t HdlcFrame::getDeviceId() const
{
    return device_id;
}


//---------------------------------------------------------------------------//


void HdlcFrame::setClientId(uint8_t value)
{
    client_id = value;
}


//---------------------------------------------------------------------------//


uint16_t HdlcFrame::getClientId() const
{
    return client_id;
}


//---------------------------------------------------------------------------//


bool HdlcFrame::isValid() const
{
    return is_valid;
}


//---------------------------------------------------------------------------//


void HdlcFrame::setFinal(bool final)
{
    hdlc::Format f{ format };
    f.s = final;
    format = f.value;
}

//---------------------------------------------------------------------------//


bool HdlcFrame::isFinal() const
{
    hdlc::Format f{ format };
    return f.s == 0;
}


//---------------------------------------------------------------------------//

void HdlcFrame::setInfo(const QByteArray &info)
{
    frame_info = info;
}


//---------------------------------------------------------------------------//

QByteArray HdlcFrame::getInfo() const
{
    return frame_info;
}

//---------------------------------------------------------------------------//

hdlc::ControlType HdlcFrame::type() const
{
    unsigned  char control = 0x00;

    struct ControlByte  {
        uint8_t b1 : 1;
        uint8_t b2 : 1;
        uint8_t b3 : 1;
        uint8_t b4 : 1;
        uint8_t b5 : 1;
        uint8_t b6 : 1;
        uint8_t b7 : 1;
        uint8_t b8 : 1;
    }* byte = (ControlByte*)&control;

    if(byte->b1 == 0)
    {
        return hdlc::ControlType::I;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 0 &&
            byte->b3 == 0 &&
            byte->b4 == 0)
    {
        return  hdlc::ControlType::RR;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 0 &&
            byte->b3 == 1 &&
            byte->b4 == 0)
    {
        return  hdlc::ControlType::RNR;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 0 &&
            byte->b3 == 0 &&
            byte->b4 == 1)
    {
        return  hdlc::ControlType::REJ;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 0 &&
            byte->b3 == 1 &&
            byte->b4 == 1)
    {
        return  hdlc::ControlType::SREJ;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 0 &&
            byte->b4 == 0 &&
            byte->b6 == 0 &&
            byte->b7 == 0 &&
            byte->b8 == 0)
    {
        return  hdlc::ControlType::UI;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 0 &&
            byte->b4 == 0 &&
            byte->b6 == 0 &&
            byte->b7 == 0 &&
            byte->b8 == 1)
    {
        return  hdlc::ControlType::SNRM;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 0 &&
            byte->b4 == 0 &&
            byte->b6 == 0 &&
            byte->b7 == 1 &&
            byte->b8 == 0)
    {
        return  hdlc::ControlType::DISC;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 0 &&
            byte->b4 == 0 &&
            byte->b6 == 1 &&
            byte->b7 == 0 &&
            byte->b8 == 0)
    {
        return  hdlc::ControlType::UP;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 0 &&
            byte->b4 == 0 &&
            byte->b6 == 1 &&
            byte->b7 == 1 &&
            byte->b8 == 0)
    {
        return  hdlc::ControlType::UA;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 0 &&
            byte->b4 == 0 &&
            byte->b6 == 1 &&
            byte->b7 == 1 &&
            byte->b8 == 1)
    {
        return  hdlc::ControlType::TEST;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 1 &&
            byte->b4 == 0 &&
            byte->b6 == 0 &&
            byte->b7 == 0 &&
            byte->b8 == 0)
    {
        return  hdlc::ControlType::SIM;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 1 &&
            byte->b4 == 0 &&
            byte->b6 == 0 &&
            byte->b7 == 0 &&
            byte->b8 == 1)
    {
        return  hdlc::ControlType::FRMR;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 1 &&
            byte->b4 == 1 &&
            byte->b6 == 0 &&
            byte->b7 == 0 &&
            byte->b8 == 0)
    {
        return  hdlc::ControlType::DM;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 1 &&
            byte->b4 == 1 &&
            byte->b6 == 0 &&
            byte->b7 == 0 &&
            byte->b8 == 1)
    {
        return  hdlc::ControlType::RSET;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 1 &&
            byte->b4 == 1 &&
            byte->b6 == 0 &&
            byte->b7 == 1 &&
            byte->b8 == 0)
    {
        return  hdlc::ControlType::SARME;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 1 &&
            byte->b4 == 1 &&
            byte->b6 == 0 &&
            byte->b7 == 1 &&
            byte->b8 == 1)
    {
        return  hdlc::ControlType::SNRME;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 1 &&
            byte->b4 == 1 &&
            byte->b6 == 1 &&
            byte->b7 == 0 &&
            byte->b8 == 0)
    {
        return  hdlc::ControlType::SABM;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 1 &&
            byte->b4 == 1 &&
            byte->b6 == 1 &&
            byte->b7 == 0 &&
            byte->b8 == 1)
    {
        return  hdlc::ControlType::XID;
    }
    else if(byte->b1 == 1 &&
            byte->b2 == 1 &&
            byte->b3 == 1 &&
            byte->b4 == 1 &&
            byte->b6 == 1 &&
            byte->b7 == 1 &&
            byte->b8 == 0)
    {
        return  hdlc::ControlType::SABME;
    }

    return hdlc::ControlType::UNDEFINED;
}


//---------------------------------------------------------------------------//


bool HdlcFrame::parseFrameData_i(const QByteArray &data)
{
    const size_t minimal_size = Internal::getMinimalPacketSize(addr_size);

    if (data.size() < minimal_size)
        return false;

    if (*data.begin() != hdlc::Flag || *data.rbegin() != hdlc::Flag)
        return false;

    if (!Internal::checkHCSandFCS(minimal_size, data))
        return false;

    const char* byte_data = std::next(data.data());

    format |= (0xFF & *byte_data++) << 8;
    format |=  0xFF & *byte_data++;

    const hdlc::Format f{ format };
    if (f.size != data.size() - 2 || f.ftype != 0b00001010)
        return false;

    client_id      |= (0xFF & *byte_data++) >> 1;
    logical_device |= (0xFF & *byte_data++) >> 1;
    device_id      |= (0xFF & *byte_data++) >> 1;

    control = *byte_data++;

    if (data.size() > minimal_size)  {
        frame_info = QByteArray(
                        std::next(data.begin(), minimal_size - 1),
                        data.size() - minimal_size - 2);
    }

    return true;
}


//---------------------------------------------------------------------------//

QByteArray HdlcFrame::toData() const
{
    QByteArray result;
    return result;
}


//---------------------------------------------------------------------------//

