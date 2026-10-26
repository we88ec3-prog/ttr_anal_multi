
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008ebf50(void)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = in_EAX;
  *(undefined4 *)(in_ECX + 0x1b0) = 0x20;
  uVar1 = FUN_008bc7d0();
  *(undefined4 *)(in_ECX + 0x1b4) = uVar1;
  if (in_ECX != 0) {
    FUN_008ebee0();
    return in_ECX;
  }
  _DAT_00000014 = 0;
  _DAT_00000184 = 0;
  uRam00000018 = 0;
  uRam00000188 = 0;
  _DAT_00000000 = 0;
  uRam00000004 = 0;
  _DAT_000001b8 = 0;
  return 0;
}

