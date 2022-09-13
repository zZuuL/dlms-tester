#include "HdlcFrame.h"

namespace Internal {

inline size_t getMinimalPacketSize(uint8_t size)
{
    static const uint8_t min_size = 9;

    if (size == 2)
        return min_size + 1;
    return min_size;
}


inline bool checkHCSandFCS(size_t minimal_size, const QByteArray &data)
{
    return false;
}

}


//---------------------------------------------------------------------------//

HdlcFrame::HdlcFrame(uint8_t size)
    : is_final(true)
    , is_valid(true)
    , addr_size(size)
{}


//---------------------------------------------------------------------------//


HdlcFrame::HdlcFrame(uint8_t size, const QByteArray &data)
    : HdlcFrame(size)
{
    is_valid = parseFrameData_i(data);
}


//---------------------------------------------------------------------------//

void HdlcFrame::setData(const QByteArray &data)
{
    frame_data = data;
}

//---------------------------------------------------------------------------//


QByteArray HdlcFrame::toData() const
{
    QByteArray result;
    return result;
}

//---------------------------------------------------------------------------//


bool HdlcFrame::isValid() const
{
    return is_valid;
}


//---------------------------------------------------------------------------//


void HdlcFrame::setFinal(bool final)
{
    is_final = final;
}

//---------------------------------------------------------------------------//


bool HdlcFrame::isFinal() const
{
    return is_final;
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

// DM:
// 7E A0 08 21 00 41 1F 4D 09 7E
// UA:
// 7E A0 1F 00 41 21 93 A1 69 81 80 12 05 01 80 06 01 80 07 04 00 00 00 01 08 04 00 00 00 01 19 A9 7E
// AARE:
// 7E A0 38 21 02 41 30 D1 B1 E6 E7 00 61 29 A1 09 06 07 60 85 74 05 08 01 01 A2 03 02 01 00 A3 05 A1 03 02 01 00 BE 10 04 0E 08 00 06 5F 1F 04 00 00 10 10 04 00 00 07 36 E3 7E

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



    return true;
}


//---------------------------------------------------------------------------//
