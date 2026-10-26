
undefined4 * FUN_0054f4e0(int param_1)

{
  uint *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *in_EAX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(param_1 + 4)) && ((uint)puVar3[3] <= *in_EAX)) {
    return puVar3 + 4;
  }
  FUN_0054f7d0();
  FUN_0054f6a0(&param_1,puVar3);
  return (undefined4 *)(param_1 + 0x10);
}

