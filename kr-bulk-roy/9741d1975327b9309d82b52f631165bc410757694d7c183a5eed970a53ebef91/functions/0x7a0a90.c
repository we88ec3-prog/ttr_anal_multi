
int FUN_007a0a90(void)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  ushort *in_EDX;
  undefined4 *puVar3;
  uint local_8;
  
  puVar3 = *(undefined4 **)(in_EAX + 4);
  if (*(char *)((int)puVar3[1] + 0x11) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(ushort *)(puVar1 + 3) < *in_EDX) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x11) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(in_EAX + 4)) && (*(ushort *)(puVar3 + 3) <= *in_EDX)) {
    return (int)puVar3 + 0xe;
  }
  local_8 = (uint)*in_EDX;
  FUN_007a3580();
  FUN_0081a600(&local_8,puVar3);
  return local_8 + 0xe;
}

