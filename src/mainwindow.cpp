#include "mainwindow.h"
#include "devicesetupdialog.h"

//---------------------------------------------------------------------------//

MainWindow::MainWindow(QWidget *pWgt /*= nullptr*/)
    : QMainWindow(pWgt)
{
    DeviceSetting setting;

    ui.setupUi(this);
    DeviceSetupDialog d(setting, this);
    d.exec();
}


//---------------------------------------------------------------------------//
