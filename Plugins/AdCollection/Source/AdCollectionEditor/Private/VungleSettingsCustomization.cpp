// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "AdCollectionEditor.h"
#include "VungleSettingsCustomization.h"
#include "Modules/ModuleManager.h"
#include "Layout/Visibility.h"
#include "UnrealClient.h"
#include "Interfaces/ITargetPlatformManagerModule.h"
#include "VungleSetting.h"
#include "PropertyHandle.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "IDetailPropertyRow.h"

#define LOCTEXT_NAMESPACE "VungleSettings"

//////////////////////////////////////////////////////////////////////////
// FAndroidSDKSettingsCustomization

TSharedRef<IDetailCustomization> FVungleSettingsCustomization::MakeInstance()
{
	return MakeShareable(new FVungleSettingsCustomization);
}

FVungleSettingsCustomization::FVungleSettingsCustomization()
{
	TargetPlatformManagerModule = &FModuleManager::LoadModuleChecked<ITargetPlatformManagerModule>("TargetPlatform");
}

void FVungleSettingsCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailLayout)
{
	SavedLayoutBuilder = &DetailLayout;
	BuildSDKPathSection(DetailLayout);
}


void FVungleSettingsCustomization::BuildSDKPathSection(IDetailLayoutBuilder& DetailLayout)
{
}

//////////////////////////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
