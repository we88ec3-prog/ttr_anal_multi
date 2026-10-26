
int FUN_0081a580(void)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 in_ECX;
  ushort *in_EDX;
  undefined4 *puVar3;
  uint3 local_8;
  undefined1 uStack_5;
  
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
  uStack_5 = (undefined1)((uint)in_ECX >> 0x18);
  local_8 = (uint3)*in_EDX;
  FUN_005d0da0();
  FUN_0081a600(&local_8,puVar3);
  return _local_8 + 0xe;
}

