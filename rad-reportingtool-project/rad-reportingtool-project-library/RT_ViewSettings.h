#ifndef RT_VIEWSETTINGS_H
#define RT_VIEWSETTINGS_H

/*! \class RT_ViewSettings
 * Class for tracking application view states
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.0
 * \since 1.4
 */
struct RT_ViewSettings
{
	bool useDateStamp = true;
	bool useTimeStamp = true;
	bool useGroupStamp = true;
	bool useClientStamp = true;
	bool useMessageHeaderStamp = true;
	bool useContentStamp = true;
	bool showFilterArea = true;
	bool showLogDetailArea = true;
	bool showClientSection = true;
	bool showGroupSection = true;
};

#endif //!RT_VIEWSETTINGS_H
