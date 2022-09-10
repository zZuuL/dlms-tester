#include "MainWindow.h"
#include "DeviceSetupDialog.h"

#include <QDebug>
#include <QMessageBox>


//---------------------------------------------------------------------------//

MainWindow::MainWindow(QWidget *pWgt /*= nullptr*/)
    : MainWindowBase(pWgt)
{
}


//---------------------------------------------------------------------------//


bool MainWindow::init()
{
    return true;
}


//---------------------------------------------------------------------------//


bool MainWindow::fini()
{
    if (MainWindowBase::isChanged())
    {
        const QMessageBox::StandardButton button = QMessageBox::question(
                this,
                QString("Save"),
                QString("Device schema is changed, save changes?"),
                QMessageBox::Save | QMessageBox::Ignore,
                QMessageBox::Save
        );

        if (button == QMessageBox::Save)
        {

        }
    }

    return true;
}


//---------------------------------------------------------------------------//


bool MainWindow::changeDeviceSetting(DeviceSetting &device_setting)
{
    DeviceSetupDialog setting_dialog(this, device_setting);
    bool result = setting_dialog.exec() == QDialog::Accepted;
    if (result)
        device_setting = setting_dialog.get();
    return result;
}

//---------------------------------------------------------------------------//

