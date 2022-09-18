#ifndef __mainwindow_H
#define __mainwindow_H

#include "MainWindowBase.h"
#include "HdlcConnectionPool.h"

//---------------------------------------------------------------------------//

class MainWindow : public MainWindowBase
{
    const int SettingDataRole = Qt::UserRole + 1;
    const int ConnectionRole  = Qt::UserRole + 2;

public:
    explicit MainWindow(QWidget *pWgt = nullptr);

    bool init() override;
    bool fini() override;
    void add() override;
    void modify() override;
    void remove() override;

    bool connect() override;
    bool disconnect() override;

private:
    bool devises_changed;

    HdlcConnectionPool connection_pool;
};


//---------------------------------------------------------------------------//



#endif /*__mainwindow_H*/