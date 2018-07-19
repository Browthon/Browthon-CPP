#include "TabWidget.hpp"
#include "WebView.hpp"
#include "UrlInput.hpp"

namespace Bn
{
    TabWidget::TabWidget(Bn::MainWidget *parent):
    QTabWidget(parent)
    {
        TabWidget::parent = parent;
        this->setTabPosition(QTabWidget::North);
        this->setMovable(true);
        this->addTab(this->parent->view, "Youtube");
        this->parent->view->show();
    }

    void TabWidget::changeTab()
    {
        this->parent->setView(static_cast<WebView*>(this->currentWidget()));
        this->parent->urlInput->setUrl();
    }

    void TabWidget::addView()
    {
        auto tab = new WebView(this->parent);
        this->addTab(tab, "Youtube");
        tab->show();
        this->setCurrentWidget(tab);
    }

    void TabWidget::setTitle()
    {
        QString title;
        if (this->parent->view->title().size() >= 13)
        {
            title = this->parent->view->title().mid(0,9)+"...";
        }
        else
        {
            title = this->parent->view->title();
        }
        this->setTabText(this->currentIndex(), title);
    }
}
