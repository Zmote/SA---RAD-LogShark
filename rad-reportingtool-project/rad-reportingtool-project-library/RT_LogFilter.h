#ifndef RT_LOGFILTER_H
#define RT_LOGFILTER_H
#include <QRegExp>

/*!
 * \class RT_LogFilter
 * \brief A filter class, to manage complex filter terms. The filter class
 * takes a filter string as constructor argument and constructs the filter
 * object by taking apart the string 
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.1
 * \since 1.3
 */
class RT_LogFilter
{
public:
	explicit RT_LogFilter(const QString& searchTerm = "", bool isCaseSensitive = false);
	QStringList toString() const;
	/**
	 * \brief To determine if the entered filter string is valid
	 * \return if entered regex is a valid filter regex
	 */
	bool isValid();
	QRegExp dateTerm;
	QRegExp timeTerm;
	QRegExp groupNameTerm;
	QRegExp clientNameTerm;
	QRegExp messageKindTerm;
	QRegExp contentTerm;

	QString plainSearchTerm;
private:
	QRegExp searchTermRegex{"^((Content|Date|Time|Client|Group|Kind)(=)[a-zA-Z0-9\\^\\$,;:-\\+\\*%\\\\\\?\\~\\'\\[\\]{}!¨_()\\|& ]+(&{2})?)*$"};
	QRegExp splitRegex{"=|&&"};
};

#endif //!RT_LOGFILTER_H
