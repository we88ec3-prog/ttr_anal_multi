
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00817ed0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  void **ppvVar9;
  undefined4 *puVar10;
  uint uVar11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar8 = DAT_00fab280;
  puStack_c = &LAB_0090ea85;
  uVar11 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8 = 1;
  puVar2 = (undefined4 *)*DAT_00fab280;
  ppvVar9 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar9, puVar2 != puVar8) {
    puVar3 = (undefined4 *)puVar2[5];
    puVar4 = (undefined4 *)*puVar3;
    while (puVar4 != puVar3) {
      piVar5 = (int *)puVar4[4];
      if ((*piVar5 == 0) && (iVar6 = piVar5[0x17], iVar6 != 0)) {
        FUN_0081b6a0(uVar11);
        FUN_0089120c(iVar6);
        piVar5[0x17] = 0;
      }
      iVar6 = puVar4[4];
      if (iVar6 != 0) {
        if (*(int *)(iVar6 + 0x68) != 0) {
          FUN_0089120c(*(int *)(iVar6 + 0x68));
        }
        *(undefined4 *)(iVar6 + 0x68) = 0;
        *(undefined4 *)(iVar6 + 0x6c) = 0;
        *(undefined4 *)(iVar6 + 0x70) = 0;
        FUN_0089120c(iVar6);
      }
      if (puVar4[5] != 0) {
        FUN_0089120c(puVar4[5]);
      }
      if (*(char *)((int)puVar4 + 0x19) == '\0') {
        puVar7 = (undefined4 *)puVar4[2];
        if (*(char *)((int)puVar7 + 0x19) == '\0') {
          cVar1 = *(char *)((int)*puVar7 + 0x19);
          puVar4 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar7 + 0x19);
            puVar4 = puVar7;
            puVar7 = (undefined4 *)*puVar7;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar4[1] + 0x19);
          puVar10 = (undefined4 *)puVar4[1];
          puVar7 = puVar4;
          while ((puVar4 = puVar10, cVar1 == '\0' && (puVar7 == (undefined4 *)puVar4[2]))) {
            cVar1 = *(char *)((int)puVar4[1] + 0x19);
            puVar10 = (undefined4 *)puVar4[1];
            puVar7 = puVar4;
          }
        }
      }
    }
    ppvVar9 = ExceptionList;
    if (*(char *)((int)puVar2 + 0x21) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x21);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x21);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x21);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x21);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  FUN_008197a0(DAT_00fab280[1]);
  DAT_00fab280[1] = DAT_00fab280;
  *DAT_00fab280 = DAT_00fab280;
  DAT_00fab280[2] = DAT_00fab280;
  DAT_00fab284 = 0;
  if (DAT_00fab28c != 0) {
    FUN_0089120c(DAT_00fab28c);
  }
  DAT_00fab28c = 0;
  _DAT_00fab290 = 0;
  _DAT_00fab294 = 0;
  local_8 = 2;
  FUN_00819860(*DAT_00fab280,DAT_00fab280);
  FUN_0089120c(DAT_00fab280);
  ExceptionList = local_10;
  return;
}

