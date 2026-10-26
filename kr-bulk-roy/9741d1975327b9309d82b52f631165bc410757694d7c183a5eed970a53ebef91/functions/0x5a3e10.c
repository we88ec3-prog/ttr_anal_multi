
void FUN_005a3e10(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093324e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8 = 0;
    FUN_004d4d10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccef0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb11e8 == 1) {
    iVar1 = *(int *)(in_ECX + 0x140);
    iVar2 = *(int *)(iVar1 + 0x110);
    if ((*(int *)(iVar2 + 0xcc) != 0) && (*(int *)(iVar2 + 0xd8) != 0)) {
      iVar2 = FUN_005f55a0();
      if (iVar2 != -1) {
        FUN_00645300(iVar1,iVar2);
      }
    }
  }
  else if (((DAT_00fb11e8 == 2) && (iVar1 = *(int *)(*(int *)(in_ECX + 0x148) + 0xec), iVar1 != 0))
          && (*(char *)(iVar1 + 0xb0) == '\0')) {
    FUN_006481d0();
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}

