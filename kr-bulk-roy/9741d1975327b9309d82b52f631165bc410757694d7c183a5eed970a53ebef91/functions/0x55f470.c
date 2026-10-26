
void FUN_0055f470(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009294be;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar1 = *(undefined4 **)(param_1 + 0x24);
  if (puVar1 != (undefined4 *)0x0) {
    if (0xf < (uint)puVar1[0xc]) {
      FUN_0089120c(puVar1[7],uVar2);
    }
    puVar1[0xc] = 0xf;
    puVar1[0xb] = 0;
    *(undefined1 *)(puVar1 + 7) = 0;
    if (7 < (uint)puVar1[5]) {
      FUN_0089120c(*puVar1,uVar2);
    }
    puVar1[5] = 7;
    puVar1[4] = 0;
    *(undefined2 *)puVar1 = 0;
    FUN_0089120c(puVar1,uVar2);
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    piVar3 = (int *)FUN_00542210();
    if ((int *)*piVar3 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)*piVar3;
    }
    uVar2 = (uint)piVar3[2] >> 2;
    if (*(uint *)(iVar4 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(iVar4 + 8);
    }
    *(undefined4 *)(param_1 + 0x24) =
         *(undefined4 *)(*(int *)(*(int *)(iVar4 + 4) + uVar2 * 4) + (piVar3[2] & 3U) * 4);
    if (*(int *)(param_1 + 0x1c) != 0) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      if ((uint)(*(int *)(param_1 + 0x14) * 4) <= *(uint *)(param_1 + 0x18)) {
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
      iVar4 = *(int *)(param_1 + 0x1c) + -1;
      *(int *)(param_1 + 0x1c) = iVar4;
      if (iVar4 == 0) {
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
    }
    if ((DAT_00fb72a4 & 1) == 0) {
      DAT_00fb72a4 = DAT_00fb72a4 | 1;
      local_8 = 0;
      FUN_0049f850();
      _atexit((_func_4879 *)&LAB_00bccfe0);
      local_8 = 0xffffffff;
    }
    FUN_004a03f0(&DAT_00fb72a8,*(undefined4 *)(param_1 + 0x38));
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(param_1 + 0x28) = 1;
  ExceptionList = local_10;
  return;
}

