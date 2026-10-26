
void FUN_00501cf0(void)

{
  undefined4 uVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  undefined4 uStack_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00922156;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (((*(int *)(in_ECX + 0x34) != 0) && (*(int *)(in_ECX + 0x34) != 1)) &&
     (*(int *)(in_ECX + 0x44) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 0x24))
              (*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),0,0,1,0,
               (uint)*(byte *)(in_ECX + 0x38) << 0x18 | 0xffffff,
               DAT_00d61f20 ^ (uint)&stack0xffffffc0);
  }
  local_1c = *(int *)(in_ECX + 0x10);
  local_20 = *(undefined4 *)(in_ECX + 4);
  local_24 = local_1c + -0x20;
  local_28 = 0;
  if ((*(int *)(in_ECX + 0x98) != 0) && (*(int *)(in_ECX + 0xb4) != 0)) {
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 0;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_c = 0xffffffff;
    }
    uStack_2c = DAT_00fb7b90;
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 1;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_c = 0xffffffff;
    }
    uVar1 = DAT_00e312c4;
    uStack_34 = DAT_00e312c4;
    FUN_00736180(&uStack_34);
    if ((iStack_30 == DAT_00fb7b80) || (iStack_30 == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
    }
    else {
      DAT_00fb7b90 = uVar1;
    }
    piVar2 = (int *)(in_ECX + 0x88);
    if (7 < *(uint *)(in_ECX + 0x9c)) {
      piVar2 = (int *)*piVar2;
    }
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 2;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_c = 0xffffffff;
    }
    FUN_00735c90(0,piVar2,(uint)*(byte *)(in_ECX + 0x38) << 0x18 |
                          *(uint *)(in_ECX + 0xc0) & 0xffffff,0xff000000);
    local_24 = local_24 + 0x28;
    local_1c = local_1c + 0x28;
    if (*(uint *)(in_ECX + 0xb8) < 8) {
      iVar3 = in_ECX + 0xa4;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0xa4);
    }
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 3;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
      local_c = 0xffffffff;
    }
    FUN_00735c90(0,iVar3,(uint)*(byte *)(in_ECX + 0x38) << 0x18 |
                         *(uint *)(in_ECX + 0xc0) & 0xffffff,0xff000000);
    if ((DAT_00fb7bc8 & 1) == 0) {
      DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
      local_c = 4;
      FUN_00734ef0();
      _atexit((_func_4879 *)&LAB_00bcd4f0);
    }
    uVar1 = uStack_2c;
    FUN_00736180(&uStack_2c);
    if ((iStack_30 == DAT_00fb7b80) || (iStack_30 == -0x10)) {
      DAT_00fb7b90 = DAT_00fb7b8c;
      ExceptionList = local_14;
      return;
    }
    DAT_00fb7b90 = uVar1;
  }
  ExceptionList = local_14;
  return;
}

