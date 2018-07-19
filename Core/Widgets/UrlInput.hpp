#ifndef BROWTHON_APP_URLINPUT_HPP
#define BROWTHON_APP_URLINPUT_HPP

#include <QLineEdit>
#include "BrowserWidget.hpp"

namespace Bn
{
    class UrlInput : public QLineEdit
    {
        Q_OBJECT
    public slots:
        void enterUrl();
    public:
        MainWidget* parent {nullptr};
        UrlInput(MainWidget* parent);
        void enterUrl(char* url);
        void setUrl();
    };
}

#endif //BROWTHON_APP_URLINPUT_HPP
