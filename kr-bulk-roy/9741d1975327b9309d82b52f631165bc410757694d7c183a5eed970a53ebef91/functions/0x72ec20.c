
int FUN_0072ec20(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092038b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x98,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    piVar2 = (int *)(in_ECX + 0x20);
    if (0xf < *(uint *)(in_ECX + 0x34)) {
      piVar2 = (int *)*piVar2;
    }
    iVar1 = FUN_0072e420(iVar1,piVar2);
  }
  local_8 = 0xffffffff;
  if (iVar1 == 0) {
    ExceptionList = local_10;
    return 0;
  }
  FUN_0072eb10(in_ECX);
  ExceptionList = local_10;
  return iVar1;
}

