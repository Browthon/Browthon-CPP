#include "BrowserWidget.hpp"

#include "Widgets/WebView.hpp"
#include "Widgets/UrlInput.hpp"
#include "Widgets/TabWidget.hpp"

#include <QGridLayout>
#include <QPushButton>

namespace Bn
{
    MainWidget::MainWidget(QWidget* parent = nullptr) :
    QWidget(parent)
    {
        QGridLayout* layout = new QGridLayout();

        view = new WebView(this);
        urlInput = new UrlInput(this);
        tabWidget = new TabWidget(this);
        QPushButton* addTabButton = new QPushButton("+", this);

        connect(urlInput, SIGNAL(returnPressed()), urlInput, SLOT(enterUrl()));
        connect(tabWidget, &TabWidget::currentChanged, tabWidget, &TabWidget::changeTab);
        connect(addTabButton, &QPushButton::clicked, tabWidget, &TabWidget::addView);

        layout->addWidget(urlInput, 1, 2);
        layout->addWidget(addTabButton, 1, 1);
        layout->addWidget(tabWidget, 2, 1, 1, 2);

        this->setLayout(layout);
    }

    void MainWidget::setView(WebView *view)
    {
        this->view = view;
    }
}