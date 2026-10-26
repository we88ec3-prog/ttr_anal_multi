
void FUN_0052f6b0(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  short sVar1;
  undefined4 in_EAX;
  short *psVar2;
  short *in_EDX;
  undefined4 *unaff_ESI;
  
  unaff_ESI[1] = in_EAX;
  *unaff_ESI = SkillTable::CSkillBase::vftable;
  unaff_ESI[7] = 7;
  unaff_ESI[6] = 0;
  *(undefined2 *)(unaff_ESI + 2) = 0;
  psVar2 = in_EDX;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00402160(in_EDX,(int)psVar2 - (int)(in_EDX + 1) >> 1);
  *(undefined1 *)((int)unaff_ESI + 0x25) = param_1;
  *(undefined1 *)(unaff_ESI + 9) = 1;
  unaff_ESI[0xe] = 0;
  unaff_ESI[0xf] = 7;
  *(undefined2 *)(unaff_ESI + 10) = 0;
  unaff_ESI[0x11] = param_2;
  unaff_ESI[0x12] = param_3;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x13] = SkillTable::CSkillLevelactive::vftable;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1d] = param_5;
  *unaff_ESI = SkillTable::CSkillActive::vftable;
  unaff_ESI[0x13] = SkillTable::CSkillActive::vftable;
  unaff_ESI[0x1c] = param_4;
  unaff_ESI[0x1e] = 0;
  unaff_ESI[0x1f] = 0;
  unaff_ESI[0x20] = 0;
  return;
}

