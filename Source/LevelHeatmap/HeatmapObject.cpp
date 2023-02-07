// Fill out your copyright notice in the Description page of Project Settings.

#include "HeatmapObject.h"

// Sets default values
AHeatmapObject::AHeatmapObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

FString AHeatmapObject::GetProperName()
{
	return this->GetName();
}

// Called when the game starts or when spawned
void AHeatmapObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHeatmapObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

