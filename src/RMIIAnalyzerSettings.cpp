#include "RMIIAnalyzerSettings.h"
#include <AnalyzerHelpers.h>

RMIIAnalyzerSettings::RMIIAnalyzerSettings()
:	mDataChannel( UNDEFINED_CHANNEL ), mClockChannel( UNDEFINED_CHANNEL )
{

	mDataChannelInterface.reset( new AnalyzerSettingInterfaceChannel() );
	mDataChannelInterface->SetTitleAndTooltip( "Data", "Standard Simple Data" );
	mDataChannelInterface->SetChannel( mDataChannel );

	mClockChannelInterface.reset( new AnalyzerSettingInterfaceChannel() );
	mClockChannelInterface->SetTitleAndTooltip( "Clock", "Standard Simple Clock" );
	mClockChannelInterface->SetChannel( mClockChannel );

	AddInterface( mDataChannelInterface.get() );
	AddInterface( mClockChannelInterface.get() );

	AddExportOption( 0, "Export as text file" );
	AddExportExtension( 0, "text", "txt" );

	ClearMe(false);

}

void RMIIAnalyzerSettings::ClearMe(bool flag) {
	ClearChannels();
	AddChannel( mDataChannel, "Data", flag );	
	AddChannel( mClockChannel, "Clock", flag );
}

RMIIAnalyzerSettings::~RMIIAnalyzerSettings() {}

bool RMIIAnalyzerSettings::SetSettingsFromInterfaces()
{
	mDataChannel  = mDataChannelInterface->GetChannel();
	mClockChannel = mClockChannelInterface->GetChannel();

	ClearMe(true);

	return true;
}

void RMIIAnalyzerSettings::UpdateInterfacesFromSettings()
{
	mDataChannelInterface->SetChannel( mDataChannel );
	mClockChannelInterface->SetChannel( mClockChannel );
}

void RMIIAnalyzerSettings::LoadSettings( const char* settings )
{

	SimpleArchive text_archive;
	text_archive.SetString( settings );

	text_archive >> mDataChannel;
	text_archive >> mClockChannel;

	ClearMe(true);

	UpdateInterfacesFromSettings();
}

const char* RMIIAnalyzerSettings::SaveSettings()
{
	SimpleArchive text_archive;

	text_archive << mDataChannel;
	text_archive << mClockChannel;

	return SetReturnString( text_archive.GetString() );
}

