
#pragma once

#include "ModuleManager.h"
#include "AdCollection.h"

class FVungleModule : public IAdModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual void PlayAd() override;
};