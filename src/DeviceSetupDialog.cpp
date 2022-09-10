#include "DeviceSetupDialog.h"

//---------------------------------------------------------------------------//


DeviceSetupDialog::DeviceSetupDialog(const DeviceSetting &setting /*= DeviceSetting()*/, QWidget* pWgt /*= 0*/)
    : DeviceSetupDialogBase(pWgt)
{
    DeviceSetupDialogBase::setName(setting.name);
    DeviceSetupDialogBase::setLogicalDeviceId(setting.logic_device);
    DeviceSetupDialogBase::setServerAddress(setting.server_address);
    DeviceSetupDialogBase::setLowPassword(setting.low_password);
    DeviceSetupDialogBase::setHigthPassword(setting.higth_password);
    DeviceSetupDialogBase::setSecurity(setting.security);
    DeviceSetupDialogBase::setClientId(setting.client_id);
    DeviceSetupDialogBase::setAddressSize(setting.address_size);
    DeviceSetupDialogBase::setReciveFrameSize(setting.recive_frame_size);
    DeviceSetupDialogBase::setSendFrameSize(setting.send_frame_size);
    DeviceSetupDialogBase::setReciveWindowSize(setting.recive_window_size);
    DeviceSetupDialogBase::setSendWindowSize(setting.send_window_size);
    DeviceSetupDialogBase::setSendKeepAlivePackages(setting.send_keep_alive);
    DeviceSetupDialogBase::setInactivityTimeout(setting.inactivity_timeout);
    DeviceSetupDialogBase::setIpAddress(setting.ip);
    DeviceSetupDialogBase::setIpPort(setting.port);
}


//---------------------------------------------------------------------------//


DeviceSetting DeviceSetupDialog::get() const
{
    DeviceSetting result;
    result.name               = DeviceSetupDialogBase::getName();
    result.logic_device       = DeviceSetupDialogBase::getLogicalDeviceId();
    result.server_address     = DeviceSetupDialogBase::getServerAddress();
    result.low_password       = DeviceSetupDialogBase::getLowPassword();
    result.higth_password     = DeviceSetupDialogBase::getHigthPassword();
    result.security           = DeviceSetupDialogBase::getSecurity();
    result.client_id          = DeviceSetupDialogBase::getClientId();
    result.address_size       = DeviceSetupDialogBase::getAddressSize();
    result.recive_frame_size  = DeviceSetupDialogBase::getReciveFrameSize();
    result.send_frame_size    = DeviceSetupDialogBase::getSendFrameSize();
    result.recive_window_size = DeviceSetupDialogBase::getReciveWindowSize();
    result.send_window_size   = DeviceSetupDialogBase::getSendWindowSize();
    result.send_keep_alive    = DeviceSetupDialogBase::getSendKeepAlivePackages();
    result.inactivity_timeout = DeviceSetupDialogBase::getInactivityTimeout();
    result.ip                 = DeviceSetupDialogBase::getIpAddress();
    result.port               = DeviceSetupDialogBase::getIpPort();
    return result;
}


//---------------------------------------------------------------------------//

