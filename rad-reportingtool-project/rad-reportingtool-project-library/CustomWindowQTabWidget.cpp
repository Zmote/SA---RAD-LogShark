#include "CustomWindowQTabWidget.h"
#include <QDebug>
#include <QDrag>
#include <QMimeData>

CustomWindowQTabWidget::CustomWindowQTabWidget():QTabWidget() {}

void CustomWindowQTabWidget::mousePressEvent(QMouseEvent * mouseEvent)
{
	if (mouseEvent->button() == Qt::MiddleButton || mouseEvent->button() == Qt::RightButton) {
		QDrag * drag = new QDrag(this);
		QMimeData * mimeData = new QMimeData();
		mimeData->setText("extern");
		mimeData->setObjectName(this->currentWidget()->objectName());
		drag->setMimeData(mimeData);
		emit hideWindow(this->currentWidget()->objectName());
		Qt::DropAction dropAction = drag->exec();
		if (dropAction == Qt::DropAction::IgnoreAction) {
			emit showWindow(this->currentWidget()->objectName());
		}
	}
}

void CustomWindowQTabWidget::dragEnterEvent(QDragEnterEvent * dragEvent)
{
	dragEvent->accept();
}

void CustomWindowQTabWidget::dropEvent(QDropEvent * dropEvent)
{
	dropEvent->accept();
}

void CustomWindowQTabWidget::closeEvent(QCloseEvent * closeEvent)
{
}
