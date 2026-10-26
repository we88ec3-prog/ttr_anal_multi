
undefined4 FUN_0055d5e0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938cde;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = *(int *)(param_1 + 8);
  if (*(int *)(iVar2 + -8) != 4) {
    iVar2 = FUN_006fb5d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if (iVar2 == 0) {
      ExceptionList = local_10;
      return 0;
    }
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar2 = *(int *)(param_1 + 8);
  }
  iVar2 = *(int *)(iVar2 + -0x10);
  pcVar4 = (char *)(iVar2 + 0x10);
  if (pcVar4 != (char *)0x0) {
    if ((DAT_00fe1ee8 & 1) == 0) {
      DAT_00fe1ee8 = DAT_00fe1ee8 | 1;
      local_8 = 0;
      FUN_0055c610();
      _atexit((_func_4879 *)&LAB_00bcf290);
      local_8 = 0xffffffff;
    }
    pcVar3 = pcVar4;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar4,(int)pcVar3 - (iVar2 + 0x11));
  }
  ExceptionList = local_10;
  return 0;
}

