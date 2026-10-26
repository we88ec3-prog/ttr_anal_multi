
void FUN_008fd880(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00921aa7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar3 = FUN_00891268(0x38,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar3 != 0) {
    FUN_008fd800();
  }
  local_8 = 0xffffffff;
  param_1 = 0;
  uVar5 = 0;
  iVar3 = FUN_00572120();
  uVar2 = param_1;
  if (iVar3 != 0) {
    do {
      FUN_00572140();
      iVar3 = FUN_008fd0c0();
      if (*(int *)(iVar1 + 0x68) == iVar3) {
        FUN_00572140();
        iVar3 = FUN_008fd0a0();
        uVar2 = uVar5;
        if (*(int *)(iVar1 + 0x6c) == iVar3) break;
      }
      uVar5 = uVar5 + 1;
      uVar4 = FUN_00572120();
      uVar2 = param_1;
    } while (uVar5 < uVar4);
  }
  param_1 = uVar2;
  if (param_1 != *(uint *)(iVar1 + 100)) {
    FUN_00572140();
    FUN_008fd0b0();
    FUN_008fd7c0();
    FUN_00572140();
    FUN_00572140();
    FUN_008fd0b0();
    FUN_008fd7c0();
    FUN_00572140();
    FUN_008fd0b0();
    FUN_008fd7c0();
  }
  ExceptionList = local_10;
  return;
}

