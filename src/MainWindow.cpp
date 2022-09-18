#include "MainWindow.h"
#include "DeviceSetupDialog.h"

#include <QDebug>
#include <QMessageBox>


#include <QFileDialog>

#include "HdlcFrame.h"
#include "HdlcConnection.h"
#include "XmlSchemeControl.h"


Q_DECLARE_METATYPE(DeviceSetting)
//Q_DECLARE_METATYPE(HdlcConnection)


//---------------------------------------------------------------------------//

/*
// DM:
// 7E A0 08 21 00 41 1F 4D 09 7E
// UA:
// 7E A0 1F 00 41 21 93 A1 69 81 80 12 05 01 80 06 01 80 07 04 00 00 00 01 08 04 00 00 00 01 19 A9 7E
// AARE:
// 7E A0 38 21 02 41 30 D1 B1 E6 E7 00 61 29 A1 09 06 07 60 85 74 05 08 01 01 A2 03 02 01 00 A3 05 A1 03 02 01 00 BE 10 04 0E 08 00 06 5F 1F 04 00 00 10 10 04 00 00 07 36 E3 7E
*/



/*
0x7e, 0xa0, 0x08, 0x02, 0x65, 0x21, 0x53, 0x1e, 0x72, 0x7e
0x7e, 0xa0, 0x08, 0x21, 0x02, 0x65, 0x1f, 0xa6, 0xf8, 0x7e
*/



MainWindow::MainWindow(QWidget *pWgt /*= nullptr*/)
    : MainWindowBase(pWgt)
    , devises_changed(false)
{
    QByteArray ba;
    //ba.append((char)0x7E);
    //ba.append((char)0xA0);
    //ba.append((char)0x08);
    //ba.append((char)0x21);
    //ba.append((char)0x00);
    //ba.append((char)0x41);
    //ba.append((char)0x1F);
    //ba.append((char)0x4D);
    //ba.append((char)0x09);
    //ba.append((char)0x7E);


    ba.append((char)0x7E); 
    ba.append((char)0xA0); 
    ba.append((char)0x38); 
    ba.append((char)0x21); 
    ba.append((char)0x02); 
    ba.append((char)0x41); 
    ba.append((char)0x30); 
    ba.append((char)0xD1); 
    ba.append((char)0xB1); 
    ba.append((char)0xE6); 
    ba.append((char)0xE7);
    ba.append((char)0x00); 
    ba.append((char)0x61); 
    ba.append((char)0x29); 
    ba.append((char)0xA1); 
    ba.append((char)0x09); 
    ba.append((char)0x06); 
    ba.append((char)0x07); 
    ba.append((char)0x60); 
    ba.append((char)0x85); 
    ba.append((char)0x74); 
    ba.append((char)0x05); 
    ba.append((char)0x08); 
    ba.append((char)0x01); 
    ba.append((char)0x01); 
    ba.append((char)0xA2); 
    ba.append((char)0x03); 
    ba.append((char)0x02); 
    ba.append((char)0x01); 
    ba.append((char)0x00); 
    ba.append((char)0xA3); 
    ba.append((char)0x05); 
    ba.append((char)0xA1); 
    ba.append((char)0x03); 
    ba.append((char)0x02); 
    ba.append((char)0x01); 
    ba.append((char)0x00); 
    ba.append((char)0xBE); 
    ba.append((char)0x10); 
    ba.append((char)0x04); 
    ba.append((char)0x0E); 
    ba.append((char)0x08); 
    ba.append((char)0x00); 
    ba.append((char)0x06); 
    ba.append((char)0x5F); 
    ba.append((char)0x1F); 
    ba.append((char)0x04); 
    ba.append((char)0x00); 
    ba.append((char)0x00); 
    ba.append((char)0x10); 
    ba.append((char)0x10); 
    ba.append((char)0x04); 
    ba.append((char)0x00); 
    ba.append((char)0x00); 
    ba.append((char)0x07); 
    ba.append((char)0x36); 
    ba.append((char)0xE3); 
    ba.append((char)0x7E);


    //ba.append((char)0x7e); 
    //ba.append((char)0xa0); 
    //ba.append((char)0x08); 
    //ba.append((char)0x21); 
    //ba.append((char)0x02); 
    //ba.append((char)0x65); 
    //ba.append((char)0x1f); 
    //ba.append((char)0xa6); 
    //ba.append((char)0xf8); 
    //ba.append((char)0x7e);


    HdlcFrame f(1, ba);

    ba = f.toData();

}


//---------------------------------------------------------------------------//


bool MainWindow::init()
{
    return true;
}


//---------------------------------------------------------------------------//


bool MainWindow::fini()
{
    if (MainWindowBase::devicesTreeWidget()->topLevelItemCount() > 0 && devises_changed)
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

            QList<DeviceSetting> DeviceSetting_s;

            QTreeWidget* tw = MainWindowBase::devicesTreeWidget();
            for (int i = 0; i != tw->topLevelItemCount(); ++i)
            {
                QTreeWidgetItem* item = tw->topLevelItem(i);
                DeviceSetting_s << item->data(0, SettingDataRole).value<DeviceSetting>();
            }

            if (!DeviceSetting_s.empty())
            {
                const QString scheme_file = QFileDialog::getSaveFileName(
                                                this,
                                                QString("Save"),
                                                QString("."),
                                                QString("*.xml"));
                if (!scheme_file.isEmpty())
                {
                    XmlSchemeControl xml(scheme_file);
                    xml.save(DeviceSetting_s);
                }
            }
        }
    }

    return true;
}


//---------------------------------------------------------------------------//


void MainWindow::add()
{
    DeviceSetupDialog setting_dialog(this);

    if (setting_dialog.exec() == QDialog::Accepted)
    {
        QTreeWidget* tw = MainWindowBase::devicesTreeWidget();

        const DeviceSetting settings = setting_dialog.get();

        QTreeWidgetItem* item = new QTreeWidgetItem(tw);
        item->setText(0, QString::fromStdString(settings.name));
        item->setData(0, SettingDataRole, QVariant::fromValue(settings));

        int connection_id = connection_pool.addConnection(settings);
        item->setData(0, ConnectionRole, connection_id);

        tw->setCurrentItem(item);

        devises_changed = true;
    }
}


//---------------------------------------------------------------------------//


void MainWindow::modify()
{  
    QTreeWidgetItem* current_item = MainWindowBase::devicesTreeWidget()->currentItem();
    if (current_item != nullptr)
    {
        DeviceSetting setting = current_item->data(0, SettingDataRole).value<DeviceSetting>();
        DeviceSetupDialog setting_dialog(this, setting);
        if (setting_dialog.exec() == QDialog::Accepted)
        {
            setting = setting_dialog.get();
            current_item->setText(0, QString::fromStdString(setting.name));
            current_item->setData(0, SettingDataRole, QVariant::fromValue(setting));

            int connection_id = current_item->data(0, ConnectionRole).value<int>();
            connection_pool.modifyConnection(connection_id, setting);

            devises_changed = true;
        }
    }
}


//---------------------------------------------------------------------------//


void MainWindow::remove()
{
    QTreeWidgetItem* current_item = MainWindowBase::devicesTreeWidget()->currentItem();
    if (current_item != nullptr)
    {
        DeviceSetting setting = current_item->data(0, SettingDataRole).value<DeviceSetting>();
        const QMessageBox::StandardButton button = QMessageBox::question(
                    this,
                    QString("Remove"),
                    QString("Are you sure what you want remove device: %1").arg(QString::fromStdString(setting.name)),
                    QMessageBox::Yes | QMessageBox::No,
                    QMessageBox::No);

        if (button == QMessageBox::StandardButton::Yes)
        {
            int connection_id = current_item->data(0, ConnectionRole).value<int>();
            connection_pool.removeConnection(connection_id);
            delete current_item;
        }
    }

    devises_changed = true;
}


//---------------------------------------------------------------------------//


bool MainWindow::connect()
{
    QTreeWidgetItem* current_item = MainWindowBase::devicesTreeWidget()->currentItem();
    int connection_id = current_item->data(0, ConnectionRole).value<int>();
    return connection_pool.connect(connection_id);
}


//---------------------------------------------------------------------------//


bool MainWindow::disconnect()
{
    QTreeWidgetItem* current_item = MainWindowBase::devicesTreeWidget()->currentItem();
    int connection_id = current_item->data(0, ConnectionRole).value<int>();
    return connection_pool.disconnect(connection_id);
}


//---------------------------------------------------------------------------//
