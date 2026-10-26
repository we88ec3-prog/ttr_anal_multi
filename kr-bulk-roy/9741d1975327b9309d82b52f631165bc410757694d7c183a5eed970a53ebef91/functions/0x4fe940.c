
undefined4 FUN_004fe940(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  puStack_c = &LAB_009243ea;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = (uint)*(byte *)(param_1 + 3) * 0x40;
  if (*(char *)(param_1 + 2) == '\0') {
    *(undefined4 *)(iVar3 + 0x5eb0 + in_ECX) = 1;
    *(undefined4 *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x5ecc + in_ECX) =
         *(undefined4 *)(param_1 + 0xe);
    iVar3 = (*(byte *)(param_1 + 3) + 0x17b) * 0x40;
    *(undefined4 *)(iVar3 + in_ECX) = *(undefined4 *)(param_1 + 6);
    *(undefined4 *)(iVar3 + 4 + in_ECX) = *(undefined4 *)(param_1 + 10);
    *(uint *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x5ec8 + in_ECX) =
         (uint)*(byte *)(param_1 + 0x12);
    *(undefined4 *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x5ecc + in_ECX) =
         *(undefined4 *)(param_1 + 0xe);
    *(uint *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x5eb4 + in_ECX) = (uint)*(byte *)(param_1 + 4);
    *(uint *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x5eb8 + in_ECX) = (uint)*(byte *)(param_1 + 5);
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 0;
      FUN_0051c120(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    param_1 = *(undefined4 *)(iVar1 + 0xe);
    FUN_008438c0(&param_1);
    if ((local_14 == DAT_00f8d91c) || (iVar1 = *(int *)(local_14 + 0x10), iVar1 == 0)) {
LAB_004fea52:
      FUN_006edb60(&DAT_00c0da24);
      ExceptionList = local_10;
      return 0;
    }
    param_1 = *(undefined4 *)(iVar1 + 0x20);
    iVar3 = FUN_004034e0();
    FUN_008438c0(&param_1);
    if ((local_18 != *(int *)(iVar3 + 4)) && (*(int *)(local_18 + 0x10) != 0)) {
      FUN_004026e0(iVar1,0,0xffffffff);
      goto LAB_004febde;
    }
  }
  else {
    *(undefined4 *)(iVar3 + 0x6070 + in_ECX) = 1;
    *(undefined4 *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x608c + in_ECX) =
         *(undefined4 *)(param_1 + 0xe);
    iVar3 = (*(byte *)(param_1 + 3) + 0x182) * 0x40;
    *(undefined4 *)(iVar3 + in_ECX) = *(undefined4 *)(param_1 + 6);
    *(undefined4 *)(iVar3 + 4 + in_ECX) = *(undefined4 *)(param_1 + 10);
    *(uint *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x6088 + in_ECX) =
         (uint)*(byte *)(param_1 + 0x12);
    *(undefined4 *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x608c + in_ECX) =
         *(undefined4 *)(param_1 + 0xe);
    *(uint *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x6074 + in_ECX) = (uint)*(byte *)(param_1 + 4);
    *(uint *)((uint)*(byte *)(param_1 + 3) * 0x40 + 0x6078 + in_ECX) = (uint)*(byte *)(param_1 + 5);
    if ((DAT_00f8d9a4 & 1) == 0) {
      DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
      local_8 = 1;
      FUN_0051c120(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc90);
    }
    local_8 = 0xffffffff;
    param_1 = *(undefined4 *)(iVar1 + 0xe);
    FUN_008438c0(&param_1);
    if ((local_18 == DAT_00f8d91c) || (iVar1 = *(int *)(local_18 + 0x10), iVar1 == 0))
    goto LAB_004fea52;
    param_1 = *(undefined4 *)(iVar1 + 0x20);
    iVar3 = FUN_004034e0();
    FUN_008438c0(&param_1);
    if ((local_14 != *(int *)(iVar3 + 4)) && (*(int *)(local_14 + 0x10) != 0)) {
      FUN_004026e0(iVar1,0,0xffffffff);
      goto LAB_004febde;
    }
  }
  FUN_006edb60(&DAT_00c0da24);
LAB_004febde:
  uVar2 = DAT_00faadd4 & 1;
  *(undefined4 *)(in_ECX + 0x623c) = 0;
  if (uVar2 == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 2;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0(0xf4264);
  ExceptionList = local_10;
  return 0;
}

