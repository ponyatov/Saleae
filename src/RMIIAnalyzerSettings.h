#ifndef _H_HELLO_SETTINGS
#define _H_HELLO_SETTINGS

#include <AnalyzerSettings.h>
#include <AnalyzerTypes.h>

class RMIIAnalyzerSettings : public AnalyzerSettings
{

public:
						 RMIIAnalyzerSettings();
	virtual				~RMIIAnalyzerSettings();

	virtual bool		SetSettingsFromInterfaces();
	void				UpdateInterfacesFromSettings();
	virtual void		LoadSettings( const char* settings );
	virtual const char* SaveSettings();

	Channel mDataChannel;
	Channel mClockChannel;

protected:

	std::auto_ptr< AnalyzerSettingInterfaceChannel >	mDataChannelInterface;
	std::auto_ptr< AnalyzerSettingInterfaceChannel >	mClockChannelInterface;

};

#endif // _H_HELLO_SETTINGS

