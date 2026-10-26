
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052f960(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  void **ppvVar8;
  undefined4 *puVar9;
  uint uVar10;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar6 = DAT_00fc109c;
  puStack_c = &LAB_0090b09c;
  uVar10 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8 = 2;
  puVar2 = (undefined4 *)*DAT_00fc109c;
  ppvVar8 = &local_10;
  local_10 = ExceptionList;
  puVar4 = DAT_00fc10ac;
  while (ExceptionList = ppvVar8, DAT_00fc10ac = puVar4, puVar2 != puVar6) {
    if ((undefined4 *)puVar2[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar2[4])(1,uVar10);
    }
    ppvVar8 = ExceptionList;
    puVar4 = DAT_00fc10ac;
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar9 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar9, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar9 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  puVar2 = (undefined4 *)*puVar4;
  puVar6 = DAT_00fc10bc;
  while (DAT_00fc10bc = puVar6, puVar2 != puVar4) {
    if ((undefined4 *)puVar2[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar2[4])(1);
    }
    puVar6 = DAT_00fc10bc;
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar9 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar9, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar9 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  puVar2 = (undefined4 *)*puVar6;
  while (puVar2 != puVar6) {
    if ((undefined4 *)puVar2[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar2[4])(1);
    }
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x15);
        puVar3 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar3, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar3 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  }
  cVar1 = *(char *)((int)DAT_00fc109c[1] + 0x15);
  piVar7 = (int *)DAT_00fc109c[1];
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar7[2]);
    piVar5 = (int *)*piVar7;
    FUN_0089120c(piVar7);
    piVar7 = piVar5;
    cVar1 = *(char *)((int)piVar5 + 0x15);
  }
  DAT_00fc109c[1] = DAT_00fc109c;
  *DAT_00fc109c = DAT_00fc109c;
  DAT_00fc109c[2] = DAT_00fc109c;
  _DAT_00fc10a0 = 0;
  cVar1 = *(char *)((int)DAT_00fc10ac[1] + 0x15);
  piVar7 = (int *)DAT_00fc10ac[1];
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar7[2]);
    piVar5 = (int *)*piVar7;
    FUN_0089120c(piVar7);
    piVar7 = piVar5;
    cVar1 = *(char *)((int)piVar5 + 0x15);
  }
  DAT_00fc10ac[1] = DAT_00fc10ac;
  *DAT_00fc10ac = DAT_00fc10ac;
  DAT_00fc10ac[2] = DAT_00fc10ac;
  _DAT_00fc10b0 = 0;
  cVar1 = *(char *)((int)DAT_00fc10bc[1] + 0x15);
  piVar7 = (int *)DAT_00fc10bc[1];
  while (cVar1 == '\0') {
    FUN_0073eba0(piVar7[2]);
    piVar5 = (int *)*piVar7;
    FUN_0089120c(piVar7);
    piVar7 = piVar5;
    cVar1 = *(char *)((int)piVar5 + 0x15);
  }
  DAT_00fc10bc[1] = DAT_00fc10bc;
  *DAT_00fc10bc = DAT_00fc10bc;
  DAT_00fc10bc[2] = DAT_00fc10bc;
  _DAT_00fc10c0 = 0;
  local_8._1_3_ = (undefined3)((uint)local_8 >> 8);
  local_8._0_1_ = 3;
  FUN_005540c0(*DAT_00fc10bc,DAT_00fc10bc);
  FUN_0089120c(DAT_00fc10bc);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_005540c0(*DAT_00fc10ac,DAT_00fc10ac);
  FUN_0089120c(DAT_00fc10ac);
  local_8 = 5;
  FUN_005540c0(*DAT_00fc109c,DAT_00fc109c);
  FUN_0089120c(DAT_00fc109c);
  ExceptionList = local_10;
  return;
}

