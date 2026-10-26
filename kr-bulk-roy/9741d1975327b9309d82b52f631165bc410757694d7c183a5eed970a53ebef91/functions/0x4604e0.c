
void FUN_004604e0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  int local_30;
  uint local_2c;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009315ce;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffc0;
  ExceptionList = &local_14;
  iVar4 = *(int *)(in_ECX + 4);
  uVar2 = (*(int *)(iVar4 + 0x108) - *(int *)(iVar4 + 0x104)) / 0x18;
  if (uVar2 != 0) {
    iVar4 = *(int *)(*(int *)(iVar4 + 0xf8) + 0xcc);
    if (iVar4 != 0) {
      FUN_00408920(iVar4,uVar2);
    }
    local_2c = 0;
    if (uVar2 != 0) {
      local_30 = 0;
      do {
        iVar4 = *(int *)(*(int *)(*(int *)(in_ECX + 4) + 0xf8) + 0xcc);
        if (((iVar4 == 0) || ((int)local_2c < 0)) ||
           (*(int *)(iVar4 + 0xac) - *(int *)(iVar4 + 0xa8) >> 2 <= (int)local_2c)) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(*(int *)(iVar4 + 0xa8) + local_2c * 4);
        }
        iVar1 = *(int *)(*(int *)(in_ECX + 4) + 0x104);
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 0;
          FUN_0051c120(uVar3);
          _atexit((_func_4879 *)&LAB_00bccc90);
          local_c = 0xffffffff;
        }
        local_20 = *(undefined4 *)(iVar1 + local_30 + 8);
        FUN_008438c0(&local_20);
        if ((local_1c == DAT_00f8d91c) || (iVar1 = *(int *)(local_1c + 0x10), iVar1 == 0)) {
          if (*(int *)(*(int *)(*(int *)(in_ECX + 4) + 0x104) + 8 + local_30) == 0xf423e) {
            FUN_006064d0();
          }
        }
        else {
          FUN_00757710();
          (**(code **)(**(int **)(iVar4 + 0x248) + 0x1ac))
                    (*(undefined4 *)(iVar1 + 0x20),*(undefined4 *)(iVar1 + 0x1c),0,0,
                     *(undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + 0x104) + 0xc + local_30));
        }
        local_30 = local_30 + 0x18;
        local_2c = local_2c + 1;
      } while (local_2c < uVar2);
    }
    FUN_00749920(*(undefined4 *)(*(int *)(in_ECX + 4) + 0xf8));
    (**(code **)(**(int **)(*(int *)(in_ECX + 4) + 0xf8) + 200))();
    (**(code **)(**(int **)(in_ECX + 4) + 0xd0))();
  }
  ExceptionList = local_14;
  return;
}

