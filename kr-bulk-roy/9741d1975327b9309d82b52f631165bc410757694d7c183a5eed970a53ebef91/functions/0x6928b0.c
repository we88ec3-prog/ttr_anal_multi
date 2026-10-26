
void FUN_006928b0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00945b7c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  iVar2 = DAT_00fb7258;
  local_c = 0xffffffff;
  iVar4 = 0;
  if (DAT_00fb7258 != 0) {
    uVar3 = *(int *)(DAT_00fb7258 + 0x2c) - *(int *)(DAT_00fb7258 + 0x28) >> 2;
    local_24 = 0;
    if (uVar3 != 0) {
      puVar5 = (undefined4 *)(in_ECX + 0x8c);
      do {
        if (2 < iVar4) {
          ExceptionList = local_14;
          return;
        }
        if (((local_24 < (uint)(*(int *)(iVar2 + 0x2c) - *(int *)(iVar2 + 0x28) >> 2)) &&
            (piVar1 = *(int **)(*(int *)(iVar2 + 0x28) + local_24 * 4),
            *(char *)((int)piVar1 + 10) != '\0')) && (piVar1 != (int *)0x0)) {
          if ((DAT_00f94390 & 1) == 0) {
            DAT_00f94390 = DAT_00f94390 | 1;
            local_c = 1;
            FUN_004e1590();
            _atexit((_func_4879 *)&LAB_00bccc80);
            local_c = 0xffffffff;
          }
          if (*piVar1 != DAT_00f93930) {
            FUN_00693fa0();
            (**(code **)(*(int *)*puVar5 + 0x94))(1);
            iVar4 = iVar4 + 1;
            puVar5 = puVar5 + 1;
          }
        }
        local_24 = local_24 + 1;
      } while (local_24 < uVar3);
    }
  }
  if (iVar4 < 3) {
    puVar5 = (undefined4 *)(in_ECX + 0x8c + iVar4 * 4);
    iVar4 = 3 - iVar4;
    do {
      (**(code **)(*(int *)*puVar5 + 0x94))(0);
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  ExceptionList = local_14;
  return;
}

