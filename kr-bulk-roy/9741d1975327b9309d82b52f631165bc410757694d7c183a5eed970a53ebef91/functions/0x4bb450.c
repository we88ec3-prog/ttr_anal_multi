
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_004bb450(float param_1)

{
  undefined2 in_FPUControlWord;
  undefined1 uVar1;
  undefined1 local_8;
  
  uVar1 = (undefined1)((ushort)in_FPUControlWord >> 8);
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
  }
  local_8 = (undefined1)(int)ROUND(_DAT_00fb8824 * param_1);
  return CONCAT11(uVar1,local_8) | 0xc00;
}

