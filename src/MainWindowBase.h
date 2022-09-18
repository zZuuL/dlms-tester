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

public:
    explicit MainWindowBase(QWidget *pWgt = 0);

    virtual bool init() = 0;
    virtual bool fini() = 0;
    virtual void add() = 0;
    virtual void modify() = 0;
    virtual void remove() = 0;
    virtual bool connect() = 0;
    virtual bool disconnect() = 0;

    QTreeWidget* devicesTreeWidget() const;

protected:
    bool isChanged() const;
    void closeEvent(QCloseEvent *event) override;

private slots:
    void actionHandler(const QAction* action);
    void modifySettings(QTreeWidgetItem *item, int column);


protected:
    Ui::MainWindow ui_;
    QActionGroup   actions_;
};


//---------------------------------------------------------------------------//


#endif /*__mainwindowbase_H*/
