#include "mainwindowbase.h"

//---------------------------------------------------------------------------//

MainWindowBase::MainWindowBase(QWidget *pWgt/* = 0*/)
{
    ui_.setupUi(this);
}

//---------------------------------------------------------------------------//

void MainWindowBase::actionHandler()
{
    const QObject* senser_object = sender();

    if (senser_object == ui_.action_AboutQt)
    {
        QApplication::aboutQt();
    }


}