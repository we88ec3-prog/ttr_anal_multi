
void FUN_0064d1a0(void)

{
  int iVar1;
  int iVar2;
  undefined4 ****ppppuVar3;
  int in_ECX;
  undefined4 uVar4;
  int iStack_ac;
  undefined4 ***apppuStack_a8 [4];
  undefined4 uStack_98;
  uint uStack_94;
  undefined4 ***apppuStack_8c [4];
  undefined4 uStack_7c;
  uint uStack_78;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093d917;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_ac;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0xf0) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xf0) + 200))(DAT_00d61f20 ^ (uint)&stack0xffffff48);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  switch(DAT_00f9392c) {
  case 7:
    uVar4 = 0x13b;
    FUN_00585620(0x13b);
    FUN_00585330(uVar4);
    FUN_004068f0();
    local_c = 1;
    (**(code **)(**(int **)(in_ECX + 0x100) + 0x58))();
    iVar1 = FUN_0062ddf0();
    ppppuVar3 = (undefined4 ****)apppuStack_a8[0];
    if (uStack_94 < 8) {
      ppppuVar3 = apppuStack_a8;
    }
    iStack_ac = iVar1;
    iVar2 = FUN_0044df20(0,ppppuVar3,uStack_98);
    if (iVar2 != 0) {
      if (iVar1 != 0) {
        uVar4 = 0x2b7;
        FUN_00585620(0x2b7);
        FUN_00585330(uVar4);
        FUN_00757710();
      }
      uVar4 = 0x13b;
      FUN_00585620(0x13b);
      FUN_00585330(uVar4);
      uVar4 = FUN_004068f0();
      local_c._0_1_ = 2;
      FUN_00757800(uVar4);
      local_c = CONCAT31(local_c._1_3_,1);
LAB_0064d33b:
      FUN_004fa440();
      (**(code **)(**(int **)(in_ECX + 0xec) + 200))();
    }
    break;
  default:
    goto switchD_0064d254_caseD_8;
  case 0x15:
    uVar4 = 0x13d;
    FUN_00585620(0x13d);
    FUN_00585330(uVar4);
    FUN_004068f0();
    local_c = 5;
    (**(code **)(**(int **)(in_ECX + 0x100) + 0x58))();
    iVar1 = FUN_0062ddf0();
    ppppuVar3 = (undefined4 ****)apppuStack_8c[0];
    if (uStack_78 < 8) {
      ppppuVar3 = apppuStack_8c;
    }
    iStack_ac = iVar1;
    iVar2 = FUN_0044df20(0,ppppuVar3,uStack_7c);
    if (iVar2 != 0) {
      if (iVar1 != 0) {
        uVar4 = 0x2b8;
        FUN_00585620(0x2b8);
        FUN_00585330(uVar4);
        FUN_00757710();
      }
      uVar4 = 0x13d;
      FUN_00585620(0x13d);
      FUN_00585330(uVar4);
      uVar4 = FUN_004068f0();
      local_c._0_1_ = 6;
      FUN_00757800(uVar4);
      local_c = CONCAT31(local_c._1_3_,5);
      FUN_004fa440();
      (**(code **)(**(int **)(in_ECX + 0xec) + 200))();
    }
    if (uStack_78 < 8) goto switchD_0064d254_caseD_8;
    goto LAB_0064d553;
  case 0x17:
  case 0x18:
    uVar4 = 0x13c;
    FUN_00585620(0x13c);
    FUN_00585330(uVar4);
    FUN_004068f0();
    local_c = 3;
    (**(code **)(**(int **)(in_ECX + 0x100) + 0x58))();
    iVar1 = FUN_0062ddf0();
    ppppuVar3 = (undefined4 ****)apppuStack_a8[0];
    if (uStack_94 < 8) {
      ppppuVar3 = apppuStack_a8;
    }
    iStack_ac = iVar1;
    iVar2 = FUN_0044df20(0,ppppuVar3,uStack_98);
    if (iVar2 != 0) {
      if (iVar1 != 0) {
        uVar4 = 0x2b9;
        FUN_00585620(0x2b9);
        FUN_00585330(uVar4);
        FUN_00757710();
      }
      uVar4 = 0x13c;
      FUN_00585620(0x13c);
      FUN_00585330(uVar4);
      uVar4 = FUN_004068f0();
      local_c._0_1_ = 4;
      FUN_00757800(uVar4);
      local_c = CONCAT31(local_c._1_3_,3);
      goto LAB_0064d33b;
    }
  }
  apppuStack_8c[0] = apppuStack_a8[0];
  if (7 < uStack_94) {
LAB_0064d553:
    FUN_0089120c(apppuStack_8c[0]);
  }
switchD_0064d254_caseD_8:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_ac);
  return;
}

