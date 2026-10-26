
void FUN_005759a0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int *unaff_EDI;
  
  puVar2 = *(undefined4 **)(*unaff_EDI + 4);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)(puVar3[0xb] + 4) + 8))();
    if ((int *)puVar3[0xb] != (int *)0x0) {
      (**(code **)(*(int *)puVar3[0xb] + 8))();
      puVar3[0xb] = 0;
    }
    puVar3[0xb] = 0;
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
        puVar6 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x31);
          puVar6 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  iVar5 = *unaff_EDI;
  FUN_007d0240(*(undefined4 *)(*(int *)(iVar5 + 4) + 4));
  *(int *)(*(int *)(iVar5 + 4) + 4) = *(int *)(iVar5 + 4);
  *(undefined4 *)*(undefined4 *)(iVar5 + 4) = *(undefined4 *)(iVar5 + 4);
  *(int *)(*(int *)(iVar5 + 4) + 8) = *(int *)(iVar5 + 4);
  *(undefined4 *)(iVar5 + 8) = 0;
  if ((int *)unaff_EDI[1] != (int *)0x0) {
    (**(code **)(*(int *)unaff_EDI[1] + 8))();
    unaff_EDI[1] = 0;
    if ((int *)unaff_EDI[2] != (int *)0x0) {
      (**(code **)(*(int *)unaff_EDI[2] + 8))();
      unaff_EDI[2] = 0;
    }
    if ((int *)unaff_EDI[3] != (int *)0x0) {
      (**(code **)(*(int *)unaff_EDI[3] + 8))();
      unaff_EDI[3] = 0;
    }
  }
  unaff_EDI[6] = 0;
  return;
}

