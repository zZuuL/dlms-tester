#ifndef __devicesetupdialog_H
#define __devicesetupdialog_H

#include "DeviceSetting.h"
#include "DeviceSetupDialogBase.h"

//---------------------------------------------------------------------------//

class DeviceSetupDialog final : public DeviceSetupDialogBase
{
public:
    explicit DeviceSetupDialog(const DeviceSetting &setting = DeviceSetting(), QWidget* pWgt = 0);
    DeviceSetting get() const;

private:
    Ui::DeviceSetupDialog ui_;
};

//---------------------------------------------------------------------------//



#endif /*__devicesetupdialog_H*/