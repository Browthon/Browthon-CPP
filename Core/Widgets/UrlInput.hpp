#ifndef BROWTHON_APP_URLINPUT_HPP
#define BROWTHON_APP_URLINPUT_HPP

#include <QLineEdit>
#include "Core\BrowserWidget.hpp"

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
        void enterUrl(QString url);
        void setUrl();
        void enterUrlGiven(QString url);
    };
}

#endif //BROWTHON_APP_URLINPUT_HPP
