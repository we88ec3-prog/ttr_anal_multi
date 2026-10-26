
void FUN_00536ff0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  void **ppvVar8;
  uint uVar9;
  undefined4 *in_ECX;
  int *piVar10;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b038;
  uVar9 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_8 = 2;
  puVar2 = (undefined4 *)in_ECX[0xc];
  puVar3 = (undefined4 *)*puVar2;
  ppvVar8 = &local_10;
  local_10 = ExceptionList;
  while (ExceptionList = ppvVar8, puVar3 != puVar2) {
    iVar4 = puVar3[4];
    if (iVar4 != 0) {
      FUN_00536ff0(uVar9);
      FUN_0089120c(iVar4);
    }
    ppvVar8 = ExceptionList;
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x15);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar7 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar7, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar7 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  uVar9 = (uint)local_8 >> 8;
  local_8 = CONCAT31((int3)uVar9,3);
  FUN_005540c0(*(undefined4 *)in_ECX[0xc],(undefined4 *)in_ECX[0xc]);
  FUN_0089120c(in_ECX[0xc]);
  piVar10 = (int *)in_ECX[7];
  if (piVar10 != (int *)0x0) {
    piVar6 = (int *)in_ECX[8];
    for (; piVar10 != piVar6; piVar10 = piVar10 + 4) {
      if (*piVar10 != 0) {
        FUN_0089120c(*piVar10);
      }
      *piVar10 = 0;
      piVar10[1] = 0;
      piVar10[2] = 0;
    }
    FUN_0089120c(in_ECX[7]);
  }
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  if (7 < (uint)in_ECX[5]) {
    FUN_0089120c(*in_ECX);
  }
  in_ECX[5] = 7;
  in_ECX[4] = 0;
  *(undefined2 *)in_ECX = 0;
  ExceptionList = local_10;
  return;
}

