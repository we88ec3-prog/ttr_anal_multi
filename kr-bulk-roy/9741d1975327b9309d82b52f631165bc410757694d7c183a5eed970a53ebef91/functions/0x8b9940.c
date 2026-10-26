
undefined1 FUN_008b9940(int param_1)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  
  puVar1 = *(undefined1 **)(param_1 + 0x20);
  uVar2 = 0;
  if (puVar1 < *(undefined1 **)(param_1 + 0x24)) {
    uVar2 = *puVar1;
    *(undefined1 **)(param_1 + 0x20) = puVar1 + 1;
  }
  return uVar2;
}

