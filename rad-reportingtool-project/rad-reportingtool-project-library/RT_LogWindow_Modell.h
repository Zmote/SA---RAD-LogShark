#ifndef RT_LOGWINDOW_MODELL_H
#define RT_LOGWINDOW_MODELL_H
#include "RT_LogFilter.h"
#include "RT_Client.h"

/**
 * \class RT_LogWindow_Modell
 * \brief Modell for \ref RT_LogWindow
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.1
 * \since 1.1
 */
class RT_LogWindow_Modell {
public:
	RT_LogWindow_Modell(RT_Client & pClient, bool pIsIndependent);
	RT_LogFilter filter;
	RT_Client & client;
	bool isIndependent;
};

#endif // !RT_LOGWINDOW_MODELL_H
