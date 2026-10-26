
undefined4 * FUN_00720570(int *param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  char local_35;
  int local_34;
  int *local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 *local_24;
  int local_20;
  char *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00907f31;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if ((param_2 != 0) && (*(char *)(param_2 + 1) != '\x01')) {
                    /* WARNING: Subroutine does not return */
    FUN_0071f620();
  }
  iVar6 = param_1[5];
  local_35 = '\0';
  local_30 = (int *)0x3;
  if (iVar6 == 0x16) {
    local_30 = (int *)0x2;
    local_35 = '\x01';
    FUN_0071d0d0(uVar3);
  }
  else {
    if (iVar6 == 0x17) {
      FUN_0071d0d0(uVar3);
      puVar4 = (undefined4 *)FUN_0071bdb0();
      if (puVar4 == (undefined4 *)0x0) {
LAB_0072064e:
                    /* WARNING: Subroutine does not return */
        FUN_0071f670();
      }
      *puVar4 = 0x20c0138;
LAB_00720659:
      puVar4[1] = param_2;
      puVar4[2] = 0;
      puVar4[3] = 0;
      puVar4[4] = 0;
      ExceptionList = local_14;
      return puVar4;
    }
    if (iVar6 == 0x18) {
      FUN_0071d0d0(uVar3);
      puVar4 = (undefined4 *)FUN_0071bdb0();
      if (puVar4 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0071f670();
      }
      *puVar4 = 0x2090138;
      goto LAB_00720659;
    }
  }
  local_20 = 0;
  local_1c = (char *)0x0;
  if (param_1[5] == 0x14) {
    local_20 = param_1[3];
    local_1c = (char *)param_1[4];
    FUN_0071d0d0(uVar3);
    if (param_1[5] == 0x19) {
      if (local_35 != '\0') {
                    /* WARNING: Subroutine does not return */
        FUN_0071f620();
      }
      local_30 = (int *)FUN_0071ff30(&local_35);
      if (local_35 == '\0') {
                    /* WARNING: Subroutine does not return */
        FUN_0071f620();
      }
      FUN_0071d0d0();
      if (param_1[5] == 9) goto LAB_00720805;
      if (param_1[5] != 0x14) goto LAB_0072074d;
      local_20 = param_1[3];
      local_1c = (char *)param_1[4];
      FUN_0071d0d0();
    }
    if (param_1[5] != 0xc) {
      if ((((int)local_1c - local_20 < 3) || (local_1c[-2] != ':')) || (local_1c[-1] != '*')) {
        local_34 = 1;
      }
      else {
        local_34 = 8;
        local_1c = local_1c + -1;
      }
      goto LAB_00720815;
    }
    FUN_0071d0d0();
    iVar6 = param_1[5];
    if (iVar6 == 0xd) {
      FUN_0071d0d0();
      local_34 = FUN_00720100();
      if (local_34 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0071f620();
      }
      local_20 = 0;
      local_1c = (char *)0x0;
      goto LAB_00720815;
    }
    cVar2 = FUN_0071d0a0();
    if (cVar2 == '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    if (iVar6 != 0xe) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    local_20 = param_1[3];
    local_1c = (char *)param_1[4];
    local_34 = 6;
    FUN_0071d0d0();
    if (param_1[5] != 0xd) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
  }
  else {
    if (param_1[5] != 9) {
LAB_0072074d:
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
LAB_00720805:
    local_1c = (char *)0x0;
    local_20 = 0;
    local_34 = 7;
  }
  FUN_0071d0d0(uVar3);
LAB_00720815:
  puVar4 = (undefined4 *)FUN_0071bdb0();
  local_2c = puVar4;
  if (puVar4 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0071f670();
  }
  local_c = 0;
  local_28 = puVar4;
  local_24 = puVar4;
  uVar5 = FUN_0071f6d0(&local_20);
  *(undefined1 *)((int)puVar4 + 2) = local_30._0_1_;
  *(undefined2 *)puVar4 = 0x138;
  *(undefined1 *)((int)puVar4 + 3) = (undefined1)local_34;
  puVar4[1] = param_2;
  puVar4[2] = 0;
  puVar4[3] = 0;
  puVar4[4] = uVar5;
  local_c = 0xffffffff;
  iVar6 = param_1[5];
  local_30 = (int *)0x0;
  do {
    if (iVar6 != 0x12) {
      ExceptionList = local_14;
      return puVar4;
    }
    FUN_0071d0d0();
    iVar6 = FUN_00721210();
    piVar1 = (int *)*param_1;
    uVar3 = piVar1[1] + 0x18;
    if (uVar3 < 0x1001) {
      piVar7 = (int *)(piVar1[1] + 4 + *piVar1);
      piVar1[1] = uVar3;
    }
    else {
      piVar7 = (int *)(*(code *)PTR_FUN_00d63d48)(0x1004);
      if (piVar7 == (int *)0x0) goto LAB_0072064e;
      *piVar7 = *piVar1;
      *piVar1 = (int)piVar7;
      piVar1[1] = 0x18;
      piVar7 = piVar7 + 1;
    }
    if (piVar7 == (int *)0x0) goto LAB_0072064e;
    *piVar7 = 0x10f;
    piVar7[1] = iVar6;
    piVar7[2] = 0;
    piVar7[3] = 0;
    if (param_1[5] != 0x13) {
                    /* WARNING: Subroutine does not return */
      FUN_0071f620();
    }
    FUN_0071d0d0();
    if (local_30 == (int *)0x0) {
      local_2c[2] = piVar7;
    }
    else {
      local_30[3] = (int)piVar7;
    }
    iVar6 = param_1[5];
    puVar4 = local_2c;
    local_30 = piVar7;
  } while( true );
}

