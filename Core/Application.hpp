#ifndef BROWTHON_APP_APPLICATION_H
#define BROWTHON_APP_APPLICATION_H

#include <QApplication>

namespace Bn
{
    class Application : public QApplication
    {
    public:
        bool isClose;
        Application(int argc, char** argv);
        bool isClosing();
        void quitApp();
    };
}

#endif //BROWTHON_APP_APPLICATION_H
