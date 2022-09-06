#ifndef __dlms_H
#define __dlms_H

namespace dlms {

enum class SecurityTypeEnum
{
    None       = 0x00,
    Low        = 0x01,
    Hight      = 0x02,
    Hight_GMAC = 0x05
};

} // dlms

#endif /*__dlms_H*/
