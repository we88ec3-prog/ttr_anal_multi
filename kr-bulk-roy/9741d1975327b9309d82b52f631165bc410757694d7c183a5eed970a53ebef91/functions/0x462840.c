
void FUN_00462840(short param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_EDX;
  undefined4 *puVar5;
  
  puVar2 = *(undefined4 **)(in_EDX + 4);
  cVar1 = *(char *)((int)puVar2[1] + 0x25);
  puVar5 = puVar2;
  puVar4 = (undefined4 *)puVar2[1];
  while (cVar1 == '\0') {
    if ((int)param_1 < (int)puVar4[3]) {
      puVar3 = (undefined4 *)*puVar4;
      puVar5 = puVar4;
    }
    else {
      puVar3 = (undefined4 *)puVar4[2];
    }
    puVar4 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x25);
  }
  cVar1 = *(char *)((int)puVar2[1] + 0x25);
  puVar4 = (undefined4 *)puVar2[1];
  while (cVar1 == '\0') {
    if ((int)puVar4[3] < (int)param_1) {
      puVar3 = (undefined4 *)puVar4[2];
      puVar4 = puVar2;
    }
    else {
      puVar3 = (undefined4 *)*puVar4;
    }
    puVar2 = puVar4;
    puVar4 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x25);
  }
  while (puVar2 != puVar5) {
    FUN_0053dd00();
    if (*(char *)((int)puVar2 + 0x25) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0x25) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x25);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x25);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar2[1] + 0x25);
        puVar3 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar3, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar1 = *(char *)((int)puVar2[1] + 0x25);
          puVar3 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  }
  return;
}

