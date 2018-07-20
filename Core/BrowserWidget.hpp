#ifndef BROWTHON_APP_MAINWIDGET_H
#define BROWTHON_APP_MAINWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Bn
{
    class UrlInput;
    class WebView;
    class TabWidget;

    class MainWidget : public QWidget
    {
    public:
        QWidget* parent;
        MainWidget(QWidget* parent);
        WebView* view;
        UrlInput* urlInput;
        TabWidget* tabWidget;
        QPushButton* backButton;
        QPushButton* reloadButton;
        QPushButton* forwardButton;
        void setView(WebView* view);
        void showHome();
    };
}

#endif //BROWTHON_APP_MAINWIDGET_H
