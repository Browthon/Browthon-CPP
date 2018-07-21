#ifndef BROWTHON_APP_PAGE_HPP
#define BROWTHON_APP_PAGE_HPP

#include <QWebEnginePage>
#include <QWebEngineFullScreenRequest>
#include <QWebEngineView>

namespace Bn
{
    class WebView;

    class WebPage : public QWebEnginePage
    {
    public:
        WebPage(QWidget* parent);
        WebView* view;
        QWebEngineView* fullView;
        void createFullScreen(QWebEngineFullScreenRequest request);
        void exitFullScreen();
    };
}

#endif //BROWTHON_APP_PAGE_HPP
