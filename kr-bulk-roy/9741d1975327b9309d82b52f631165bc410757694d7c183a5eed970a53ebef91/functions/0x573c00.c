
void FUN_00573c00(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  void **ppvVar7;
  uint uVar8;
  int *piVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f658;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  puVar2 = *(undefined4 **)(*param_1 + 4);
  puVar3 = (undefined4 *)*puVar2;
  ppvVar7 = &local_10;
  local_10 = ExceptionList;
  piVar9 = param_1;
  while (ExceptionList = ppvVar7, param_1 = piVar9, puVar3 != puVar2) {
    iVar4 = puVar3[10];
    if (iVar4 != 0) {
      FUN_00572980(iVar4);
      FUN_0089120c(iVar4);
    }
    ppvVar7 = ExceptionList;
    piVar9 = param_1;
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x2d);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x2d);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  iVar4 = *piVar9;
  FUN_007b7d40(*(undefined4 *)(*(int *)(iVar4 + 4) + 4));
  *(int *)(*(int *)(iVar4 + 4) + 4) = *(int *)(iVar4 + 4);
  *(undefined4 *)*(undefined4 *)(iVar4 + 4) = *(undefined4 *)(iVar4 + 4);
  *(int *)(*(int *)(iVar4 + 4) + 8) = *(int *)(iVar4 + 4);
  *(undefined4 *)(iVar4 + 8) = 0;
  iVar4 = *piVar9;
  if (iVar4 != 0) {
    local_8 = 0;
    FUN_0057ffd0(**(undefined4 **)(iVar4 + 4),*(undefined4 **)(iVar4 + 4));
    local_8 = 0xffffffff;
    FUN_0089120c(*(undefined4 *)(iVar4 + 4),uVar8);
    FUN_0089120c(iVar4);
    piVar9 = param_1;
  }
  FUN_00574250(piVar9 + 1,&param_1,piVar9[1],piVar9[2]);
  piVar9[0x11] = 0;
  ExceptionList = local_10;
  return;
}

