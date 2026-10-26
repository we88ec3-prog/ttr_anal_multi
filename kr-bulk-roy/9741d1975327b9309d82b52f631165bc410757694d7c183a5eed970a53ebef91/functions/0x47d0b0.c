
void FUN_0047d0b0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piVar4;
  int *piVar5;
  undefined4 local_84;
  uint local_70;
  undefined4 local_68;
  uint local_54;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009312b0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xcc);
  if ((iVar2 == 0) || (piVar5 = *(int **)(iVar2 + 0xdc), piVar5 == (int *)0x0)) {
LAB_0047d123:
    piVar5 = (int *)0x0;
  }
  else {
    iVar2 = (**(code **)(*piVar5 + 4))(uVar1);
    if (iVar2 != 0x12d) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0047d123;
    }
  }
  iVar2 = *(int *)(*(int *)(in_ECX + 0xfc) + 0xcc);
  if ((iVar2 != 0) && (piVar4 = *(int **)(iVar2 + 0xdc), piVar4 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar4 + 4))();
    if (iVar2 == 0x12d) goto LAB_0047d165;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar4 = (int *)0x0;
LAB_0047d165:
  if ((piVar5 != (int *)0x0) && (piVar4 != (int *)0x0)) {
    FUN_0047bb50();
    local_8 = 0;
    FUN_0047b450();
    local_8._0_1_ = 1;
    FUN_0047dc10();
    local_8._0_1_ = 2;
    uVar3 = FUN_0047dc50();
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_00757800(uVar3);
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    if (7 < local_70) {
      FUN_0089120c(local_84);
    }
    local_8 = 0xffffffff;
    if (7 < local_54) {
      FUN_0089120c(local_68);
    }
    (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

