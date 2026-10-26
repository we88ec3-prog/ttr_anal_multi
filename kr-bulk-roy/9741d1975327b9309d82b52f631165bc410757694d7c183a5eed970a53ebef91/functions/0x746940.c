
int FUN_00746940(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int unaff_ESI;
  undefined8 uVar6;
  
  puVar2 = *(undefined4 **)(unaff_ESI + 0x50);
  puVar5 = (undefined4 *)*puVar2;
  while( true ) {
    if (puVar5 == puVar2) {
      return 0;
    }
    uVar6 = FUN_007469c0(puVar5[4],param_1);
    puVar5 = (undefined4 *)((ulonglong)uVar6 >> 0x20);
    if ((int)uVar6 != 0) break;
    if (*(char *)((int)puVar5 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar5[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar3 + 0x15);
        puVar5 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar3 + 0x15);
          puVar5 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar5[1] + 0x15);
        puVar4 = (undefined4 *)puVar5[1];
        puVar3 = puVar5;
        while ((puVar5 = puVar4, cVar1 == '\0' && (puVar3 == (undefined4 *)puVar5[2]))) {
          cVar1 = *(char *)((int)puVar5[1] + 0x15);
          puVar4 = (undefined4 *)puVar5[1];
          puVar3 = puVar5;
        }
      }
    }
  }
  return (int)uVar6;
}

