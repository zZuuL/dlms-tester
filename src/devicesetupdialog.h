#ifndef __devicesetupdialog_H
#define __devicesetupdialog_H

#include "ui_devicesetupdialog.h"

//---------------------------------------------------------------------------//

class DeviceSetupDialog final : public QDialog
{
public:
    explicit DeviceSetupDialog(QWidget* pWgt /*= 0*/);

private:
    Ui::DeviceSetupDialog ui_;
};

//---------------------------------------------------------------------------//



#endif /*__devicesetupdialog_H*/
