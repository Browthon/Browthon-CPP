#ifndef BROWTHON_APP_MAINWIDGET_H
#define BROWTHON_APP_MAINWIDGET_H

#include <QWidget>
#include <QPushButton>

namespace Bn
{
    class UrlInput;
    class WebView;
    class TabWidget;
    class MainWindow;

    class MainWidget : public QWidget
    {
    public:
        MainWindow* parent;
        MainWidget(MainWindow* parent);
        WebView* view;
        UrlInput* urlInput;
        TabWidget* tabWidget;
        QPushButton* backButton;
        QPushButton* reloadButton;
        QPushButton* forwardButton;
        void setView(WebView* view);
        void showHome();
        void createTabWithUrl(QString url);
        void openHistory();
        void openFav();
        void openDownload();
        void openSession();
        void openRaccourci();
        void openParameters();
        void openInfoBrowthon();
        void openInfoQt();
    };
}

#endif //BROWTHON_APP_MAINWIDGET_H
