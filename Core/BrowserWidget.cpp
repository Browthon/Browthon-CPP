#include "BrowserWidget.hpp"
#include "Widgets/WebView.hpp"

#include <QGridLayout>

namespace Bn
{
    MainWidget::MainWidget(QWidget* parent = nullptr) :
    QWidget(parent)
    {
        QGridLayout* layout = new QGridLayout();
        WebView* view = new WebView(this);
        layout->addWidget(view, 1, 1);
        this->setLayout(layout);
    }
}