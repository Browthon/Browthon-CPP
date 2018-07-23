#ifndef BROWTHON_APP_PAGE_HPP
#define BROWTHON_APP_PAGE_HPP

#include <QWebEnginePage>
#include <QWebEngineFullScreenRequest>
#include <QWebEngineView>
#include <QWebEngineScript>

namespace Bn
{
    class WebHitTestResult;
    class WebView;

    class WebPage : public QWebEnginePage
    {
    public:
        WebPage(WebView* parent);
        WebView* view;
        QWebEngineView* fullView;
        void createFullScreen(QWebEngineFullScreenRequest request);
        void exitFullScreen();
        WebHitTestResult* hitTestContent(QPoint pos);
        QPointF mapToViewport(QPoint pos);
        QVariant executeJavaScript(const QString& scriptSrc, quint32 worldId = QWebEngineScript::MainWorld, int timeout = 500);
    };
}

#endif //BROWTHON_APP_PAGE_HPP
