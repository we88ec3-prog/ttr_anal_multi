
void FUN_005cb1c0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int unaff_EDI;
  
  puVar2 = (undefined4 *)**(undefined4 **)(unaff_EDI + 0x4c);
  while (puVar2 != *(undefined4 **)(unaff_EDI + 0x4c)) {
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
        puVar6 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar6, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar6 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  iVar4 = *(int *)(unaff_EDI + 0x3c);
  piVar5 = *(int **)(iVar4 + 0x78);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    *(undefined4 *)(iVar4 + 0x78) = 0;
  }
  piVar5 = *(int **)(iVar4 + 0x7c);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    *(undefined4 *)(iVar4 + 0x7c) = 0;
  }
  *(undefined4 *)(iVar4 + 0x74) = 0;
  iVar4 = *(int *)(unaff_EDI + 0x40);
  piVar5 = *(int **)(iVar4 + 0x78);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    *(undefined4 *)(iVar4 + 0x78) = 0;
  }
  piVar5 = *(int **)(iVar4 + 0x7c);
  if (piVar5 != (int *)0x0) {
    (**(code **)(*piVar5 + 8))(piVar5);
    *(undefined4 *)(iVar4 + 0x7c) = 0;
  }
  *(undefined4 *)(iVar4 + 0x74) = 0;
  *(undefined4 *)(unaff_EDI + 0x38) = 0;
  return;
}

