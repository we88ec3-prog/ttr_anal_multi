
void FUN_00403b90(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  undefined4 uVar3;
  undefined4 uVar4;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094001e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  local_14 = *(undefined4 *)(unaff_EDI + 0x24c);
  FUN_008438c0(&local_14);
  if (((local_18 != DAT_00f8d91c) && (*(int *)(local_18 + 0x10) != 0)) &&
     (iVar2 = *(int *)(*(int *)(local_18 + 0x10) + 0x54), iVar2 != 0)) {
    if (*(int *)(iVar2 + 4) != 0) {
      FUN_00404ba0();
      iVar1 = FUN_004d42c0();
      if (iVar1 == 0) {
        uVar4 = 0x196;
        FUN_005854b0(0x196,0,0);
        uVar4 = FUN_00585330(uVar4);
        uVar3 = 0x1c1;
        FUN_005854b0(0x1c1,uVar4);
        uVar4 = FUN_00585330(uVar3);
        FUN_00404b10(0xca,uVar4);
        ExceptionList = local_10;
        return;
      }
    }
    switch(*(undefined4 *)(iVar2 + 8)) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x1b:
    case 0x20:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      iVar2 = FUN_00891268(0x24);
      if (iVar2 != 0) {
        FUN_00753e70(0xf4422,*(undefined4 *)(unaff_EDI + 0x248),0,0);
      }
      break;
    default:
      goto switchD_00403c95_caseD_5;
    case 0x1d:
      iVar2 = FUN_00891268(0x20);
      if (iVar2 != 0) {
        FUN_00753d00(1,1);
      }
    }
    FUN_00404aa0();
    FUN_00750020();
  }
switchD_00403c95_caseD_5:
  ExceptionList = local_10;
  return;
}

