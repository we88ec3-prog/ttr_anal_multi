
void FUN_007b3a30(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009320ac;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = in_ECX;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  iVar3 = FUN_00799ba0(&DAT_00fb76a8);
  *(int *)(in_ECX + 4) = iVar3;
  if (iVar3 != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    piVar1 = DAT_00fb76a8;
    (**(code **)(*DAT_00fb76a8 + 0x7c))(&local_14,"Material/Char_Skin.obj");
    uVar4 = (**(code **)(*piVar1 + 200))(local_14);
    *(undefined4 *)(in_ECX + 8) = uVar4;
  }
  ExceptionList = local_10;
  return;
}

