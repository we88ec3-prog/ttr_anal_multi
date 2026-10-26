
void FUN_0068cf00(void)

{
  code *pcVar1;
  uint uVar2;
  int *in_ECX;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092cfce;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[0x3d] + 0x144) = 0x10;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_8 = 0xffffffff;
  local_14 = 0x32a;
  FUN_005740f0(&local_14);
  if (local_18 != DAT_00fe5ac8) {
    FUN_00757710(uVar2);
    (**(code **)(*in_ECX + 200))();
    ExceptionList = local_10;
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

