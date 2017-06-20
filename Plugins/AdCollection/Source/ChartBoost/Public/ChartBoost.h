
#pragma once

#include "ModuleManager.h"
#include "AdCollection.h"

class FChartBoostModule : public IAdModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual void PlayAd() override;
	virtual void ShowInterstitialAd() override;
};