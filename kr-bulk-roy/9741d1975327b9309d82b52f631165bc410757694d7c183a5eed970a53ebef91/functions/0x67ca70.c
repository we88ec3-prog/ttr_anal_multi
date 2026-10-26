
/* WARNING: Type propagation algorithm not settling */

void FUN_0067ca70(int *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uStack_94;
  int *piStack_90;
  int iStack_8c;
  int *piStack_88;
  int aiStack_84 [5];
  uint auStack_64 [2];
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  void *pvStack_44;
  undefined4 uStack_38;
  undefined4 uStack_2c;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00932e14;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  aiStack_84[4] = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  aiStack_84[3] = 0x67cac6;
  FUN_00757710();
  aiStack_84[3] = 0;
  aiStack_84[2] = 0;
  aiStack_84[1] = 0xffffffff;
  aiStack_84[0] = -1;
  piStack_88 = (int *)0x67cadf;
  (**(code **)(*(int *)param_1[0x3e] + 0x19c))();
  piStack_88 = (int *)0x0;
  iStack_8c = 0;
  piStack_90 = (int *)0xffffffff;
  uStack_94 = 0xffffffff;
  (**(code **)(*(int *)param_1[0x41] + 0x19c))();
  FUN_00757710();
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    uStack_2c = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    uStack_2c = 0xffffffff;
  }
  aiStack_84[1] = 0x1a;
  FUN_005740f0(aiStack_84 + 1);
  if (aiStack_84[0] == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  uVar3 = FUN_004068f0();
  uStack_2c = 1;
  FUN_00757800(uVar3);
  uStack_2c = 0xffffffff;
  if (7 < auStack_64[0]) {
    FUN_0089120c(aiStack_84[3]);
  }
  (**(code **)(*(int *)param_1[0x3d] + 0x94))(0);
  (**(code **)(*(int *)param_1[0x46] + 0x94))(0);
  (**(code **)(*(int *)param_1[0x45] + 0x90))(0);
  piVar6 = param_1 + 0x48;
  piStack_88 = param_1 + 0x3f;
  iStack_8c = 2;
  do {
    piStack_90 = piVar6;
    (**(code **)(*(int *)*piStack_88 + 0x19c))(0xffffffff,0xffffffff,0,0);
    FUN_005d99d0(0xffffffff);
    piVar4 = (int *)FUN_00891268(0x1c);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      iVar5 = piVar6[1];
      iVar1 = *piVar6;
      piVar4[1] = -1;
      piVar4[2] = -1;
      piVar4[3] = 0;
      piVar4[4] = 0xf4369;
      *piVar4 = (int)FoxUI::FXUIEventI2::vftable;
      piVar4[5] = iVar1;
      piVar4[6] = iVar5;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      uStack_38 = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      uStack_38 = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))(piVar4);
    }
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x10))(1);
    }
    piStack_88 = piStack_88 + 1;
    aiStack_84[0] = -1;
    aiStack_84[1] = 0xffffffff;
    aiStack_84[2] = 0xffffffff;
    aiStack_84[3] = 0xffffffff;
    piVar6 = piStack_90 + 0xe;
    iStack_8c = iStack_8c + -1;
    aiStack_84[4] = 0;
    auStack_64[0] = auStack_64[0] & 0xffffff00;
    uStack_5c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    uStack_50 = 0;
    piVar4 = aiStack_84;
    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piStack_90 = *piVar4;
      piVar4 = piVar4 + 1;
      piStack_90 = piStack_90 + 1;
    }
  } while (iStack_8c != 0);
  piStack_90 = piVar6;
  FUN_00757710();
  (**(code **)(*(int *)param_1[0x66] + 0x94))(0);
  (**(code **)(*param_1 + 200))();
  ExceptionList = pvStack_44;
  __security_check_cookie(uStack_4c ^ (uint)&uStack_94);
  return;
}

