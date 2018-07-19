#ifndef BROWTHON_APP_TABWIDGET_HPP
#define BROWTHON_APP_TABWIDGET_HPP

#include <QtWidgets/QTabWidget>
#include "../BrowserWidget.hpp"

namespace Bn
{
    class TabWidget : public QTabWidget
    {
    public:
        MainWidget* parent;
        TabWidget(MainWidget* parent);
        void changeTab();
        void addView();
        void setTitle();
    };
}

#endif //BROWTHON_APP_TABWIDGET_HPP
