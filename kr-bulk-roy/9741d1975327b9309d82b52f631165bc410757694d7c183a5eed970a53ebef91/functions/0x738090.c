
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_00738090(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  DAT_00fd2bb8 = 0;
  _DAT_00fd2bcc = 0;
  DAT_00fd2cd0 = 0;
  _DAT_00fd2cd4 = 0;
  _DAT_00fd2ce8 = 0;
  _DAT_00fd2cec = 0;
  _DAT_00fd2cd8 = 1;
  _DAT_00fd2cdc = 1;
  DAT_00fd2ce0 = 1;
  DAT_00fd2ce4 = 1;
  puVar1 = &DAT_00fd2c50;
  do {
    puVar2 = puVar1 + 1;
    puVar1[-0x20] = 0x3f800000;
    *puVar1 = 0x43800000;
    puVar1 = puVar2;
  } while ((int)puVar2 < 0xfd2cd0);
  return &DAT_00fd2bb8;
}

