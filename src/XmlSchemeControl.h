#ifndef __XmlSchemeControl_H
#define __XmlSchemeControl_H


#include <QList>
#include "DeviceSetting.h"

//---------------------------------------------------------------------------//

class XmlSchemeControl
{
public:
    XmlSchemeControl(const QString& scheme_file);
    bool save(const QList<DeviceSetting>& settings);
    QList<DeviceSetting> load();

private:
    QString filename;
};


//---------------------------------------------------------------------------//


#endif /*__XmlSchemeControl_H*/
