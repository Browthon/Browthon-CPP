#ifndef BROWTHON_APP_MAINWIDGET_H
#define BROWTHON_APP_MAINWIDGET_H

#include <QWidget>

namespace Bn
{
    class UrlInput;
    class WebView;
    class MainWidget : public QWidget
    {
    public:
        MainWidget(QWidget* parent);
        WebView* view;
        UrlInput* urlInput;
        void setView(WebView* view);
    };
}

#endif //BROWTHON_APP_MAINWIDGET_H
