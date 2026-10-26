
void FUN_006599f0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 *unaff_EDI;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00946318;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8 = 0;
  switch(param_1) {
  case 1:
  case 6:
    FUN_00425330();
    FUN_004f7a70();
    break;
  default:
    goto switchD_00659a43_caseD_2;
  case 3:
    FUN_00404c10();
    uVar1 = FUN_0051d6d0();
    FUN_004026e0(uVar1,0,0xffffffff);
    goto switchD_00659a43_caseD_2;
  case 4:
    FUN_00425330();
    FUN_004f7a70();
    break;
  case 7:
    FUN_00425330();
    FUN_004f7ba0();
    break;
  case 8:
    FUN_00425330();
    FUN_004f7ba0();
    break;
  case 0xb:
    FUN_0040f930(local_14);
    iVar2 = FUN_00500f90();
    if ((iVar2 != 0) && (FUN_005740f0(&stack0x0000000c), *(int *)(iVar2 + 0x6c) != 0)) {
      FUN_00402110(0x10);
      FUN_004fa440();
      goto LAB_00659aa0;
    }
    goto switchD_00659a43_caseD_2;
  }
  FUN_0041f490(local_30);
switchD_00659a43_caseD_2:
  *(undefined4 *)(unaff_EDI + 10) = 7;
  *(undefined4 *)(unaff_EDI + 8) = 0;
  *unaff_EDI = 0;
  FUN_00402800(local_30);
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
LAB_00659aa0:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

