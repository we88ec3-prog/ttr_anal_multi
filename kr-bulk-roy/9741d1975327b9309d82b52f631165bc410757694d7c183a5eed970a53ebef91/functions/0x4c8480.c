
void FUN_004c8480(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  iVar2 = FUN_004c9580(in_ECX);
  if (iVar2 == 0x10) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    iVar3 = *(int *)(in_ECX + 0x368);
    if (DAT_00f93930 == *(int *)(in_ECX + 0x9c)) {
      if (iVar3 != 0) {
        iVar2 = FUN_007b4ed0(iVar3);
        *(undefined4 *)(iVar2 + 4) = 2;
      }
      goto LAB_004c8554;
    }
  }
  else {
    iVar3 = *(int *)(in_ECX + 0x368);
    if (iVar2 != 0x11) {
      if (iVar3 != 0) {
        iVar2 = FUN_007b4ed0(iVar3);
        *(undefined4 *)(iVar2 + 4) = 0;
      }
      goto LAB_004c8554;
    }
  }
  if (iVar3 != 0) {
    iVar2 = FUN_007b4ed0(iVar3);
    *(undefined4 *)(iVar2 + 4) = 4;
  }
LAB_004c8554:
  if (*(int *)(in_ECX + 0x368) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x368) + 0x28) = 0;
  }
  ExceptionList = local_14;
  return;
}

