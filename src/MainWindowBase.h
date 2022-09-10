#ifndef __mainwindowbase_H
#define __mainwindowbase_H

#include "ui_MainWindow.h"

#include <QActionGroup>

#include "DeviceSetting.h"

//---------------------------------------------------------------------------//

class QCloseEvent;

class MainWindowBase : public QMainWindow
{
    Q_OBJECT

    const int SettingDataRole = Qt::UserRole + 1;

public:
    explicit MainWindowBase(QWidget *pWgt = 0);

    virtual bool init() = 0;
    virtual bool fini() = 0;
    virtual bool changeDeviceSetting(DeviceSetting &device_setting) = 0;

protected:
    bool isChanged() const;

    void closeEvent(QCloseEvent *event) override;

private:
    void setDeviceSettingItem_i(const DeviceSetting &setting, QTreeWidgetItem* item);

private slots:
    void actionHandler(const QAction* action);
    void modifySettings(QTreeWidgetItem *item, int column);


protected:
    Ui::MainWindow ui_{};
    QActionGroup   actions_;

    bool           changed;
};


//---------------------------------------------------------------------------//


#endif /*__mainwindowbase_H*/
