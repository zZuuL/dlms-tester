#include "MainWindowBase.h"

#include <QCloseEvent>


//---------------------------------------------------------------------------//


Q_DECLARE_METATYPE(DeviceSetting)


MainWindowBase::MainWindowBase(QWidget *pWgt/* = 0*/)
    : QMainWindow(pWgt)
    , actions_(this)
    , changed(false)
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

bool MainWindowBase::isChanged() const
{
    return changed;
}

//---------------------------------------------------------------------------//

void MainWindowBase::actionHandler(const QAction* action)
{
    if (action == ui_.action_AboutQt) {
        QApplication::aboutQt();
    }

    else if (action == ui_.action_Close) {
        QMainWindow::close();
    }

    else if (action == ui_.action_AddDevice) {
        DeviceSetting setting;
        if (changeDeviceSetting(setting))
        {
            QTreeWidgetItem* item = new QTreeWidgetItem(ui_.twDevices);
            setDeviceSettingItem_i(setting, item);

        }
    }

    else if (action == ui_.action_RemoveDevice) {

    }

    else if (action == ui_.action_DeviceConnect) {
        connect();
    }

    else if (action == ui_.action_DeviceDisconnect) {
        disconnect();
    }
}

//---------------------------------------------------------------------------//


void MainWindowBase::setDeviceSettingItem_i(const DeviceSetting &setting, QTreeWidgetItem* item)
{
    changed = true;

    item->setText(0, QString::fromStdString(setting.name));
    item->setData(0, SettingDataRole, QVariant::fromValue(setting));

    ui_.twDevices->setCurrentItem(item);
}

//---------------------------------------------------------------------------//

void MainWindowBase::modifySettings(QTreeWidgetItem *item, int column)
{
    if (item != nullptr) {
        DeviceSetting setting = item->data(0, SettingDataRole).value<DeviceSetting>();
        if (changeDeviceSetting(setting))
            setDeviceSettingItem_i(setting, item);
    }
}


//---------------------------------------------------------------------------//

void MainWindowBase::closeEvent(QCloseEvent *event)
{
    fini();
    event->accept();
}

//---------------------------------------------------------------------------//

QList<DeviceSetting> MainWindowBase::getDeviceScheme() const
{
    QList<DeviceSetting> result;
    for (int i = 0; i != ui_.twDevices->topLevelItemCount(); ++i) {
        QTreeWidgetItem* item = ui_.twDevices->topLevelItem(i);
        result << item->data(0, SettingDataRole).value<DeviceSetting>();
    }
    return result;
}

//---------------------------------------------------------------------------//

bool MainWindowBase::getActiveDevice(DeviceSetting &setting) const
{
    if (QTreeWidgetItem* item = ui_.twDevices->currentItem()) {
        setting = item->data(0, SettingDataRole).value<DeviceSetting>();
    }
    return false;
}

//---------------------------------------------------------------------------//
