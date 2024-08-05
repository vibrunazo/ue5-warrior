// vibrunazo


#include "AbilitySystem/Abilities/WarriorHeroGameplayAbility.h"

#include "Characters/WarriorHeroCharacter.h"
#include "Controllers/WarriorHeroController.h"

AWarriorHeroCharacter* UWarriorHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedWarriorHeroCharacter.IsValid())
	{
		CachedWarriorHeroCharacter = Cast<AWarriorHeroCharacter>(GetAvatarActorFromActorInfo());
	}
	
	return CachedWarriorHeroCharacter.IsValid() ? CachedWarriorHeroCharacter.Get() : nullptr;
}

AWarriorHeroController* UWarriorHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedWarriorHeroController.IsValid())
	{
		CachedWarriorHeroController = Cast<AWarriorHeroController>(GetAvatarActorFromActorInfo());
	}
	
	return CachedWarriorHeroController.IsValid() ? CachedWarriorHeroController.Get() : nullptr;
}

UHeroCombatComponent* UWarriorHeroGameplayAbility::GetHeroCombatComponentFromActorInfo()
{
	return GetHeroCharacterFromActorInfo() ? GetHeroCharacterFromActorInfo()->GetHeroCombatComponent() : nullptr;
}
