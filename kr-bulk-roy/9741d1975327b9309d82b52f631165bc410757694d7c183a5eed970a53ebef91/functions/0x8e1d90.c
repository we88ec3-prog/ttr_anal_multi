
undefined1 FUN_008e1d90(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  int in_EDX;
  
  puVar2 = *(undefined1 **)(in_EDX + 0xc);
  if (puVar2 < *(undefined1 **)(in_EDX + 8)) {
    uVar1 = *puVar2;
    *(undefined1 **)(in_EDX + 0xc) = puVar2 + 1;
    return uVar1;
  }
  FUN_008e0760();
  return 0;
}

