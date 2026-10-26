
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00450910(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  FUN_00744ca0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xcb) {
    (**(code **)(*in_ECX + 0x54))();
    if ((_DAT_00fbacd8 & 1) == 0) {
      _DAT_00fbacd8 = _DAT_00fbacd8 | 1;
      _DAT_00fbacdc = 0;
      _DAT_00fbace0 = 0;
      _atexit((_func_4879 *)&DAT_00bcd6c0);
    }
    iVar1 = *in_ECX;
    uVar2 = FUN_0047a000((char)in_ECX[0x96],*(undefined1 *)((int)in_ECX + 0x259),0);
    (**(code **)(iVar1 + 0x50))(uVar2);
    return;
  }
  if (*(int *)(param_1 + 0x10) == 0xcc) {
    (**(code **)(*in_ECX + 0x54))();
  }
  return;
}

