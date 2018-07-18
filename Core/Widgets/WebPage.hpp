#ifndef BROWTHON_APP_PAGE_HPP
#define BROWTHON_APP_PAGE_HPP

#include <QWebEnginePage>

namespace Bn
{
    class WebPage : public QWebEnginePage
    {
    public:
        WebPage(QWidget* parent);
    };
}

#endif //BROWTHON_APP_PAGE_HPP
