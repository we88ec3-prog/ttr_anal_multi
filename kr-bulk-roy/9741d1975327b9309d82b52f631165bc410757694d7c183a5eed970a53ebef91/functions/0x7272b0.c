
undefined4 FUN_007272b0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_EDX;
  
  if ((in_EDX != 0) && (puVar2 = *(undefined4 **)(in_EDX + 0x1c), puVar2 != (undefined4 *)0x0)) {
    puVar2[7] = 0;
    *(undefined4 *)(in_EDX + 0x14) = 0;
    *(undefined4 *)(in_EDX + 8) = 0;
    *(undefined4 *)(in_EDX + 0x18) = 0;
    *(undefined4 *)(in_EDX + 0x30) = 1;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[3] = 0;
    puVar2[8] = 0;
    puVar2[10] = 0;
    puVar2[0xb] = 0;
    puVar2[0xc] = 0;
    puVar2[0xe] = 0;
    puVar2[0xf] = 0;
    puVar1 = puVar2 + 0x14c;
    puVar2[5] = 0x8000;
    puVar2[0x1b] = puVar1;
    puVar2[0x14] = puVar1;
    puVar2[0x13] = puVar1;
    return 0;
  }
  return 0xfffffffe;
}

