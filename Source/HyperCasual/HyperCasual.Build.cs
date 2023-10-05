// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HyperCasual : ModuleRules
{
	public HyperCasual(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG" });
	}
}
