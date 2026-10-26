
void FUN_004856f0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_EAX;
  int *piVar6;
  undefined1 local_10 [12];
  
  puVar2 = *(undefined4 **)(in_EAX + 4);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    piVar6 = (int *)FUN_0044b540(&stack0x00000004);
    if (puVar3[5] != *piVar6) {
      FUN_004858c0(local_10,puVar3 + 3);
    }
    if (*(char *)((int)puVar3 + 0x21) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x21) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x21);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x21);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x21);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}

