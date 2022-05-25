// Fill out your copyright notice in the Description page of Project Settings.


#include "HeatmapManager.h"
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

bool AHeatmapManager::SaveTxt(FString SaveTextB, FString FileNameB)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FPaths::ProjectDir() + FileNameB);
	return FFileHelper::SaveStringToFile(SaveTextB, *(FPaths::ProjectDir() + FileNameB));
}
