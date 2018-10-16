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


}

RMIIAnalyzerSettings::~RMIIAnalyzerSettings() {}


