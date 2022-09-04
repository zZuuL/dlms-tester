#ifndef __devicesetupdialog_H
#define __devicesetupdialog_H

#include "devicesetting.h"
#include "devicesetupdialogbase.h"

//---------------------------------------------------------------------------//

class DeviceSetupDialog final : public DeviceSetupDialogBase
{
public:
    explicit DeviceSetupDialog(const DeviceSetting &setting, QWidget* pWgt = 0);
    DeviceSetting get() const;

private:
    Ui::DeviceSetupDialog ui_;
};

//---------------------------------------------------------------------------//



#endif /*__devicesetupdialog_H*/
