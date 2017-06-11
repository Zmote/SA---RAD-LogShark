#ifndef RT_SETTINGS_H
#define RT_SETTINGS_H
#include "RT_Client.h"
#include "RT_LogSettings.h"
#include "RT_ViewSettings.h"
#include <QMutex>

/*!
 * \class RT_Settings
 * \brief A static class to manage and access
 * application-wide settings, like log buffer limit
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.1
 * \since 1.4
 */
class RT_Settings
{
public:
	static QString baseFileSaveLocation();
	static void baseFileSaveLocation(QString val);

	static QString toFileSaveLocation();
	static void toFileSaveLocation(QString val);

	static QString toSharedFileSaveLocation();
	static void toSharedFileSaveLocation(QString val);

	static QString toRingFileSaveLocation();
	static void toRingFileSaveLocation(QString val);

	static int logBufferLimit();
	static int messageBufferLimit();

	static int ringBufferLimit();
	static void messageBufferLimit(int val);

	static void logBufferLimit(int val);
	static void ringBufferLimit(int val);

	static void autoRegistrationAllowed(bool val);
	
	/**
	 * \brief Holds auto registration state,
	 * whether clients can auto-register when they
	 * arrive via network
	 * \return auto registration allowed state
	 */
	static bool autoRegistrationAllowed();

	static void currentConfigurationFileName(QString fileName);
	static QString currentConfigurationFileName();

	static QString configurationFilesLocation();

	static int updateInterval();
	static void updateInterval(int pUpdateInterval);

	/**
	 * \brief Loads configuration values from a file
	 * \param fileName path to file
	 * \return if load succeded or not
	 */
	static bool load(QString fileName);
	/**
	 * \brief persist settings to file
	 */
	static void save();
	/**
	 * \brief Resets the settings to their default value
	 */
	static void reset();

	static bool persistGlobalSettings;
	static bool persistViewSettings;

	static QString masterHost;
	static int masterPort;

	static RT_LogSettings logSettings;
	static RT_ViewSettings viewSettings;
	static QList<RT_Client> clients;
	static QList<RT_Client> groups;
private:
	static QString _baseFileSaveLocation;
	static QString _toFileSaveLocation;
	static QString _toSharedFileSaveLocation;
	static QString _toRingFileSaveLocation;

	static int _logBufferLimit;
	static int _ringBufferLimit;
	static int _messageBufferLimit;
	static bool _autoRegistrationAllowed;

	static QString _configurationFilesLocation;
	static QString _currentConfigurationFileName;

	static int _updateInterval;
	static QMutex mutex;
};

#endif //!RT_SETTINGS_H
