#include "Application.hpp"
#include "Browser.hpp"

namespace Bn
{
    Application::Application(int argc, char** argv):
    QApplication(argc, argv)
    {
        Application::isClose = false;
        MainWindow();
    }

    bool Application::isClosing()
    {
        return Application::isClose;
    }

    void Application::quitApp()
    {
        Application::isClose = true;

        Application::quit();
    }
}