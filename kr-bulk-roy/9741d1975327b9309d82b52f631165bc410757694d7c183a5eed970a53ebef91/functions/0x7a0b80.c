
undefined4 * FUN_007a0b80(void)

{
  uint *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  int local_8;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[4] < *in_EAX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(in_ECX + 4)) && ((uint)puVar3[4] <= *in_EAX)) {
    return puVar3 + 6;
  }
  FUN_007a25f0();
  FUN_007a28e0(&local_8,puVar3);
  return (undefined4 *)(local_8 + 0x18);
}

