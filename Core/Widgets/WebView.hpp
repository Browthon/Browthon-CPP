#ifndef BROWTHON_APP_WEBVIEW_HPP
#define BROWTHON_APP_WEBVIEW_HPP

#include <QWebEngineView>
#include "../BrowserWidget.hpp"

namespace Bn
{
    class WebView : public QWebEngineView
    {
    public:
        WebView(MainWidget* parent);
        MainWidget* parent;
        QWebEnginePage* page;
        void createConnection();
    };
}

#endif //BROWTHON_APP_WEBVIEW_HPP
