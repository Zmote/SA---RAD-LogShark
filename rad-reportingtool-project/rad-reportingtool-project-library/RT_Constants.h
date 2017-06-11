#ifndef RT_CONSTANTS_H
#define RT_CONSTANTS_H
#include <QString>

/*!
 * \brief namespace of constant values used accross the application
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.4
 * \since 1.1
 */
namespace RT_Constants
{
	const QString GLOBAL = "Global";
	const QString EMPTY_STATE = "-";
	const QString LIVE = "Live";
	const QString TO_FILE = "To File";
	const QString TO_RING_FILE = "To Ring File";
	const QString TO_SHARED_FILE = "To Shared File";
	const QString TO_PARENT = "To Parent";
	const QString TO_GLOBAL = "To Global";
	const QString TO_MERGE_VIEW = "To MergeView";
	const QString MK_INFO = "Info";
	const QString MK_WARNING = "Warning";
	const QString MK_ERROR = "Error";
	const QString MK_EXCEPTION = "Exception";
	const QString MK_FATAL = "Fatal";
	const QString MK_UNRECOGNIZED = "Unrecognized";
	const QString MERGEVIEW_PREFIX = "MERGEVIEW_";
	const QString SHAREDFILE_PREFIX = "SHAREDFILE_";
	const QString RINGFILE_PREFIX = "RINGFILE_";
	const QString QTREEVIEW_ACTIVE_SELECTION_CSS = "QTreeView::item:selected:!active{background-color:#cce6ff}";
	const QString QTABLEVIEW_ACTIVE_SELECTION_CSS = "QTableView::item:selected:!active{background-color:#cce6ff}";
	const int GLOBAL_ID = -1;
	const int GROUP_ID = -2;
	const int baseUpdateInterval = 200;
}
#endif // !RT_CONSTANTS_H