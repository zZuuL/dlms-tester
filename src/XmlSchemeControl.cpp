#include "XmlSchemeControl.h"


//---------------------------------------------------------------------------//


XmlSchemeControl::XmlSchemeControl(const QString& scheme_file)
    : filename(scheme_file)
{}


//---------------------------------------------------------------------------//


bool XmlSchemeControl::save(const QList<DeviceSetting>& settings)
{
    return false;
}


//---------------------------------------------------------------------------//


QList<DeviceSetting> XmlSchemeControl::load()
{
    QList<DeviceSetting>  result;
    return result;
}

//---------------------------------------------------------------------------//

