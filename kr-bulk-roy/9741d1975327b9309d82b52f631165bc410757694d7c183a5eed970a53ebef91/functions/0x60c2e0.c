
void FUN_0060c2e0(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f76e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = DAT_00fc1094 & 1;
  *(undefined4 *)(unaff_EDI + 0x288) = 3;
  if (uVar1 == 0) {
    DAT_00fc1094 = DAT_00fc1094 | 1;
    local_8 = 0;
    FUN_0052f7e0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcdc80);
  }
  uVar3 = FUN_005302d0();
  switch(uVar3) {
  case 1:
  case 2:
  case 3:
  case 4:
  case 8:
  case 9:
  case 10:
    iVar4 = FUN_00530330();
    if (iVar4 == 1) {
      *(undefined4 *)(unaff_EDI + 0x288) = 0;
    }
    else {
      if (iVar4 == 2) {
        *(undefined4 *)(unaff_EDI + 0x288) = 1;
        ExceptionList = local_10;
        return;
      }
      if (iVar4 == 3) {
        *(undefined4 *)(unaff_EDI + 0x288) = 2;
        ExceptionList = local_10;
        return;
      }
    }
  }
  ExceptionList = local_10;
  return;
}

