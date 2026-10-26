
void FUN_0041eb80(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piStack_7c;
  int *piStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  undefined **local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00931eb4;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&piStack_7c;
  ExceptionList = &local_14;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_68 = FUI::CFXUIBinder::vftable;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_c = 1;
  FUN_0041ef40(DAT_00d61f20 ^ (uint)&stack0xffffff78);
  FUN_005a9f40(in_ECX + 0x100);
  FUN_0041f020();
  FUN_005a9f40(in_ECX + 0x104);
  FUN_0040b670(in_ECX);
  FUN_0041f460(&DAT_00bf4860);
  local_c._0_1_ = 2;
  FUN_00405300(*(int *)(in_ECX + 0x100) + 0xa0);
  local_c._0_1_ = 1;
  FUN_00757640(local_54);
  FUN_0041f460(&DAT_00bf4868);
  local_c._0_1_ = 3;
  FUN_00405300(*(int *)(in_ECX + 0x104) + 0xa0);
  local_c = CONCAT31(local_c._1_3_,1);
  FUN_00757640(local_54);
  iVar2 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xd8);
  if (iVar2 != 0) {
    FUN_0040acb0(iVar2,0,*(undefined4 *)(in_ECX + 0x100));
  }
  iVar2 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xd8);
  if (iVar2 != 0) {
    FUN_0040acb0(iVar2,1,*(undefined4 *)(in_ECX + 0x104));
  }
  FUN_00749920(*(undefined4 *)(in_ECX + 0xf4));
  (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  FUN_0040b5b0(0);
  piStack_78 = (int *)0x0;
  iStack_70 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8)) / 2;
  iStack_74 = 0;
  piVar4 = (int *)(in_ECX + 0xf8);
  do {
    iVar2 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xd8);
    if (iVar2 == 0) {
LAB_0041ed54:
      iVar2 = 0;
    }
    else {
      piStack_7c = piStack_78;
      FUN_0082ef00(&piStack_7c);
      if (iStack_6c == *(int *)(iVar2 + 0xac)) goto LAB_0041ed54;
      iVar2 = *(int *)(iStack_6c + 0x10);
    }
    *piVar4 = iVar2;
    FUN_00749c50();
    iVar2 = *piVar4;
    iVar1 = iStack_74 - *(int *)(iVar2 + 8);
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + iVar1;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + iVar1;
    iVar1 = *(int *)(iVar2 + 0xc);
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + -iVar1;
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + -iVar1;
    *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar2 + 0xc);
    *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar2 + 0x10);
    *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar2 + 0x14);
    if (*(int *)(iVar2 + 0x60) != 0) {
      iVar1 = *(int *)(*(int *)(iVar2 + 0x60) + 0x2c);
      *(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + iVar1;
      *(int *)(iVar2 + 0x34) = *(int *)(iVar2 + 0x34) + iVar1;
      iVar1 = *(int *)(*(int *)(iVar2 + 0x60) + 0x30);
      *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) + iVar1;
      *(int *)(iVar2 + 0x38) = *(int *)(iVar2 + 0x38) + iVar1;
    }
    piStack_7c = *(int **)(iVar2 + 100);
    piVar3 = (int *)*piStack_7c;
    if (piVar3 != piStack_7c) {
      do {
        FUN_00746f70();
        piVar3 = (int *)*piVar3;
      } while (piVar3 != piStack_7c);
    }
    iStack_74 = iStack_74 + iStack_70;
    piStack_78 = (int *)((int)piStack_78 + 1);
    piVar4 = piVar4 + 1;
    if (1 < (int)piStack_78) {
      local_68 = FoxUI::FXUIBinderBase::vftable;
      if (local_64 != 0) {
        FUN_0089120c(local_64);
      }
      ExceptionList = local_14;
      __security_check_cookie(local_1c ^ (uint)&piStack_7c);
      return;
    }
  } while( true );
}

