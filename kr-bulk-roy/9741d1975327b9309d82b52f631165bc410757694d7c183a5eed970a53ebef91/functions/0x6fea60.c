
undefined4 * FUN_006fea60(byte param_1)

{
  undefined4 *puVar1;
  int in_EDX;
  int unaff_ESI;
  
  for (puVar1 = (undefined4 *)
                (((1 << (*(byte *)(in_EDX + 7) & 0x1f)) - 1U & *(uint *)(unaff_ESI + 8)) * 0x20 +
                *(int *)(in_EDX + 0x10)); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[7]) {
    if ((puVar1[6] == 4) && (puVar1[4] == unaff_ESI)) goto LAB_006fea96;
  }
  puVar1 = &DAT_00c0bfc8;
LAB_006fea96:
  if (puVar1[2] == 0) {
    *(byte *)(in_EDX + 6) = *(byte *)(in_EDX + 6) | '\x01' << (param_1 & 0x1f);
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}

