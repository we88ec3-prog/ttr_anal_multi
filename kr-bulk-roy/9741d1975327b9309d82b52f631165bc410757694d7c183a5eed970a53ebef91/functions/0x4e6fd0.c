
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004e6fd0(uint param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  
  *(undefined1 *)(in_ECX + 0x68f9) = *(undefined1 *)(param_1 + 3);
  *(undefined1 *)(in_ECX + 0x68fa) = *(undefined1 *)(param_1 + 2);
  puVar1 = (undefined4 *)FUN_00891268(0x14);
  iVar2 = 0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = FoxUI::FXUIEvent::vftable;
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1[3] = 0;
    puVar1[4] = 0xf42d4;
  }
  FUN_004072a0();
  do {
    if (((uint)*(byte *)(in_ECX + 0x68fa) & 1 << ((byte)iVar2 & 0x1f)) != 0) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      param_1 = (uint)CONCAT12((byte)iVar2,0x101);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&param_1,4);
      }
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return 0;
}

