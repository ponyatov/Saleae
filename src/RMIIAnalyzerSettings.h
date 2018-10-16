#ifndef _H_RMII_SETTINGS
#define _H_RMII_SETTINGS

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

private:
	void				ClearMe(bool flag);

protected:

	std::auto_ptr< AnalyzerSettingInterfaceChannel >	mDataChannelInterface;
	std::auto_ptr< AnalyzerSettingInterfaceChannel >	mClockChannelInterface;

};

#endif // _H_RMII_SETTINGS

