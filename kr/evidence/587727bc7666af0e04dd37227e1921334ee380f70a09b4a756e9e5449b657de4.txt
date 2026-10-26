
undefined4 FUN_004b99c0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if (DAT_00f9392c != *(byte *)(param_1 + 2)) {
    DAT_00f9392c = (uint)*(byte *)(param_1 + 2);
  }
  switch(*(undefined1 *)(param_1 + 2)) {
  case 2:
    iVar2 = FUN_00891268(0xbd54);
    if (iVar2 != 0) {
      FUN_004c46f0();
    }
    break;
  default:
    goto switchD_004b9a4e_caseD_3;
  case 4:
    iVar2 = FUN_00891268(0xbd5c);
    if (iVar2 != 0) {
      FUN_004bc6a0();
    }
    break;
  case 6:
    puVar1 = (undefined4 *)FUN_00891268(0xbd54);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_004add50();
      *puVar1 = Scene::CDuelField::vftable;
      DAT_00d6a674 = 0x44554546;
      FUN_004bdba0();
    }
    break;
  case 9:
    iVar2 = FUN_00891268(0xbd5c);
    if (iVar2 != 0) {
      FUN_004c54e0();
    }
    break;
  case 0x19:
    iVar2 = FUN_00891268(0xbd54);
    if (iVar2 != 0) {
      FUN_004564f0();
    }
    break;
  case 0x1a:
    iVar2 = FUN_00891268(0xbd54);
    if (iVar2 != 0) {
      FUN_004369d0();
    }
    break;
  case 0x1c:
    iVar2 = FUN_00891268(0xbd5c);
    if (iVar2 != 0) {
      FUN_00422fb0();
    }
  }
  FUN_004b7d50();
switchD_004b9a4e_caseD_3:
  ExceptionList = local_14;
  return 0;
}

