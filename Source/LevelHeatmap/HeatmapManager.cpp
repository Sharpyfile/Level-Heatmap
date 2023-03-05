// Fill out your copyright notice in the Description page of Project Settings.

#include "HeatmapManager.h"
#include "HeatmapObject.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "HAL/FilemanagerGeneric.h"

// Sets default values
AHeatmapManager::AHeatmapManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHeatmapManager::BeginPlay()
{
	Super::BeginPlay();
	
}

FVector2D AHeatmapManager::GetGameViewportSize()
{
	return FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
}

AHeatmapObject* AHeatmapManager::FindHeatmapObjectByName(FString objectName)
{
	for (int i = 0; i < this->HeatmapObjects.Num(); ++i)
	{
		if (this->HeatmapObjects[i] != nullptr)
		{
			if (this->HeatmapObjects[i]->GetProperName().Equals(objectName))
				return this->HeatmapObjects[i];
		}
	}

	return nullptr;
}

// Called every frame
void AHeatmapManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AHeatmapManager::LoadTxt(FString FileNameA, FString& SaveTextA)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FPaths::ProjectDir() + FileNameA);
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::ProjectDir() + FileNameA));
}

void AHeatmapManager::LoadDataNew(int cameraType)
{
	FString temp2;
	LoadTxt(LoadTextFile + ".txt", temp2);
	TArray<FString> Parsed;
	temp2.ParseIntoArray(Parsed, TEXT("|"), false);
	FString objectName = "";
	FString counter = "";

	// Zero it
	for (int i = 0; i < HeatmapObjects.Num(); ++i)
	{
		if (cameraType == -1)
			HeatmapObjects[i]->Counter = 0;
		else if (cameraType == 0)
			HeatmapObjects[i]->CounterFPP = 0;
		else if (cameraType == 1)
			HeatmapObjects[i]->CounterTPP = 0;
		else if (cameraType == 2)
			HeatmapObjects[i]->CounterCS = 0;
		else
			HeatmapObjects[i]->Counter = 0;
	}	

	for (int i = 0; i < Parsed.Num(); ++i)
	{
		objectName = "";
		counter = "";
		Parsed[i].Split(TEXT(", "), &objectName, &counter);
		objectName = objectName.Replace(TEXT("N:"), TEXT(""), ESearchCase::IgnoreCase);
		counter = counter.Replace(TEXT("C:"), TEXT(""), ESearchCase::IgnoreCase);

		if (FCString::Atoi64(*counter) == 0)
			continue;
		
		AHeatmapObject* foundObject = FindHeatmapObjectByName(objectName);
		if (foundObject != nullptr)
		{
			if (cameraType == -1)
				FindHeatmapObjectByName(objectName)->Counter = FCString::Atoi64(*counter);
			else if (cameraType == 0)
				FindHeatmapObjectByName(objectName)->CounterFPP = FCString::Atoi64(*counter);
			else if (cameraType == 1)
				FindHeatmapObjectByName(objectName)->CounterTPP = FCString::Atoi64(*counter);
			else if (cameraType == 2)
				FindHeatmapObjectByName(objectName)->CounterCS = FCString::Atoi64(*counter);
			else
				FindHeatmapObjectByName(objectName)->Counter = FCString::Atoi64(*counter);
		}
	}
}

void AHeatmapManager::LoadDataAdditiveSpecific(FString path, int cameraType)
{
	FString temp2;
	LoadTxt(path, temp2);
	TArray<FString> Parsed;
	temp2.ParseIntoArray(Parsed, TEXT("|"), false);
	FString objectName = "";
	FString counter = "";

	for (int i = 0; i < Parsed.Num(); ++i)
	{
		objectName = "";
		counter = "";
		Parsed[i].Split(TEXT(", "), &objectName, &counter);
		objectName = objectName.Replace(TEXT("N:"), TEXT(""), ESearchCase::IgnoreCase);
		counter = counter.Replace(TEXT("C:"), TEXT(""), ESearchCase::IgnoreCase);

		if (FCString::Atoi64(*counter) == 0)
			continue;

		AHeatmapObject* foundObject = FindHeatmapObjectByName(objectName);
		if (foundObject != nullptr)
		{
			if (cameraType == -1)
				FindHeatmapObjectByName(objectName)->Counter += FCString::Atoi64(*counter);
			else if (cameraType == 0)
				FindHeatmapObjectByName(objectName)->CounterFPP += FCString::Atoi64(*counter);
			else if (cameraType == 1)
				FindHeatmapObjectByName(objectName)->CounterTPP += FCString::Atoi64(*counter);
			else if (cameraType == 2)
				FindHeatmapObjectByName(objectName)->CounterCS += FCString::Atoi64(*counter);
			else
				FindHeatmapObjectByName(objectName)->Counter += FCString::Atoi64(*counter);
		}
	}
}

//void AHeatmapManager::LoadDataAdditiveDirectory(FString directoryPath, int cameraType)
//{
//	for (int i = 0; i < HeatmapObjects.Num(); ++i)
//	{
//		if (cameraType == -1)
//			HeatmapObjects[i]->Counter = 0;
//		else if (cameraType == 0)
//			HeatmapObjects[i]->CounterFPP = 0;
//		else if (cameraType == 1)
//			HeatmapObjects[i]->CounterTPP = 0;
//		else if (cameraType == 2)
//			HeatmapObjects[i]->CounterCS = 0;
//		else
//			HeatmapObjects[i]->Counter = 0;
//	}
//
//	FString path = FPaths::ProjectDir() + directoryPath + "/";
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, path);
//	TArray<FString> FoundFiles;
//	FFileManagerGeneric::Get().FindFiles(FoundFiles, *path, TEXT(".txt"));
//
//	for (int i = 0; i < FoundFiles.Num(); ++i)
//	{
//		LoadDataAdditiveSpecific(directoryPath + "/" + FoundFiles[i], cameraType);
//		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, directoryPath + "/" + FoundFiles[i]);
//	}
//}

void AHeatmapManager::LoadDataAdditiveDirectory(FString directoryPath, int cameraType)
{
	for (int i = 0; i < HeatmapObjects.Num(); ++i)
	{
		HeatmapObjects[i]->Counter = 0;
		HeatmapObjects[i]->CounterFPP = 0;
		HeatmapObjects[i]->CounterTPP = 0;
		HeatmapObjects[i]->CounterCS = 0;
	}

	FString path = FPaths::ProjectDir() / "Badania/*";
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, path);
	TArray<FString> FoundDirectories;
	TArray<FString> FoundSubDirectories;
	TArray<FString> FoundFiles;
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(FoundDirectories, *path, true, true);


	// Level name
	FString worldName = GetWorld()->GetMapName();
	worldName.RemoveFromStart(GetWorld()->StreamingLevelsPrefix);

	// L-NL-A, NL-A-L, A-L-NL
	for (int i = 0; i < FoundDirectories.Num(); ++i)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FoundDirectories[i]);
		// 1, 2, 3, 4, 5, 6, etc.
		FString newPath = path;
		newPath.RemoveFromEnd(TEXT("*"));
		newPath += FoundDirectories[i] / TEXT("*");
		FileManager.FindFiles(FoundSubDirectories, *newPath, true, true);

		// LinearMap-FPP, etc.
		for (int y = 0; y < FoundSubDirectories.Num(); ++y)
		{
			FString newFilePath = newPath;
			newFilePath.RemoveFromEnd(TEXT("*"));
			newFilePath += FoundSubDirectories[y] / TEXT("*");

			FileManager.FindFiles(FoundFiles, *newFilePath, true, true);

			// Now check every file and read it
			for (int z = 0; z < FoundFiles.Num(); ++z)
			{
				FString directPath = newFilePath;
				directPath.RemoveFromEnd(TEXT("*"));
				directPath += "/" + FoundFiles[z];

				if (FoundFiles[z].Contains(worldName))
				{
					if (FoundFiles[z].Contains("FPP"))
					{
						LoadDataAdditiveSpecific(directPath, 0);
					}
					else if (FoundFiles[z].Contains("TPP"))
					{
						LoadDataAdditiveSpecific(directPath, 1);
					}
					else if (FoundFiles[z].Contains("CS"))
					{
						LoadDataAdditiveSpecific(directPath, 2);
					}						
				}			
			}
			FoundFiles.Empty();
		}

		FoundSubDirectories.Empty();
	}

	FoundDirectories.Empty();
}

bool AHeatmapManager::SaveTxt(FString SaveTextB, FString FileNameB)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FPaths::ProjectDir() + FileNameB);
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::ProjectDir() + FileNameB));
}
