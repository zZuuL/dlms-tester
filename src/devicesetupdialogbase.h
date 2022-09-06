#ifndef __devicesetupdialogbase_H
#define __devicesetupdialogbase_H

#include "devicesetting.h"
#include "ui_devicesetupdialog.h"


//---------------------------------------------------------------------------//

class DeviceSetupDialogBase : public QDialog
{
    Q_OBJECT

public:
    explicit DeviceSetupDialogBase(QWidget* pWgt = 0);

    void setName (const std::string &name);
    std::string getName() const;

    void setLogicalDeviceId(uint16_t logic_device);
    uint16_t getLogicalDeviceId() const;

    void setServerAddress(uint16_t server_address);
    uint16_t getServerAddress() const;

    void setLowPassword(const std::string & low_password);
    std::string getLowPassword() const;

    void setHigthPassword(const std::string &higth_password);
    std::string getHigthPassword() const;

    void setSecurity(dlms::SecurityTypeEnum security);
    dlms::SecurityTypeEnum getSecurity() const;

    void setClientId (uint8_t client_id);
    uint8_t getClientId () const;

    void setAddressSize(uint8_t address_size);
    uint8_t getAddressSize() const;

    void setReciveFrameSize(uint16_t recive_frame_size);
    uint16_t getReciveFrameSize() const;

    void setSendFrameSize(uint16_t send_frame_size);
    uint16_t getSendFrameSize() const;

    void setReciveWindowSize(uint8_t recive_window_size);
    uint8_t getReciveWindowSize() const;

    void setSendWindowSize(uint8_t send_window_size);
    uint8_t getSendWindowSize() const;

    void setSendKeepAlivePackages(bool send_keep_alive_packages);
    bool getSendKeepAlivePackages() const;

    void setInactivityTimeout(uint16_t timeout);
    uint16_t getInactivityTimeout() const;

    void setIpAddress(const std::string &ip);
    std::string getIpAddress() const;

    void setIpPort(uint16_t port);
    uint16_t getIpPort() const;

private slots:
    void clientIdChanged();

private:
    Ui::DeviceSetupDialog ui_;
};

//---------------------------------------------------------------------------//


#endif /*__devicesetupdialogbase_*/
