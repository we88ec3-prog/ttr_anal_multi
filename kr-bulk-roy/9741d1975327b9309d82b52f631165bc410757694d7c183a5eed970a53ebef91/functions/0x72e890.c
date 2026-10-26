
void FUN_0072e890(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ccab;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_00730050(in_ECX + 0x11,param_1);
  if (iVar2 != 0) {
    FUN_00403040(param_2,0,0xffffffff);
    ExceptionList = local_10;
    return;
  }
  iVar2 = FUN_00891268(0x54,uVar1);
  local_8 = 0;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0072d9f0(iVar2,param_1,param_2);
  }
  local_8 = 0xffffffff;
  if (iVar2 != 0) {
    *(int **)(iVar2 + 0x50) = in_ECX + 0x11;
    *(int *)(iVar2 + 0x4c) = in_ECX[0x24];
    *(int *)(in_ECX[0x24] + 0x50) = iVar2;
    in_ECX[0x24] = iVar2;
    ExceptionList = local_10;
    return;
  }
  if (in_ECX != (int *)0x0) {
    while( true ) {
      iVar2 = (**(code **)(*in_ECX + 0x10))();
      if (iVar2 != 0) break;
      in_ECX = (int *)in_ECX[4];
      if (in_ECX == (int *)0x0) {
        ExceptionList = local_10;
        return;
      }
    }
    iVar2 = (**(code **)(*in_ECX + 0x10))();
    if (iVar2 != 0) {
      FUN_00732010(3,0,0,0);
    }
  }
  ExceptionList = local_10;
  return;
}

