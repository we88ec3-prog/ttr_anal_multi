
void FUN_00687300(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009485fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = *(undefined4 *)(in_ECX[0x4b] + 0x254);
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  local_14 = uVar1;
  FUN_008438c0(&local_14);
  if (local_18 == DAT_00f8d91c) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(local_18 + 0x10);
  }
  if ((*(int *)(iVar2 + 0x40) == 0) && ((char)in_ECX[0x5c] == '\0')) {
    FUN_00688bf0(in_ECX[0x3d]);
  }
  else {
    FUN_00687930();
    *(undefined1 *)(in_ECX + 0x5c) = 0;
  }
  (**(code **)(*in_ECX + 0x16c))(1);
  ExceptionList = local_10;
  return;
}

