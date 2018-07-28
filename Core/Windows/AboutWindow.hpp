#ifndef BROWTHON_APP_ABOUTWINDOW_HPP
#define BROWTHON_APP_ABOUTWINDOW_HPP

#include <QWidget>
#include "Core/BrowserWidget.hpp"

namespace Bn
{
    class AboutWindow : public QWidget
    {
    public:
        MainWidget* parent;
        AboutWindow(MainWidget* parent, QString type);
        void openWebsiteBrowthon();
        void openWebsiteQt();
    };
}

#endif //BROWTHON_APP_ABOUTWINDOW_HPP
