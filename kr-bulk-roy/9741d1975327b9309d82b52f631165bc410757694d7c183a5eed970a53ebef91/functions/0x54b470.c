
/* WARNING: Removing unreachable block (ram,0x0054b5ea) */

void FUN_0054b470(void)

{
  undefined4 *puVar1;
  
  FUN_008084f0();
  FUN_00402a70("BATTLE",6);
  FUN_00808bd0();
  FUN_00402a70("PARTNER1_PINCH",0xe);
  FUN_00808bd0();
  FUN_00402a70("PARTNER2_PINCH",0xe);
  FUN_00808bd0();
  FUN_00402a70("MY_PINCH",8);
  FUN_00808bd0();
  puVar1 = (undefined4 *)FUN_00891268();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = SubAI::CDistCondition::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
  }
  FUN_008095d0();
  puVar1 = (undefined4 *)FUN_00891268();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = SubAI::CTierCheckCondition::vftable;
    puVar1[1] = 0;
  }
  FUN_008095d0();
  puVar1 = (undefined4 *)FUN_00891268();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = SubAI::CSkillCheckCondition::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
  }
  FUN_008095d0();
  puVar1 = (undefined4 *)FUN_00891268();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = SubAI::CPhaseCondition::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
  }
  FUN_008095d0();
  puVar1 = (undefined4 *)FUN_00891268();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = SubAI::CMoveAction::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
  }
  FUN_008095d0();
  puVar1 = (undefined4 *)FUN_00891268();
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = SubAI::CAttackAction::vftable;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0xffffffff;
    puVar1[4] = 0;
  }
  FUN_008095d0();
  FUN_00808730();
  return;
}

