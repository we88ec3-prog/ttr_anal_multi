
undefined2 * FUN_007713e0(void)

{
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)FUN_00891268(0x3c);
  if (puVar1 != (undefined2 *)0x0) {
    *(undefined4 *)(puVar1 + 10) = 7;
    *(undefined4 *)(puVar1 + 8) = 0;
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 0x18) = 7;
    *(undefined4 *)(puVar1 + 0x16) = 0;
    puVar1[0xe] = 0;
    *(undefined4 *)(puVar1 + 0x1c) = 0;
    return puVar1;
  }
  return (undefined2 *)0x0;
}

