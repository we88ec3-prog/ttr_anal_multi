
void FUN_0070db10(void)

{
  byte bVar1;
  int *piVar2;
  int in_EAX;
  int in_EDX;
  
  piVar2 = *(int **)(in_EAX + 0x30);
  bVar1 = *(byte *)((int)piVar2 + 0x32);
  while (in_EDX < (int)(uint)bVar1) {
    *(char *)((int)piVar2 + 0x32) = *(char *)((int)piVar2 + 0x32) + -1;
    *(int *)(*(int *)(*piVar2 + 0x18) + 8 +
            (uint)*(ushort *)((int)piVar2 + (uint)*(byte *)((int)piVar2 + 0x32) * 2 + 0xac) * 0xc) =
         piVar2[6];
    bVar1 = *(byte *)((int)piVar2 + 0x32);
  }
  return;
}

