#include <QApplication>

#include "Core\Browser.hpp"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    auto main = new Bn::MainWindow();
    main->showMaximized();

    return a.exec();
}