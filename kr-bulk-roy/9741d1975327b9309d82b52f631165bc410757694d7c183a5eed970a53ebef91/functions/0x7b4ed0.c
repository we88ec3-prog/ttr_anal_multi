
undefined4 * FUN_007b4ed0(int param_1)

{
  byte *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  if (*(char *)((int)puVar3[1] + 0x25) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *in_EAX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x25) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(param_1 + 4)) && (*(byte *)(puVar3 + 3) <= *in_EAX)) {
    return puVar3 + 4;
  }
  FUN_007b53a0();
  FUN_007b5140(&param_1,puVar3);
  return (undefined4 *)(param_1 + 0x10);
}

