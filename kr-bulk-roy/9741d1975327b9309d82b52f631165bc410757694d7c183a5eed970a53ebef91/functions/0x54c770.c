
void FUN_0054c770(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 in_ECX;
  int *unaff_FS_OFFSET;
  undefined1 local_54 [44];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ee06;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  DAT_00fbab38 = param_1;
  DAT_00fbab34 = in_ECX;
  if (param_1 == 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 4;
      FUN_00798de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    iVar3 = DAT_00fb76e8;
    *(undefined4 *)(DAT_00fb76e8 + 0xb0) = 1;
  }
  else {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    puVar2 = (undefined4 *)(**(code **)(**(int **)(DAT_00fb76e8 + 4) + 0x24))(local_54);
    local_28 = *puVar2;
    local_24 = puVar2[1];
    local_20 = puVar2[2];
    local_1c = local_28;
    local_18 = local_24;
    local_14 = local_20;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    iVar3 = DAT_00fb76e8;
    *(undefined4 *)(DAT_00fb76e8 + 0xc) = local_28;
    *(undefined4 *)(iVar3 + 0x10) = local_24;
    *(undefined4 *)(iVar3 + 0x14) = local_20;
    *(undefined4 *)(iVar3 + 0xcc) = 0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    iVar3 = DAT_00fb76e8;
    *(undefined4 *)(DAT_00fb76e8 + 0x24) = 0;
    *(undefined4 *)(iVar3 + 0xcc) = 0;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 3;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    iVar3 = DAT_00fb76e8;
    *(undefined4 *)(DAT_00fb76e8 + 0xb0) = 0;
  }
  *(undefined4 *)(iVar3 + 0xd8) = *(undefined4 *)(iVar3 + 0xd4);
  *unaff_FS_OFFSET = local_10;
  return;
}

