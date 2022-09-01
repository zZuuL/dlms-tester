#include "mainwindow.h"
#include "devicesetupdialog.h"

//---------------------------------------------------------------------------//

MainWindow::MainWindow(QWidget *pWgt /*= nullptr*/)
    : QMainWindow(pWgt)
{
    DeviceSetupDialog d(this); d.exec();
    ui.setupUi(this);
}

//---------------------------------------------------------------------------//
