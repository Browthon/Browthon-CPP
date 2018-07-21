#include "WebPage.hpp"
#include "WebView.hpp"

#include <QAction>
#include <QWebEngineView>

namespace Bn
{
    WebPage::WebPage(QWidget* parent = nullptr):
    QWebEnginePage(parent)
    {
        this->view = dynamic_cast<WebView*>(parent);
        connect(this, &WebPage::fullScreenRequested, this, &WebPage::createFullScreen);
    }

    void WebPage::createFullScreen(QWebEngineFullScreenRequest request)
    {
        if (request.toggleOn())
        {
            fullView = new QWebEngineView();
            auto exitFSAction = new QAction();
            exitFSAction->setShortcut(Qt::Key_Escape);
            connect(exitFSAction, &QAction::triggered, this, &WebPage::exitFullScreen);

            fullView->addAction(exitFSAction);
            this->setView(fullView);
            fullView->showFullScreen();
            fullView->raise();
        }
        else
        {
            delete fullView;
            this->setView(this->view);
        }
        request.accept();
    }

    void WebPage::exitFullScreen()
    {
        this->triggerAction(this->ExitFullScreen);
    }
}