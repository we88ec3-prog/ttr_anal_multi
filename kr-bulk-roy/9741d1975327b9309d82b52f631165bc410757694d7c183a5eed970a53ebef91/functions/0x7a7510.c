
undefined4 FUN_007a7510(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  puStack_c = &LAB_00918d9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1bc0 & 1) == 0) {
    DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
    local_8 = 0;
    FUN_007bef00(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcec50);
  }
  uVar3 = param_2;
  local_8 = 0xffffffff;
  local_20 = param_2;
  local_1c = param_3;
  FUN_004dd400(&DAT_00fe1b60,&param_1,&local_20);
  if ((param_1 != DAT_00fe1b64) && (*(int *)(param_1 + 0x18) != 0)) {
    iVar4 = *(int *)(*(int *)(param_1 + 0x18) + 0x20);
    if ((char)((uint)uVar3 >> 0x18) == '\x01') {
      iVar4 = iVar4 + 0x10;
    }
    param_1 = iVar4;
    piVar2 = (int *)FUN_007a0c00(&param_1);
    if (*(int *)(iVar1 + 0x60) != *piVar2) {
      FUN_007a7620(iVar1,iVar4);
    }
    local_20 = param_2;
    local_1c = param_3;
    uVar3 = FUN_007a25f0();
    FUN_007a2810(iVar1 + 0x5c,uVar3);
    *(undefined1 *)(iVar1 + 0x28) = 1;
    ExceptionList = local_10;
    return 1;
  }
  ExceptionList = local_10;
  return 0;
}

