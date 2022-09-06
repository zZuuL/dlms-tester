#ifndef __hdlc_H
#define __hdlc_H


namespace hdlc {

enum class ClientIdEnum
{
    PublicClient = 0x10,
    Reader       = 0x20,
    Configurator = 0x30
};

} // hdlc

#endif /*__hdlc_H*/
