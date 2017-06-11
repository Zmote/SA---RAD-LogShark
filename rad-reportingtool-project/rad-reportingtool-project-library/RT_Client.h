#ifndef RT_CLIENT_H
#define RT_CLIENT_H

#include <QPointer>
#include "CommonStringUtils.h"
#include "RT_Constants.h"
#include <QColor>

class QTableView;

/*!
* \class RT_Client
* \brief A representative class for Clients
*
* \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
* \version 1.4
* \since 1.0
*/
class RT_Client{
public:
	RT_Client(const int pClientId = -1, const QString pClientName = RT_Constants::GLOBAL, const QString pGroupName = RT_Constants::GLOBAL, QTableView * pTable = nullptr);
	RT_Client(const RT_Client & copy);
	RT_Client & operator=(const RT_Client & copy);
	bool operator==(const RT_Client & copy) const;
	bool isParent() const;
	void clearModel() const;
	/** ACCESSORS **/
	QTableView * getTable();
	QColor color() const;
	bool binary() const;
	bool active() const;
	bool live() const;
	bool toFile() const;
	bool toRingFile() const;
	bool toSharedFile() const;
	bool toParent() const;
	bool newestOnTop() const;
	bool scrollToBottom() const;
	bool windowed() const;
	bool toGlobal() const;
	bool toMergeView() const;
	int getClientId() const;
	QString getClientName() const;
	QString getGroupName() const;
	QString getSharedFileName() const;
	QString getMergeViewName() const;

	/** SETTERS **/
	void color(const QColor & color);
	void binary(bool val);
	void active(bool val);
	void live(bool val);
	void toFile(bool val);
	void toRingFile(bool val);
	void toSharedFile(bool val);
	void toParent(bool val);
	void toGlobal(bool val);
	void toMergeView(bool val);
	void newestOnTop(bool val);
	void scrollToBottom(bool val);
	void windowed(bool val);
	void addLog(const QList<QList<QString>> & rows);
	void setSharedFileName(QString fileName);
	void setMergeViewName(QString mergeViewName);
private:
	void scroll(int rowCount);
	QPointer<QTableView> table;
	bool isBinary;
	bool isActive;
	bool isLive;
	bool isToFile;
	bool isToRingFile;
	bool isToSharedFile;
	bool isToParent;
	bool isToGlobal;
	bool isToMergeView;
	bool isNewestOnTop;
	bool isScrollToBottom;
	bool isWindowed;
	int clientId = -1;
	QColor tableColor;
	QString clientName{};
	QString groupName{};
	QString mergeViewName{};
	QString sharedFileName{};
};

#endif // !RT_CLIENT_H
