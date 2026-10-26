
undefined4 FUN_008d66b0(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_008b8f30(*(undefined4 *)(param_1 + 4),"truetype");
  if (puVar1 == (undefined4 *)0x0) {
    return 0xb;
  }
  *(undefined4 *)(param_1 + 0x1c) = *puVar1;
  return 0;
}

