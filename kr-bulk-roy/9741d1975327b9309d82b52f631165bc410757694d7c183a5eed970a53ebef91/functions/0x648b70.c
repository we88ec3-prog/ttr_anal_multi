
void FUN_00648b70(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  uint local_30;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00926b26;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_c = 0;
    FUN_004a79a0(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_c = 0xffffffff;
  FUN_00450340();
  local_c = 1;
  uVar2 = local_24 - local_28 >> 2;
  local_30 = 0;
  if (uVar2 != 0) {
    do {
      iVar1 = local_30 * 4;
      FUN_006c09c0(*(undefined4 *)(*(int *)(iVar1 + local_28) + 4));
      FUN_0043c570(*(int *)(*(int *)(iVar1 + local_28) + 4) + 10);
      *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xe0) + iVar1) + 0x24c) =
           **(undefined4 **)(iVar1 + local_28);
      (**(code **)(**(int **)(iVar1 + *(int *)(in_ECX + 0xe0)) + 0x94))
                (*(undefined1 *)(*(int *)(iVar1 + local_28) + 8));
      (**(code **)(**(int **)(iVar1 + *(int *)(in_ECX + 0xe0)) + 200))();
      (**(code **)(**(int **)(iVar1 + *(int *)(in_ECX + 0xf0)) + 0x94))
                (*(undefined1 *)(*(int *)(iVar1 + local_28) + 8));
      (**(code **)(**(int **)(iVar1 + *(int *)(in_ECX + 0xf0)) + 200))();
      local_30 = local_30 + 1;
    } while (local_30 < uVar2);
  }
  FUN_00649570();
  if (local_28 != 0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}

