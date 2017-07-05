// Some copyright should be here...

using System.IO;
using UnrealBuildTool;

public class AdMob : ModuleRules
{
    private string ModulePath
    {
        get { return ModuleDirectory; }
    }

	public AdMob(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"AdMob/Public"
				
				// ... add public include paths required here ...
			}
			);

        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				
				// ... add other public dependencies that you statically link with here ...
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "AdCollection",

				// ... add private dependencies that you statically link with here ...	
			}
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
        

        if (Target.Platform == UnrealTargetPlatform.IOS)
        {
            PrivateIncludePaths.Add("Private/IOS");
            PrivateIncludePaths.Add("../AdCollection/ThirdPartyFrameworks/VungleAdmobIOS/");

            string strStaticPath = Path.GetFullPath( Path.Combine( ModulePath, "../AdCollection/ThirdPartyFrameworks/VungleAdmobIOS/" ) );

            PublicLibraryPaths.Add(strStaticPath);

            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "GoogleMobileAds",														// Framework name
            "../AdCollection/ThirdPartyFrameworks/GoogleMobileAds.embeddedframework.zip")
            );

            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "UnityAds",														// Framework name
            "../AdCollection/ThirdPartyFrameworks/UnityAds.embeddedframework.zip")
            );


            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "VungleSDK",														// Framework name
            "../AdCollection/ThirdPartyFrameworks/VungleSDK.embeddedframework.zip")
            );

            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "Chartboost",														// Framework name
            "../AdCollection/ThirdPartyFrameworks/Chartboost.embeddedframework.zip")
            );


            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "AdColony",														// Framework name
            "../AdCollection/ThirdPartyFrameworks/AdColony-iOS-SDK-3.zip")
            );


            // adapter
            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "UnityAdapter",														// Framework name
            "../AdCollection/ThirdPartyFrameworks/UnityAdapter-2.1.0.0.zip")
            );

            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "ChartboostAdapter",														// Framework name
            "../AdCollection/ThirdPartyFrameworks/ChartboostAdapter-6.6.3.0.zip")
            );
            

            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "AdColonyAdapter",														// Framework name
            "../AdCollection/ThirdPartyFrameworks/AdColonyAdapter-3.1.1.0.zip")
            );


            // helper lib
            PublicAdditionalFrameworks.Add(
            new UEBuildFramework(
            "AdsUtil",														// Framework name
            "../AdCollection/ThirdPartyFrameworks/AdsUtil.embeddedframework.zip")
            );

            PublicAdditionalLibraries.Add("VungleAdapter");
            PublicAdditionalShadowFiles.Add("../AdCollection/ThirdPartyFrameworks/VungleAdmobIOS/libVungleAdapter.a");


            PublicFrameworks.AddRange(
            new string[]
            {
            "EventKit",
            "MediaPlayer",
            "AdSupport",
            "CoreLocation",
            "SystemConfiguration",
            "MessageUI",
            "Security",
            "CoreTelephony"
            }
            );



        }
        else if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateIncludePaths.Add("Private/Android");
            PrivateDependencyModuleNames.AddRange(
                new string[] {
                "Launch",
                }
                );

            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, BuildConfiguration.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "AdMob_UPL.xml")));
        }
        else if (Target.Platform == UnrealTargetPlatform.Win32 || Target.Platform == UnrealTargetPlatform.Win64)
        {
            PrivateIncludePaths.Add("Private/Windows");
        }
        else if(Target.Platform == UnrealTargetPlatform.Mac)
        {
            PrivateIncludePaths.Add("Private/Mac");
        }
        else
        {
            PrecompileForTargets = PrecompileTargetsType.None;
        }
    }
}
