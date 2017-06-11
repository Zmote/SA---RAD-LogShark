#ifndef RT_UPDATEWORKER_H
#define RT_UPDATEWORKER_H
#include <QObject>
#include <QThread>
#include <QDebug>
#include "RT_Main_Modell.h"

/**
 * \class RT_UpdateWorker
 * \brief Update worker, sends update signals to \ref RT_CaptureWorker in a certain interval
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.1
 * \since 1.3
 */
class RT_UpdateWorker : public QObject
{
	Q_OBJECT
public:
	RT_UpdateWorker(QObject* parent = 0);
public slots:
	/**
	 * \brief Starts updater loop
	 */
	void startUpdater();
	signals:
	/**
	 * \brief Signals an update to \ref RT_CaptureWorker
	 */
	void signalUpdate();
};

#endif //! RT_UPDATEWORKER_H
