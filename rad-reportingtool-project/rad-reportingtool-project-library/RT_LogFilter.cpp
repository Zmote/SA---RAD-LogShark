#include "RT_LogFilter.h"
#include <QStringList>

RT_LogFilter::RT_LogFilter(const QString& searchTerm, bool isCaseSentsitive):plainSearchTerm(searchTerm)
{
	Qt::CaseSensitivity caseSensitivity = isCaseSentsitive ? Qt::CaseSensitive : Qt::CaseInsensitive;
	QStringList list = searchTerm.split(splitRegex, QString::SkipEmptyParts);
	for(int i = 0; i < list.size();)
	{
		if (i + 1 >= list.size()) break;
		QString key = list.at(i);
		QString entry = list.at(i + 1);
		if (key.contains("Date") || key.contains("date"))
		{
			dateTerm = QRegExp(entry, caseSensitivity);
		}
		if (key.contains("Time") || key.contains("time"))
		{
			timeTerm = QRegExp(entry, caseSensitivity);
		}
		if (key.contains("Client") || key.contains("client"))
		{
			clientNameTerm = QRegExp(entry, caseSensitivity);;
		}
		if (key.contains("Group") || key.contains("group"))
		{
			groupNameTerm = QRegExp(entry, caseSensitivity);
		}
		if (key.contains("Kind") || key.contains("kind"))
		{
			messageKindTerm = QRegExp(entry, caseSensitivity);;
		}
		if (key.contains("Content") || key.contains("content"))
		{
			contentTerm = QRegExp(entry, caseSensitivity);
		}
		i = i + 2;
	}
}

QStringList RT_LogFilter::toString() const
{
	QStringList output{};
	output.append("Date: " + dateTerm.pattern());
	output.append("Time: " + timeTerm.pattern());
	output.append("Group: " + groupNameTerm.pattern());
	output.append("Client: " + clientNameTerm.pattern());
	output.append("Kind: " + messageKindTerm.pattern());
	output.append("Content: " + contentTerm.pattern());
	return output;
}

bool RT_LogFilter::isValid()
{
	return plainSearchTerm.contains(searchTermRegex) && dateTerm.isValid() && timeTerm.isValid() && clientNameTerm.isValid()
	&& groupNameTerm.isValid() && messageKindTerm.isValid() && contentTerm.isValid();
}

