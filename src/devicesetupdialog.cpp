#include "devicesetupdialog.h"
#include "devicesetting.h"

//---------------------------------------------------------------------------//


DeviceSetupDialog::DeviceSetupDialog(const DeviceSetting &setting, QWidget* pWgt /*= 0*/)
    : DeviceSetupDialogBase(pWgt)
{}

//---------------------------------------------------------------------------//

DeviceSetting DeviceSetupDialog::get() const
{
    DeviceSetting result;
    return result;
}


//---------------------------------------------------------------------------//

