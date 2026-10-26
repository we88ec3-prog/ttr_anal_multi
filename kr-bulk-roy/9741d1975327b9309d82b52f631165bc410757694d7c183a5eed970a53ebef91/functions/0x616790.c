
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00616790(void)

{
  code *pcVar1;
  int iVar2;
  int in_EAX;
  undefined4 uVar3;
  undefined1 in_CL;
  int *unaff_ESI;
  
  unaff_ESI[0x92] = in_EAX;
  pcVar1 = *(code **)(*unaff_ESI + 0x54);
  *(undefined1 *)(unaff_ESI + 0x94) = in_CL;
  unaff_ESI[0x93] = 1;
  (*pcVar1)();
  if ((_DAT_00fc0db0 & 1) == 0) {
    _DAT_00fc0db0 = _DAT_00fc0db0 | 1;
    DAT_00fc0db4 = 0;
    DAT_00fc0db8 = 0;
    DAT_00fc0dbc = 0;
    DAT_00fc0dc0 = 0;
    _atexit((_func_4879 *)&DAT_00bcd9e0);
  }
  iVar2 = *unaff_ESI;
  uVar3 = FUN_0060c740(unaff_ESI[0x92],(char)unaff_ESI[0x94],unaff_ESI[0x97],unaff_ESI[0x98]);
  (**(code **)(iVar2 + 0x50))(uVar3);
  return;
}

