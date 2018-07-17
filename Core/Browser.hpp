#ifndef BROWTHON_APP_BROWSER_H
#define BROWTHON_APP_BROWSER_H

#include <QMainWindow>
#include <QLayout>
#include <QCloseEvent>

#include "BrowserWidget.hpp"

namespace Bn
{
    class MainWindow : public QMainWindow
    {
    public:
        MainWindow();
        QWidget* mainWidget {nullptr};
    };
}

#endif //BROWTHON_APP_BROWSER_H
