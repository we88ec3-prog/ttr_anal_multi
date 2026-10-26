
void FUN_007ba6b0(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009350ca;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x3c) != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 1;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
      }
    }
    iVar1 = DAT_00fb76a8;
    local_8 = 0xffffffff;
    if (*(int *)(DAT_00fb76a8 + 0xec) != 0) {
      (**(code **)(**(int **)(DAT_00fb76a8 + 0xec) + 4))(*(int **)(DAT_00fb76a8 + 0xec));
      local_20 = *(int **)(iVar1 + 0xec);
    }
    FUN_007e0dd0(*(undefined4 *)(in_ECX + 0x54));
    if (*(int *)(in_ECX + 0x40) != 0) {
      (**(code **)(*(int *)(*(int *)(in_ECX + 0x40) + 4) + 8))();
    }
    if ((DAT_00fe3284 & 1) == 0) {
      DAT_00fe3284 = DAT_00fe3284 | 1;
      local_8 = 2;
      FUN_007df1e0();
      _atexit((_func_4879 *)&LAB_00bd0ad0);
      local_8 = 0xffffffff;
    }
    (**(code **)(DAT_00fe3288 + 8))();
    uVar2 = 0;
    uVar5 = *(int *)(in_ECX + 0xa8) - *(int *)(in_ECX + 0xa4) >> 2;
    if (uVar5 != 0) {
      do {
        FUN_007e8240(*(undefined4 *)(DAT_00fba838 + 0x8c),
                     *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0xa4) + uVar2 * 4) + 0x34));
        uVar2 = uVar2 + 1;
      } while (uVar2 < uVar5);
    }
    if (*(int *)(in_ECX + 0x8c) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x8c) + 8))();
    }
    uVar2 = *(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c) >> 2;
    local_14 = 0;
    if (uVar2 != 0) {
      do {
        iVar1 = *(int *)(*(int *)(in_ECX + 0x7c) + local_14 * 4);
        if (((*(int *)(iVar1 + 0x20) != 0) && (*(int *)(iVar1 + 0x78) == 0)) &&
           (iVar3 = (*(int *)(iVar1 + 0x5c) - *(int *)(iVar1 + 0x58)) / 0x2c, iVar3 != 0)) {
          iVar4 = 0;
          do {
            (**(code **)(**(int **)(iVar4 + 0x28 + *(int *)(iVar1 + 0x58)) + 8))();
            iVar4 = iVar4 + 0x2c;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        local_14 = local_14 + 1;
      } while (local_14 < uVar2);
    }
    FUN_007bb240();
    (**(code **)(*local_20 + 8))(local_20);
  }
  ExceptionList = local_10;
  return;
}

