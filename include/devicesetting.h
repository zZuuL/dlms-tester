#ifndef __devicesetting_H
#define __devicesetting_H

#include <string>
#include <cstdint>

//---------------------------------------------------------------------------//

enum class SecurityTypeEnum
{
    None       = 0x00,
    Low        = 0x01,
    Hight      = 0x02,
    Hight_GMAC = 0x05
};

//---------------------------------------------------------------------------//

enum class ClientIdEnum
{
    PublicClient = 0x10,
    Reader       = 0x20,
    Configurator = 0x30
};

//---------------------------------------------------------------------------//

struct DeviceSetting
{
    //main
    std::string      name;
    uint16_t         logic_device;
    uint16_t         server_address;
    uint8_t          address_size;
    SecurityTypeEnum security;
    uint8_t          client_id;
    //hdlc
    uint16_t         recive_frame_size;
    uint16_t         send_frame_size;
    uint8_t          recive_window_size;
    uint8_t          send_window_size;
    bool             send_keep_alive;
    uint16_t         inactivity_timeout;
    //lan
    std::string      ip;
    uint16_t         port;

    DeviceSetting()
        : name("")
        , logic_device(1)
        , server_address(32)
        , address_size(1)
        , security(SecurityTypeEnum::None)
        , client_id((uint8_t)ClientIdEnum::PublicClient)
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
