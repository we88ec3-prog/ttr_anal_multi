
void FUN_00612940(undefined4 param_1,byte param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *unaff_EDI;
  undefined4 uVar5;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091d526;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  unaff_EDI[4] = 0;
  puVar4 = unaff_EDI;
  if (7 < (uint)unaff_EDI[5]) {
    puVar4 = (undefined4 *)*unaff_EDI;
  }
  uVar3 = DAT_00fb11a8 & 1;
  *(undefined2 *)puVar4 = 0;
  if (uVar3 == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(local_14);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_8 = 0xffffffff;
  local_54 = param_1;
  FUN_0082ef00(&local_54);
  if ((((local_50 != DAT_00fb11b0) && (iVar1 = *(int *)(local_50 + 0x10), iVar1 != 0)) &&
      ((uint)param_2 < (uint)(*(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2))) &&
     ((piVar2 = *(int **)(*(int *)(iVar1 + 0x14) + (uint)param_2 * 4), piVar2 != (int *)0x0 &&
      (piVar2 = (int *)*piVar2, piVar2 != (int *)0x0)))) {
    local_50 = *piVar2;
    if (local_50 != 0) {
      uVar5 = 0x2d5;
      FUN_00585620(0x2d5);
      FUN_00585330(uVar5);
      uVar5 = FUN_004068f0();
      local_8 = 1;
      FUN_004041f0(uVar5,0,0xffffffff);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
    }
    if (piVar2[1] != 0) {
      if (unaff_EDI[4] != 0) {
        FUN_00404420(unaff_EDI);
      }
      local_50 = piVar2[1];
      uVar5 = 0x2d6;
      FUN_00585620(0x2d6);
      FUN_00585330(uVar5);
      uVar5 = FUN_004068f0();
      local_8 = 2;
      FUN_004041f0(uVar5,0,0xffffffff);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
    }
    if (piVar2[2] != 0) {
      if (unaff_EDI[4] != 0) {
        FUN_00404420(unaff_EDI);
      }
      uVar5 = 0x2d7;
      FUN_00585620(0x2d7);
      FUN_00585330(uVar5);
      uVar5 = FUN_004068f0();
      local_8 = 3;
      FUN_004041f0(uVar5,0,0xffffffff);
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

