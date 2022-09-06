#include "devicesetupdialogbase.h"

//---------------------------------------------------------------------------//

DeviceSetupDialogBase::DeviceSetupDialogBase(QWidget* pWgt/* = 0*/)
    : QDialog(pWgt)
{
    ui_.setupUi(this);
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setName (const std::string &name)
{
    ui_.leName->setText(QString::fromStdString(name));
}

//---------------------------------------------------------------------------//

std::string DeviceSetupDialogBase::getName() const
{
    return ui_.leName->text().toStdString();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setLogicalDeviceId(uint16_t logic_device)
{
    ui_.sbLogicalDeviceId->setValue(logic_device);
}

//---------------------------------------------------------------------------//

uint16_t DeviceSetupDialogBase::getLogicalDeviceId() const
{
    return ui_.sbLogicalDeviceId->value();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setServerAddress(uint16_t server_address)
{
    ui_.sbServerAddress->setValue(server_address);
}

//---------------------------------------------------------------------------//

uint16_t DeviceSetupDialogBase::getServerAddress() const
{
    return ui_.sbServerAddress->value();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setLowPassword(const std::string & low_password)
{
    ui_.leLowPassword->setText(QString::fromStdString(low_password));
}

//---------------------------------------------------------------------------//

std::string DeviceSetupDialogBase::getLowPassword() const
{
    return ui_.leLowPassword->text().toStdString();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setHigthPassword(const std::string &higth_password)
{
    ui_.leHigthPassword->setText(QString::fromStdString(higth_password));
}

//---------------------------------------------------------------------------//

std::string DeviceSetupDialogBase::getHigthPassword() const
{
    return ui_.leHigthPassword->text().toStdString();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setSecurity(dlms::SecurityTypeEnum security)
{
    switch (security)
    {
    case dlms::SecurityTypeEnum::None:
        {
            ui_.rbSecurityNone->setChecked(true);
            break;
        }
    case dlms::SecurityTypeEnum::Low:
        {
            ui_.rbSecurityLow->setChecked(true);
            break;;
        }
    case dlms::SecurityTypeEnum::Hight:
    case dlms::SecurityTypeEnum::Hight_GMAC:
        {
            ui_.rbSecurityHight->setChecked(true);
            break;
        }
    }
}

//---------------------------------------------------------------------------//

dlms::SecurityTypeEnum DeviceSetupDialogBase::getSecurity() const
{
    if (ui_.rbSecurityNone->isChecked())
    {
        return dlms::SecurityTypeEnum::None;
    }
    else if (ui_.rbSecurityLow->isChecked())
    {
        return dlms::SecurityTypeEnum::Low;
    }
    else if (ui_.rbSecurityHight->isChecked())
    {
        return dlms::SecurityTypeEnum::Hight;
    }

    return dlms::SecurityTypeEnum::Hight;
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setClientId (uint8_t client_id)
{
    ui_.sbClientOther->setValue(client_id);

    switch (client_id)
    {
        case (uint8_t)hdlc::ClientIdEnum::PublicClient:
        {
            ui_.rbClientPublic->setChecked(true);
            break;
        }
        case (uint8_t)hdlc::ClientIdEnum::Reader:
        {
            ui_.rbClientReader->setChecked(true);
            break;
        }
        case (uint8_t)hdlc::ClientIdEnum::Configurator:
        {
            ui_.rbClientConfigurator->setChecked(true);
            break;
        }
        default:
        {
            ui_.rbClientOther->setChecked(true);
        }
    }
}

//---------------------------------------------------------------------------//

uint8_t DeviceSetupDialogBase::getClientId () const
{
    if (ui_.rbClientPublic->isChecked())
    {
        return (uint8_t) hdlc::ClientIdEnum::PublicClient;
    }
    else if (ui_.rbClientReader->isChecked())
    {
        return (uint8_t) hdlc::ClientIdEnum::Reader;
    }
    else if (ui_.rbClientConfigurator->isChecked())
    {
        return (uint8_t) hdlc::ClientIdEnum::Configurator;
    }

    return (uint8_t) ui_.sbClientOther->value();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setAddressSize(uint8_t address_size)
{
    switch (address_size)
    {
    case 1:
        {
            ui_.rbAddressSize1->setChecked(true);
            break;
        }
    case 2:
        {
            ui_.rbAddressSize2->setChecked(true);
            break;
        }
    case 4:
        {
            ui_.rbAddressSize4->setChecked(true);
            break;
        }
    }
}

//---------------------------------------------------------------------------//

uint8_t DeviceSetupDialogBase::getAddressSize() const
{
    if (ui_.rbAddressSize1->isChecked())
    {
        return 1;
    }
    else if (ui_.rbAddressSize2->isChecked())
    {
        return 2;
    }
    else if (ui_.rbAddressSize4->isChecked())
    {
        return 4;
    }

    return 0;
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setReciveFrameSize(uint16_t recive_frame_size)
{
    ui_.sbReciveFrameSize->setValue(recive_frame_size);
}

//---------------------------------------------------------------------------//

uint16_t DeviceSetupDialogBase::getReciveFrameSize() const
{
    return ui_.sbReciveFrameSize->value();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setSendFrameSize(uint16_t send_frame_size)
{
    ui_.sbSendFrameSize->setValue(send_frame_size);
}

//---------------------------------------------------------------------------//

uint16_t DeviceSetupDialogBase::getSendFrameSize() const
{
    return ui_.sbSendFrameSize->value();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setReciveWindowSize(uint8_t recive_window_size)
{
    ui_.sbReciveWindowSize->setValue(recive_window_size);
}

//---------------------------------------------------------------------------//

uint8_t DeviceSetupDialogBase::getReciveWindowSize() const
{
    return ui_.sbReciveWindowSize->value();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setSendWindowSize(uint8_t send_window_size)
{
    ui_.sbSendWindowSize->setValue(send_window_size);
}

//---------------------------------------------------------------------------//

uint8_t DeviceSetupDialogBase::getSendWindowSize() const
{
    return ui_.sbSendWindowSize->value();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setSendKeepAlivePackages(bool send_keep_alive_packages)
{
    ui_.cbSendKeepAlive->setChecked(send_keep_alive_packages);
}

//---------------------------------------------------------------------------//

bool DeviceSetupDialogBase::getSendKeepAlivePackages() const
{
    return ui_.cbSendKeepAlive->isChecked();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setInactivityTimeout(uint16_t timeout)
{
    ui_.sbInactivityTimeout->setValue(timeout);
}

//---------------------------------------------------------------------------//

uint16_t DeviceSetupDialogBase::getInactivityTimeout() const
{
    return ui_.sbInactivityTimeout->value();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setIpAddress(const std::string &ip)
{
    ui_.leIpAddress->setText(QString::fromStdString(ip));
}

//---------------------------------------------------------------------------//

std::string DeviceSetupDialogBase::getIpAddress() const
{
    return ui_.leIpAddress->text().toStdString();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::setIpPort(uint16_t port)
{
    ui_.sbIpPort->setValue(port);
}

//---------------------------------------------------------------------------//

uint16_t DeviceSetupDialogBase::getIpPort() const
{
    return ui_.sbIpPort->value();
}

//---------------------------------------------------------------------------//

void DeviceSetupDialogBase::clientIdChanged()
{
    QObject* obj = sender();

    if (obj == ui_.rbClientPublic)
        ui_.sbClientOther->setValue((int)hdlc::ClientIdEnum::PublicClient);
    else if (obj == ui_.rbClientReader)
        ui_.sbClientOther->setValue((int)hdlc::ClientIdEnum::Reader);
    else if (obj == ui_.rbClientConfigurator)
        ui_.sbClientOther->setValue((int)hdlc::ClientIdEnum::Configurator);

    ui_.sbClientOther->setEnabled(sender() == ui_.rbClientOther);
}

//---------------------------------------------------------------------------//


