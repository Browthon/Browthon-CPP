#include <QApplication>

#include "Browser.hpp"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    Bn::MainWindow* main = new Bn::MainWindow();
    main->show();

    return a.exec();
}