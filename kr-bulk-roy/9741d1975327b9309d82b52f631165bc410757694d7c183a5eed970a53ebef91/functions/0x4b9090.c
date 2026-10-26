
undefined4 FUN_004b9090(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094713e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  switch((int)*(char *)(param_1 + 2)) {
  case 7:
    iVar3 = FUN_00891268(0xbd54,uVar1);
    if (iVar3 != 0) {
      FUN_004bbb70();
    }
    FUN_004b7d50();
    iVar3 = FUN_00404ba0();
    *(undefined4 *)(iVar3 + 0x69a8) = 7;
    break;
  default:
                    /* WARNING: Subroutine does not return */
    FUN_006edc70("Invalid GameMode %d",(int)*(char *)(param_1 + 2));
  case 0x15:
    puVar2 = (undefined4 *)FUN_00891268(0xbd54,uVar1);
    if (puVar2 == (undefined4 *)0x0) {
      FUN_004b7d50();
    }
    else {
      FUN_004add50();
      *puVar2 = Scene::CDuelSquare::vftable;
      DAT_00d6a674 = 0x44535155;
      FUN_004bb4a0();
      FUN_004b7d50();
    }
    break;
  case 0x17:
    iVar3 = FUN_00891268(0xbd54,uVar1);
    if (iVar3 != 0) {
      FUN_004bbb70();
    }
    FUN_004b7d50();
    iVar3 = FUN_00404ba0();
    *(undefined4 *)(iVar3 + 0x69a8) = 0x17;
    break;
  case 0x18:
    iVar3 = FUN_00891268(0xbd54,uVar1);
    if (iVar3 != 0) {
      FUN_004bbb70();
    }
    FUN_004b7d50();
    iVar3 = FUN_00404ba0();
    *(undefined4 *)(iVar3 + 0x69a8) = 0x18;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar3 = DAT_00fe1a88;
  if (DAT_00f9392c != *(char *)(param_1 + 2)) {
    DAT_00f9392c = (int)*(char *)(param_1 + 2);
  }
  *(uint *)(DAT_00fe1a88 + 0x18) = (uint)*(byte *)(param_1 + 3);
  *(uint *)(iVar3 + 0x1c) = (uint)*(byte *)(param_1 + 4);
  ExceptionList = local_14;
  return 0;
}

