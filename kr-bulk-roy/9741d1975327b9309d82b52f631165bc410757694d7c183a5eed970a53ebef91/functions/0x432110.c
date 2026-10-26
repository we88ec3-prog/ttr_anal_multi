
undefined4 FUN_00432110(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int in_ECX;
  
  puVar1 = (undefined2 *)**(int **)(in_ECX + 0x20);
  if (puVar1 == (undefined2 *)0x0) {
    return 0xffff;
  }
  if (puVar1 < puVar1 + **(int **)(in_ECX + 0x30)) {
    return CONCAT22((short)((uint)puVar1 >> 0x10),*puVar1);
  }
  if ((((*(byte *)(in_ECX + 0x40) & 4) == 0) &&
      (puVar2 = (undefined2 *)**(undefined4 **)(in_ECX + 0x24), puVar2 != (undefined2 *)0x0)) &&
     ((puVar1 < puVar2 || (puVar1 < *(undefined2 **)(in_ECX + 0x3c))))) {
    if (*(undefined2 **)(in_ECX + 0x3c) < puVar2) {
      *(undefined2 **)(in_ECX + 0x3c) = puVar2;
    }
    **(int **)(in_ECX + 0x30) = *(int *)(in_ECX + 0x3c) - **(int **)(in_ECX + 0x20) >> 1;
    return CONCAT22((short)((uint)**(undefined4 **)(in_ECX + 0x20) >> 0x10),
                    *(undefined2 *)**(undefined4 **)(in_ECX + 0x20));
  }
  return 0xffff;
}

