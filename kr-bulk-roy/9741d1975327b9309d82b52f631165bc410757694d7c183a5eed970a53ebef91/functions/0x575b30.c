
void FUN_00575b30(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *unaff_EDI;
  
  puVar2 = *(undefined4 **)(*unaff_EDI + 4);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)(puVar3[0xb] + 4) + 8))();
    if (*(char *)((int)puVar3 + 0x31) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x31) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x31);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x31);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x31);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x31);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  if (unaff_EDI[1] != 0) {
    (**(code **)(*(int *)(unaff_EDI[1] + 4) + 8))();
    (**(code **)(*(int *)(unaff_EDI[2] + 4) + 8))();
    (**(code **)(*(int *)(unaff_EDI[3] + 4) + 8))();
  }
  unaff_EDI[6] = 0;
  return;
}

