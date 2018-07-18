#ifndef BROWTHON_APP_WEBVIEW_HPP
#define BROWTHON_APP_WEBVIEW_HPP

#include <QWebEngineView>

namespace Bn
{
    class WebView : public QWebEngineView
    {
    public:
        WebView(QWidget* parent);
        QWebEnginePage* page;
    };
}

#endif //BROWTHON_APP_WEBVIEW_HPP
