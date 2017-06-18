
#pragma once

#include "ModuleManager.h"
#include "AdCollection.h"

class FAdMobModule : public IAdModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual bool PlayAd() override;
};