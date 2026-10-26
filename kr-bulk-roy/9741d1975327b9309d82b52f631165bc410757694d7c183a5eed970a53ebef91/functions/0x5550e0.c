
undefined4 FUN_005550e0(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929596;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  FUN_00402a70("nodafile",8);
  FUN_00402a70("nodafile",8);
  if (*(uint *)(param_1 + 8) <= param_2) {
    ExceptionList = local_14;
    return 0;
  }
  piVar4 = (int *)FUN_00555a00(param_1);
  iVar6 = *piVar4;
  uVar2 = (piVar4[1] - iVar6) / 0x1c;
  if (uVar2 <= param_3) {
    ExceptionList = local_14;
    return 0;
  }
  switch(param_2) {
  case 1:
  case 3:
  case 7:
    if (uVar2 == 0) goto LAB_0055519d;
    iVar6 = iVar6 + param_3 * 0x1c;
  case 0:
  case 5:
    break;
  case 2:
  case 4:
  case 6:
    if (uVar2 == 0) goto LAB_0055519d;
    uVar3 = FUN_0089289d();
    iVar6 = *piVar4 + (uVar3 % uVar2) * 0x1c;
    break;
  default:
    if ((DAT_00fe1e44 & 1) == 0) {
      DAT_00fe1e44 = DAT_00fe1e44 | 1;
      local_c = 0;
      FUN_00531b40(uVar3);
      _atexit(thunk_FUN_00531c60);
      local_c = 0xffffffff;
    }
    FUN_00555af0(&local_28,&DAT_00fe1e48 + param_2 * 0x10);
    local_c = 1;
    if (local_28 != local_24) {
      uVar3 = FUN_0089289d();
      FUN_00403040(local_28 + (uVar3 % (uint)((local_24 - local_28) / 0x1c)) * 0x1c,0,0xffffffff);
    }
    FUN_00402a70("UI\\Texture\\Tooltip\\textTooltipTexture.dds",0x29);
    if (*(int *)(param_1 + 0x84) != 0) {
      FUN_005558c0();
      FUN_00555770();
    }
    iVar6 = *(int *)(param_1 + 0x14);
    iVar1 = *(int *)(param_1 + 0x10);
    uVar3 = FUN_0089289d();
    *(uint *)(param_1 + 0xf0) = uVar3 % (uint)((iVar6 - iVar1) / 0x1c);
    if (local_28 == 0) {
      ExceptionList = local_14;
      return 0;
    }
    FUN_00440a80();
    FUN_0089120c(local_28);
    ExceptionList = local_14;
    return 0;
  }
  FUN_00403040(iVar6,0,0xffffffff);
LAB_0055519d:
                    /* WARNING: Could not recover jumptable at 0x005551a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar5 = (*(code *)(&PTR_LAB_0055532c)[param_2])();
  return uVar5;
}

