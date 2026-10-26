
void FUN_005cb110(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *unaff_EDI;
  
  puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0x4c);
  while (puVar2 != *(undefined4 **)(param_1 + 0x4c)) {
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
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x15);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  *(int **)(*(int *)(param_1 + 0x3c) + 0x74) = unaff_EDI;
  (**(code **)(*unaff_EDI + 0x68))();
  FUN_00775540();
  *(int **)(*(int *)(param_1 + 0x40) + 0x74) = unaff_EDI;
  (**(code **)(*unaff_EDI + 0x68))();
  FUN_00775540();
  *(int **)(param_1 + 0x38) = unaff_EDI;
  return;
}

