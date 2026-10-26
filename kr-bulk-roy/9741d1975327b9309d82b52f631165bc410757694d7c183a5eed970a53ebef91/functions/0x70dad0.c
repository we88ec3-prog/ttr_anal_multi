
void FUN_0070dad0(void)

{
  int *piVar1;
  int in_EAX;
  int in_EDX;
  
  piVar1 = *(int **)(in_EAX + 0x30);
  *(char *)((int)piVar1 + 0x32) = *(char *)((int)piVar1 + 0x32) + (char)in_EDX;
  for (; in_EDX != 0; in_EDX = in_EDX + -1) {
    *(int *)(*(int *)(*piVar1 + 0x18) + 4 +
            (uint)*(ushort *)
                   ((int)piVar1 + ((uint)*(byte *)((int)piVar1 + 0x32) - in_EDX) * 2 + 0xac) * 0xc)
         = piVar1[6];
  }
  return;
}

