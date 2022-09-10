#ifndef __mainwindowbase_H
#define __mainwindowbase_H

#include "ui_MainWindow.h"


#include <QActionGroup>


//---------------------------------------------------------------------------//

class MainWindowBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowBase(QWidget *pWgt = 0);

    virtual bool init() = 0;
    virtual bool fini() = 0;
    virtual void adddevice() =0;

private slots:
    void actionHandler(const QAction* action);

protected:
    Ui::MainWindow ui_;
    QActionGroup   actions_;
};


//---------------------------------------------------------------------------//


#endif /*__mainwindowbase_H*/
