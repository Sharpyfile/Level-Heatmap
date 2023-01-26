// Fill out your copyright notice in the Description page of Project Settings.

#include "HeatmapManager.h"
#include "HeatmapObject.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"

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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FPaths::ProjectDir() + FileNameA);
	return FFileHelper::LoadFileToString(SaveTextA, *(FPaths::ProjectDir() + FileNameA));
}

void AHeatmapManager::LoadDataNew()
{
	FString temp2;
	LoadTxt(LoadTextFile + ".txt", temp2);
	TArray<FString> Parsed;
	temp2.ParseIntoArray(Parsed, TEXT("|"), false);
	FString objectName = "";
	FString counter = "";

	// Zero it
	for (int i = 0; i < HeatmapObjects.Num(); ++i)
		HeatmapObjects[i]->Counter = 0;
	

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
			FindHeatmapObjectByName(objectName)->Counter = FCString::Atoi64(*counter);
		}
	}

}

bool AHeatmapManager::SaveTxt(FString SaveTextB, FString FileNameB)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FPaths::ProjectDir() + FileNameB);
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::ProjectDir() + FileNameB));
}
