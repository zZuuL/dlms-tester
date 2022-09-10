#include "MainWindow.h"
#include "DeviceSetupDialog.h"


#include <QDebug>


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
    return true;
}


//---------------------------------------------------------------------------//


void MainWindow::adddevice()
{
    DeviceSetupDialog device_setup_dialog;

    if (device_setup_dialog.exec() == QDialog::Accepted)
    {
        DeviceSetting settings = device_setup_dialog.get();
    }

}


//---------------------------------------------------------------------------//
