// Some copyright should be here...

using System.IO;
using UnrealBuildTool;

public class Vungle : ModuleRules
{
	public Vungle(TargetInfo Target)
	{
		
		PublicIncludePaths.AddRange(
			new string[] {
				"Vungle/Public"
				
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
            AdditionalPropertiesForReceipt.Add(new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "Vungle_UPL.xml")));
        }
        else if (Target.Platform == UnrealTargetPlatform.Win32 || Target.Platform == UnrealTargetPlatform.Win64)
        {
            PrivateIncludePaths.Add("Private/Windows");
        }
        else
        {
            PrecompileForTargets = PrecompileTargetsType.None;
        }
    }
}
