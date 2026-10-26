
/* WARNING: Removing unreachable block (ram,0x0085a584) */

void FUN_0085a440(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar6 = param_1;
  piVar2 = *(int **)(param_1 + 4);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(iVar6 + 4) = 0;
  }
  FUN_0085d0d0(iVar6);
  puVar3 = *(undefined4 **)(iVar6 + 0x34);
  puVar4 = (undefined4 *)*puVar3;
  while (puVar4 != puVar3) {
    if ((puVar4[0xb] == 0) && (piVar2 = (int *)puVar4[4], piVar2 != (int *)0x0)) {
      (**(code **)(*piVar2 + 8))(piVar2);
      puVar4[4] = 0;
    }
    if (*(char *)((int)puVar4 + 0x45) == '\0') {
      puVar5 = (undefined4 *)puVar4[2];
      if (*(char *)((int)puVar5 + 0x45) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x45);
        puVar4 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x45);
          puVar4 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar4[1] + 0x45);
        puVar7 = (undefined4 *)puVar4[1];
        puVar5 = puVar4;
        while ((puVar4 = puVar7, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar4[2]))) {
          cVar1 = *(char *)((int)puVar4[1] + 0x45);
          puVar7 = (undefined4 *)puVar4[1];
          puVar5 = puVar4;
        }
      }
    }
  }
  FUN_0085e0f0(*(undefined4 *)(*(int *)(iVar6 + 0x34) + 4));
  *(int *)(*(int *)(iVar6 + 0x34) + 4) = *(int *)(iVar6 + 0x34);
  *(undefined4 *)*(undefined4 *)(iVar6 + 0x34) = *(undefined4 *)(iVar6 + 0x34);
  *(int *)(*(int *)(iVar6 + 0x34) + 8) = *(int *)(iVar6 + 0x34);
  *(undefined4 *)(iVar6 + 0x38) = 0;
  puVar3 = *(undefined4 **)(iVar6 + 0x44);
  puVar4 = (undefined4 *)*puVar3;
  iVar6 = param_1;
  while (param_1 = iVar6, puVar4 != puVar3) {
    piVar2 = (int *)puVar4[4];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      puVar4[4] = 0;
    }
    iVar6 = param_1;
    if (*(char *)((int)puVar4 + 0x41) == '\0') {
      puVar5 = (undefined4 *)puVar4[2];
      if (*(char *)((int)puVar5 + 0x41) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x41);
        puVar4 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x41);
          puVar4 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar4[1] + 0x41);
        puVar7 = (undefined4 *)puVar4[1];
        puVar5 = puVar4;
        while ((puVar4 = puVar7, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar4[2]))) {
          cVar1 = *(char *)((int)puVar4[1] + 0x41);
          puVar7 = (undefined4 *)puVar4[1];
          puVar5 = puVar4;
        }
      }
    }
  }
  FUN_0085e140(*(undefined4 *)(*(int *)(iVar6 + 0x44) + 4));
  *(int *)(*(int *)(iVar6 + 0x44) + 4) = *(int *)(iVar6 + 0x44);
  *(undefined4 *)*(undefined4 *)(iVar6 + 0x44) = *(undefined4 *)(iVar6 + 0x44);
  *(int *)(*(int *)(iVar6 + 0x44) + 8) = *(int *)(iVar6 + 0x44);
  *(undefined4 *)(iVar6 + 0x48) = 0;
  if (*(int *)(iVar6 + 0x8c) != *(int *)(iVar6 + 0x90)) {
    *(int *)(iVar6 + 0x90) = *(int *)(iVar6 + 0x8c);
  }
  FUN_0085e020(iVar6 + 0x20,&param_1,*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x24));
  return;
}

