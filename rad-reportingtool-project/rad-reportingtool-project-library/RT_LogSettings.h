#ifndef RT_LOGSETTINGS_H
#define RT_LOGSETTINGS_H

#include <QMutex>

/*! \class RT_LogSettings
 * A threadsafe Filter class, that contains information
 * to be passed to the clients, what and how they are
 * supposed to be logging
 * 
 * \author Zafer Dogan, <a href="mailto:zdogan@hsr.ch">Zafer Dogan</a>
 * \version 1.3
 * \since 1.0
 */
class RT_LogSettings {
public:
	RT_LogSettings& operator=(const RT_LogSettings& copy);
	bool enableInfo() const;
	bool enableWarning() const;
	bool enableError() const;
	bool enableException() const;
	bool enableFatal() const;
	bool enableBinary() const;

	bool infoMessage() const;
	bool warningMessage() const;
	bool errorMessage() const;
	bool exceptionMessage() const;
	bool fatalMessage() const;

	void enableInfo(bool val);
	void enableWarning(bool val);
	void enableError(bool val);
	void enableException(bool val);
	void enableFatal(bool val);
	void enableBinary(bool val);

	void infoMessage(bool val);
	void warningMessage(bool val);
	void errorMessage(bool val);
	void exceptionMessage(bool val);
	void fatalMessage(bool val);

private:
	mutable QMutex mutex;
	struct MessageStates {
		bool enableInfo = true;
		bool enableWarning = true;
		bool enableError = true;
		bool enableException = true;
		bool enableFatal = true;
		bool enableBinary = true;
	};

	struct BufferTriggers {
		bool infoMessage = false;
		bool warningMessage = false;
		bool errorMessage = true;
		bool exceptionMessage = true;
		bool fatalMessage = true;
	};
	MessageStates messageStates{};
	BufferTriggers bufferTriggers{};
};

#endif // !RT_LOGSETTINGS_H
