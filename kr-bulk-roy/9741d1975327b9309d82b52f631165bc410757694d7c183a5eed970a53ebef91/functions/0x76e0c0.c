
undefined4 * FUN_0076e0c0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  
  if (in_EAX == 0x103c4) {
    puVar1 = _malloc(0xc);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIDockInfo::vftable;
LAB_0076e139:
      puVar1[2] = 6;
      puVar1[1] = DAT_00fba828 + 1;
      DAT_00fba828 = DAT_00fba828 + 1;
      return puVar1;
    }
  }
  else if (in_EAX == 0x103c5) {
    puVar1 = _malloc(0x1c);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = DAT_00fba828 + 1;
      puVar1[2] = 6;
      *puVar1 = FoxUI::FXUIDockInfoLock::vftable;
      puVar1[6] = 0;
      puVar1[5] = 0;
      puVar1[4] = 0;
      puVar1[3] = 0;
      DAT_00fba828 = DAT_00fba828 + 1;
      return puVar1;
    }
  }
  else if (in_EAX == 0x103c6) {
    puVar1 = _malloc(0xc);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIDockInfoOutter::vftable;
      goto LAB_0076e139;
    }
  }
  return (undefined4 *)0x0;
}

