
undefined4 FUN_0041d460(int param_1,undefined2 param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *unaff_ESI;
  int iVar6;
  int local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910f5e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11a8 & 1) == 0) {
    DAT_00fb11a8 = DAT_00fb11a8 | 1;
    local_8 = 0;
    FUN_00813890(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccec0);
  }
  local_8 = 0xffffffff;
  local_14 = param_1;
  FUN_0082ef00(&local_14);
  if ((local_18 != DAT_00fb11b0) && (local_14 = *(int *)(local_18 + 0x10), local_14 != 0)) {
    piVar1 = (int *)unaff_ESI[1];
    piVar2 = (int *)*unaff_ESI;
    uVar4 = 0;
    piVar5 = piVar2;
    if ((int)piVar1 - (int)piVar2 >> 3 != 0) {
      do {
        if (*piVar5 == param_1) {
          *(undefined2 *)(piVar2 + uVar4 * 2 + 1) = param_2;
          unaff_ESI[4] = unaff_ESI[4] | *(uint *)(local_14 + 4);
          ExceptionList = local_10;
          return 1;
        }
        uVar4 = uVar4 + 1;
        piVar5 = piVar5 + 2;
      } while (uVar4 < (uint)((int)piVar1 - (int)piVar2 >> 3));
    }
    local_1c = param_1;
    local_18 = CONCAT22(local_18._2_2_,param_2);
    if ((&local_1c < piVar1) && (piVar2 <= &local_1c)) {
      iVar6 = (int)&local_1c - (int)piVar2 >> 3;
      if (piVar1 == (int *)unaff_ESI[2]) {
        FUN_00539180();
      }
      puVar3 = (undefined4 *)unaff_ESI[1];
      if (puVar3 != (undefined4 *)0x0) {
        uVar4 = *unaff_ESI;
        *puVar3 = *(undefined4 *)(uVar4 + iVar6 * 8);
        puVar3[1] = *(undefined4 *)(uVar4 + 4 + iVar6 * 8);
      }
    }
    else {
      if (piVar1 == (int *)unaff_ESI[2]) {
        FUN_00539180();
      }
      piVar1 = (int *)unaff_ESI[1];
      if (piVar1 != (int *)0x0) {
        *piVar1 = param_1;
        piVar1[1] = local_18;
      }
    }
    unaff_ESI[1] = unaff_ESI[1] + 8;
    unaff_ESI[4] = unaff_ESI[4] | *(uint *)(local_14 + 4);
    ExceptionList = local_10;
    return 1;
  }
  ExceptionList = local_10;
  return 0;
}

