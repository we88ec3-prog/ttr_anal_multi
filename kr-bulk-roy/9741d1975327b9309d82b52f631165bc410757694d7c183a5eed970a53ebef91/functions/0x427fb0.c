
void FUN_00427fb0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094574e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  iVar2 = DAT_00fb7258;
  local_8 = 0xffffffff;
  if (DAT_00fb7258 != 0) {
    local_14 = (int *)(param_1 + 0x124);
    local_18 = 0;
    do {
      iVar6 = 0;
      iVar3 = *(int *)(iVar2 + 0x2c) - *(int *)(iVar2 + 0x28) >> 2;
      if (iVar3 != 0) {
        piVar4 = *(int **)(iVar2 + 0x28);
        do {
          if (*(char *)(*piVar4 + 0xb) == (char)((char)local_18 + '\x01')) {
            iVar6 = iVar6 + 1;
          }
          piVar4 = piVar4 + 1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      iVar3 = *local_14;
      *(int *)(iVar3 + 0xf0) = iVar6;
      *(undefined4 *)(iVar3 + 0xf4) = 0;
      iVar3 = *(int *)(*(int *)(iVar3 + 0xec) + 0xcc);
      if (iVar3 != 0) {
        FUN_00408920(iVar3,iVar6);
      }
      local_14 = local_14 + 1;
      local_18 = local_18 + 1;
    } while (local_18 < 3);
    uVar7 = 0;
    uVar5 = *(int *)(iVar2 + 0x2c) - *(int *)(iVar2 + 0x28) >> 2;
    if (uVar5 != 0) {
      do {
        if (((uVar7 < (uint)(*(int *)(iVar2 + 0x2c) - *(int *)(iVar2 + 0x28) >> 2)) &&
            (puVar1 = *(undefined4 **)(*(int *)(iVar2 + 0x28) + uVar7 * 4),
            *(char *)((int)puVar1 + 10) != '\0')) && (puVar1 != (undefined4 *)0x0)) {
          FUN_00428320(*puVar1,*(undefined1 *)(puVar1 + 2));
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar5);
    }
  }
  ExceptionList = local_10;
  return;
}

