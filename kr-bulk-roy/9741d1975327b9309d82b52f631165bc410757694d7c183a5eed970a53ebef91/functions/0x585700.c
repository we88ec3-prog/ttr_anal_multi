
undefined4 * FUN_00585700(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(&DAT_00e560b8 + param_1 * 0x1c);
  if (7 < *(uint *)(&DAT_00e560cc + param_1 * 0x1c)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}

