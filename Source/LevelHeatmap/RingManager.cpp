// Fill out your copyright notice in the Description page of Project Settings.


#include "RingManager.h"
#include "HeatmapManager.h"

// Sets default values for this component's properties
URingManager::URingManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void URingManager::GenerateRings()
{
	FVector2D resolution = AHeatmapManager::GetGameViewportSize();

	// For now divide by 3 to get A and B as X and Y
	resolution /= 4;

	FVector A, B, C, D;
	A = FVector(800, -resolution.X,	-resolution.Y);
	B = FVector(800, resolution.X,	-resolution.Y);
	C = FVector(800, resolution.X,	resolution.Y);	
	D = FVector(800, -resolution.X,	resolution.Y);

	int count = OuterRingLength - 1;
	OuterRing.Add(A);
	OuterRing.Add(B);
	OuterRing.Add(C);
	OuterRing.Add(D);

	float xLength = (resolution.X * 2) / count;
	float yLength = (resolution.Y * 2) / count;

	// add to A	
	for (int i = 0; i < count; ++i)
	{
		FVector AHorizontal = A;
		FVector DHorizontal = D;
		FVector AVertical = A;
		FVector BVertical = B;
		AHorizontal.Y += (xLength) * i+1;
		DHorizontal.Y += (xLength) * i+1;
		AVertical.Z += (yLength) * i+1;
		BVertical.Z += (yLength) * i+1;
		OuterRing.Add(AHorizontal);
		OuterRing.Add(DHorizontal);
		OuterRing.Add(AVertical);
		OuterRing.Add(BVertical);
	}

	// Now middle ring, Divide it by 4
	resolution /= 3;
	// Again, same stuff
	A = FVector(800, -resolution.X, -resolution.Y);
	B = FVector(800, resolution.X, -resolution.Y);
	C = FVector(800, -resolution.X, resolution.Y);
	D = FVector(800, resolution.X, resolution.Y);

	count = MiddleRingLength - 1;
	MiddleRing.Add(A);
	MiddleRing.Add(B);
	MiddleRing.Add(C);
	MiddleRing.Add(D);

	// add to A	
	xLength = (resolution.X * 2) / count;
	yLength = (resolution.Y * 2) / count;

	// add to A	
	for (int i = 0; i < count; ++i)
	{
		FVector AHorizontal = A;
		FVector DHorizontal = D;
		FVector AVertical = A;
		FVector BVertical = B;
		AHorizontal.Y += (xLength)*i + 1;
		DHorizontal.Y += (xLength)*i + 1;
		AVertical.Z += (yLength)*i + 1;
		BVertical.Z += (yLength)*i + 1;
		MiddleRing.Add(AHorizontal);
		MiddleRing.Add(DHorizontal);
		MiddleRing.Add(AVertical);
		MiddleRing.Add(BVertical);
	}
}

// Called when the game starts
void URingManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URingManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

