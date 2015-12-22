// Fill out your copyright notice in the Description page of Project Settings.

#include "DML_UE4_Course.h"
#include "MyCharacter.h"
#include "Lesson/Nov18/BaseCharacterAnimation.h"


// Sets default values
AMyCharacter::AMyCharacter(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ���������� ������ ACharacter �����������, ������� �������� � ��� ���������� ������, � ������ ����� ������
	GetCapsuleComponent()->InitCapsuleSize(28.f, 92.f);	// ������ ������� ������� ���������. ������ �������� - ������, ������ - �������� ������ �������.

	bUseControllerRotationYaw = false; // �������� �� ����� ������������ ������� ������ �����������

	GetCharacterMovement()->bOrientRotationToMovement = true; // ������������ ��������� �� ����������� ���������, ��� ��������� ��� �������� ������ ��������� �� ��� �������

	GetMesh()->AddRelativeLocation(FVector(0, 0, -92.f));		// �������� ��������� ���(3D ������) �� 92 ����� ����. 1 ���� = 1 �������� ���������
	GetMesh()->AddRelativeRotation(FRotator(0, -90.f, 0));		// � ��� �� ������������ �� 90 �������� �����

	DefaultHealth = 100;
	Health = DefaultHealth;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{

	Super::BeginPlay();

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("Punch", IE_Pressed, this, &AMyCharacter::BeginPunching);
	InputComponent->BindAction("Punch", IE_Released, this, &AMyCharacter::EndPunching);

}

void AMyCharacter::SetHealth(int32 NewHealth)
{
	Health = NewHealth;
}

int32 AMyCharacter::GetHealth() const
{
	return Health;
}

void AMyCharacter::BeginPunching()
{
	UBaseCharacterAnimation* CharAnim = Cast<UBaseCharacterAnimation>(GetMesh()->GetAnimInstance());

	if (CharAnim)
	{
		CharAnim->BeginPunch();
	}
}

void AMyCharacter::EndPunching()
{
	UBaseCharacterAnimation* CharAnim = Cast<UBaseCharacterAnimation>(GetMesh()->GetAnimInstance());

	if (CharAnim)
	{
		CharAnim->EndPunch();
	}
}