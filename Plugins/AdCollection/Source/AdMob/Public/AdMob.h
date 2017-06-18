
#pragma once

#include "ModuleManager.h"
#include "AdCollection.h"

class FAdMobModule : public IAdModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual void ShowBanner(const FString adUnit, enAdsBannerPos pos) override;
	virtual void HideBanner() override;
};