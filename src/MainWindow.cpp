#include "MainWindow.h"
#include "DeviceSetupDialog.h"


#include <QDebug>


//---------------------------------------------------------------------------//

MainWindow::MainWindow(QWidget *pWgt /*= nullptr*/)
    : MainWindowBase(pWgt)
{
    DeviceSetting s;
    DeviceSetupDialog d(s);
    d.exec();
}


//---------------------------------------------------------------------------//


//void MainWindow::addDevice()
//{
//
//}



//---------------------------------------------------------------------------//
