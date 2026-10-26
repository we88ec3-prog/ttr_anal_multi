
void FUN_004d1f90(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
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
    iVar2 = *(int *)(in_ECX + 0x368);
    if (DAT_00f93930 == *(int *)(in_ECX + 0x9c)) {
      if (iVar2 != 0) {
        iVar2 = FUN_007b4ed0(iVar2);
        *(undefined4 *)(iVar2 + 4) = 4;
      }
      goto LAB_004d20e3;
    }
  }
  else {
    if (iVar2 != 0x11) {
      if (iVar2 == 0x12) {
        if (*(int *)(in_ECX + 0x424) == 3) {
          FUN_004c8450(6);
        }
        else if (*(int *)(in_ECX + 0x424) == 4) {
          iVar2 = *(int *)(in_ECX + 0x368);
          if (iVar2 != 0) {
            *(undefined4 *)(iVar2 + 0x1c) = 0x42c80000;
            *(undefined4 *)(iVar2 + 0x20) = 0x41200000;
          }
          FUN_004c8450(0);
        }
        else {
          FUN_004c8450(5);
        }
      }
      else if (*(int *)(in_ECX + 0x368) != 0) {
        iVar2 = FUN_007b4ed0(*(int *)(in_ECX + 0x368));
        *(undefined4 *)(iVar2 + 4) = 7;
      }
      goto LAB_004d20e3;
    }
    iVar2 = *(int *)(in_ECX + 0x368);
  }
  if (iVar2 != 0) {
    iVar2 = FUN_007b4ed0(iVar2);
    *(undefined4 *)(iVar2 + 4) = 2;
  }
LAB_004d20e3:
  if (*(int *)(in_ECX + 0x368) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x368) + 0x28) = 0;
  }
  ExceptionList = local_14;
  return;
}

