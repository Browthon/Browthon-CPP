#include "WebPage.hpp"
#include "WebView.hpp"
#include "../Utils/WebHitTestResult.hpp"

#include <QAction>
#include <QWebEngineView>
#include <QEventLoop>
#include <QTimer>

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

    WebHitTestResult* WebPage::hitTestContent(QPoint pos)
    {
        return new WebHitTestResult(this, pos);
    }

    QPointF WebPage::mapToViewport(QPoint pos)
    {
        return QPointF(pos.x(), pos.y());
    }

    QVariant WebPage::executeJavaScript(const QString& scriptSrc, quint32 worldId, int timeout)
    {
        QPointer<QEventLoop> loop{new QEventLoop};
        QVariant result{};
        QTimer::singleShot(timeout, loop.data(), &QEventLoop::quit);

        this->runJavaScript(scriptSrc, worldId, [loop, &result](const QVariant& res)
        {
            if (loop && loop->isRunning()) {
                result = res;
                loop->quit();
            }
        });

        loop->exec();
        delete loop;

        return result;
    }
}