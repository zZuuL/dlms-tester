#include "mainwindow.h"
#include "devicesetupdialog.h"

//---------------------------------------------------------------------------//

MainWindow::MainWindow(QWidget *pWgt /*= nullptr*/)
    : MainWindowBase(pWgt)
{
    DeviceSetting s;
    DeviceSetupDialog d(s);
    d.exec();
}


//---------------------------------------------------------------------------//
