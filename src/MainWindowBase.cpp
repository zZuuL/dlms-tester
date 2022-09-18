#include "MainWindowBase.h"

#include <QCloseEvent>


//---------------------------------------------------------------------------//


MainWindowBase::MainWindowBase(QWidget *pWgt/* = 0*/)
    : QMainWindow(pWgt)
    , actions_(this)
{
    ui_.setupUi(this);

    const int w = QMainWindow::width();

    ui_.splitter->setSizes(QList<int>() << w*0.3 << w*0.7);

    actions_.addAction(ui_.action_Close);
    actions_.addAction(ui_.action_AboutQt);
    actions_.addAction(ui_.action_AddDevice);
    actions_.addAction(ui_.action_RemoveDevice);
    actions_.addAction(ui_.action_DeviceConnect);
    actions_.addAction(ui_.action_DeviceDisconnect);

    QObject::connect(&actions_, &QActionGroup::triggered, this, &MainWindowBase::actionHandler);
    QObject::connect(ui_.twDevices, &QTreeWidget::itemDoubleClicked, this, &MainWindowBase::modifySettings);
}


//---------------------------------------------------------------------------//


QTreeWidget* MainWindowBase::devicesTreeWidget() const
{
    return ui_.twDevices;
}


//---------------------------------------------------------------------------//

void MainWindowBase::actionHandler(const QAction* action)
{
    if (action == ui_.action_AboutQt)
    {
        QApplication::aboutQt();
    }

    else if (action == ui_.action_Close)
    {
        QMainWindow::close();
    }

    else if (action == ui_.action_AddDevice)
    {
        add();
    }

    else if (action == ui_.action_RemoveDevice)
    {
        remove();
    }

    else if (action == ui_.action_DeviceConnect)
    {
        connect();
    }

    else if (action == ui_.action_DeviceDisconnect)
    {
        disconnect();
    }
}

//---------------------------------------------------------------------------//


void MainWindowBase::modifySettings(QTreeWidgetItem *item, int column)
{
    modify();
}


//---------------------------------------------------------------------------//

void MainWindowBase::closeEvent(QCloseEvent *event)
{
    fini();
    event->accept();
}

//---------------------------------------------------------------------------//
