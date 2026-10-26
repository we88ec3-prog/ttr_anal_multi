
void FUN_0066af30(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int local_3c;
  undefined4 local_38;
  int *local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c756;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = in_ECX;
  FUN_004adcd0(param_1,param_2,local_14);
  iVar2 = FUN_004ef160(param_1,param_2);
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0xd0))();
    iVar2 = in_ECX[0x3f];
    if (*(char *)(iVar2 + 0x141) == '\0') {
      FUN_00757710();
      in_ECX = local_34;
    }
    else {
      FUN_006edb10("Not supported operation");
    }
    *(undefined4 *)(iVar2 + 0x168) = 0;
    *(undefined4 *)(iVar2 + 0x160) = 0;
    *(undefined4 *)(iVar2 + 0x164) = 0;
    *(undefined4 *)(iVar2 + 0x14c) = 0;
    (**(code **)(*(int *)in_ECX[0x3f] + 200))();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_38 = 0x11;
    FUN_005740f0(&local_38);
    if (local_3c == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_004ed610();
    local_8 = 1;
    iVar2 = local_34[0x40];
    if (*(char *)(iVar2 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      FUN_006edb10("Not supported operation");
    }
    *(undefined4 *)(iVar2 + 0x168) = 0;
    *(undefined4 *)(iVar2 + 0x160) = 0;
    *(undefined4 *)(iVar2 + 0x164) = 0;
    *(undefined4 *)(iVar2 + 0x14c) = 0;
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    local_30 = local_30 & 0xffff0000;
    local_1c = 7;
    local_20 = 0;
    (**(code **)(*(int *)local_34[0x40] + 200))();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

