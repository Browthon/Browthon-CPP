#include "Browser.hpp"
#include "BrowserWidget.hpp"

#include <QCloseEvent>

namespace Bn
{
    MainWindow::MainWindow()
    {
        MainWindow::mainWidget = new MainWidget(this);
        MainWindow::setCentralWidget(MainWindow::mainWidget);
    }

    MainWindow::~MainWindow()
    {
        delete MainWindow::mainWidget;
    }

}

