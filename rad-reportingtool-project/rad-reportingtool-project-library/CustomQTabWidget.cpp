#include "CustomQTabWidget.h"
#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <QTableView>

CustomQTabWidget::CustomQTabWidget(QWidget * parent): QTabWidget(parent)
{
}

void CustomQTabWidget::mousePressEvent(QMouseEvent * mouseEvent)
{
	if (mouseEvent->button() == Qt::MiddleButton || mouseEvent->button() == Qt::RightButton) {
		//Because we have multiple tabs, we first have to
		//over which tab our mouse is hovering
		QTabBar *tabBar = this->tabBar();
		int tabPos = tabBar->tabAt(mouseEvent->pos());
		this->setCurrentIndex(tabPos);
		QDrag * drag = new QDrag(this);
		QMimeData * mimeData = new QMimeData();
		mimeData->setText("self");
		drag->setMimeData(mimeData);
		drag->exec();
	}
}

void CustomQTabWidget::dragEnterEvent(QDragEnterEvent * dragEvent)
{
	dragEvent->accept();
}

void CustomQTabWidget::dropEvent(QDropEvent * dropEvent)
{
	dropEvent->accept();
	const QMimeData * mimeData = dropEvent->mimeData();
	auto table = static_cast<QTableView *>(this->currentWidget());
	if (mimeData->text() == "self") {
		this->removeTab(this->currentIndex());
		emit floatWindowInitiated(table->objectName(), dropEvent->pos());
	}
	if (mimeData->text() == "extern") {
		emit tabWindowInitiated(mimeData->objectName());
		emit dragFinishedWithSuccess(mimeData->objectName());
	}
	QTabWidget::dropEvent(dropEvent);
}