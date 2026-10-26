
undefined4 * FUN_00819650(void)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte *in_EDX;
  undefined4 *puVar3;
  int local_8;
  
  puVar3 = *(undefined4 **)(in_EAX + 4);
  if (*(char *)((int)puVar3[1] + 0x19) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *in_EDX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x19) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(in_EAX + 4)) && (*(byte *)(puVar3 + 3) <= *in_EDX)) {
    return puVar3 + 4;
  }
  FUN_004edd10();
  FUN_00819f80(&local_8,puVar3);
  return (undefined4 *)(local_8 + 0x10);
}

