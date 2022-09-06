#ifndef __devicesetting_H
#define __devicesetting_H

#include <string>
#include <cstdint>

#include "hdlc.h"
#include "dlms.h"


//---------------------------------------------------------------------------//

struct DeviceSetting
{
    //main
    std::string            name;
    uint16_t               logic_device;
    uint16_t               server_address;
    std::string            low_password;
    std::string            higth_password;
    uint8_t                address_size;
    dlms::SecurityTypeEnum security;
    uint8_t                client_id;

    //hdlc
    uint16_t               recive_frame_size;
    uint16_t               send_frame_size;
    uint8_t                recive_window_size;
    uint8_t                send_window_size;
    bool                   send_keep_alive;
    uint16_t               inactivity_timeout;

    //lan
    std::string            ip;
    uint16_t               port;

    DeviceSetting()
        : name("")
        , logic_device(1)
        , server_address(32)
        , low_password("Reader")
        , higth_password("Configurator")
        , address_size(1)
        , security(dlms::SecurityTypeEnum::Hight)
        , client_id((uint8_t)hdlc::ClientIdEnum::Configurator)
        , recive_frame_size(128)
        , send_frame_size(128)
        , recive_window_size(1)
        , send_window_size(1)
        , send_keep_alive(true)
        , inactivity_timeout(120)
        , ip ("127.0.0.1")
        , port(5555)
    {}
};

//---------------------------------------------------------------------------//

#endif /*__devicesetting_H*/
