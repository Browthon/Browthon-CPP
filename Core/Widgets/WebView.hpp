#ifndef BROWTHON_APP_WEBVIEW_HPP
#define BROWTHON_APP_WEBVIEW_HPP

#include <QWebEngineView>
#include "../BrowserWidget.hpp"
#include "WebPage.hpp"

namespace Bn
{
    class WebView : public QWebEngineView
    {
    public:
        WebView(MainWidget* parent);
        MainWidget* parent;
        WebPage* page;
        void createConnection();
        bool event(QEvent* event);
        bool eventFilter(QObject* watched, QEvent* event);
    };
}

#endif //BROWTHON_APP_WEBVIEW_HPP
