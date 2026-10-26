
void FUN_00745680(void)

{
  char cVar1;
  code *pcVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *in_ECX;
  
  pcVar2 = *(code **)(*in_ECX + 0x10c);
  in_ECX[10] = in_ECX[10] ^ 0x200000;
  (*pcVar2)();
  puVar3 = (undefined4 *)in_ECX[0x14];
  puVar4 = (undefined4 *)*puVar3;
  while (puVar4 != puVar3) {
    FUN_00745680();
    if (*(char *)((int)puVar4 + 0x15) == '\0') {
      puVar5 = (undefined4 *)puVar4[2];
      if (*(char *)((int)puVar5 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x15);
        puVar4 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x15);
          puVar4 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar4[1] + 0x15);
        puVar6 = (undefined4 *)puVar4[1];
        puVar5 = puVar4;
        while ((puVar4 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar4[2]))) {
          cVar1 = *(char *)((int)puVar4[1] + 0x15);
          puVar6 = (undefined4 *)puVar4[1];
          puVar5 = puVar4;
        }
      }
    }
  }
  return;
}

