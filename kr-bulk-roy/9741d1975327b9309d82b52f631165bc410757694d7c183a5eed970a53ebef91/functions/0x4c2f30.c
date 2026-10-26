
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c2f30(void)

{
  undefined4 *puVar1;
  
  (**(code **)(**(int **)(DAT_00fb1318 + 0x18) + 0xac))
            (*(int **)(DAT_00fb1318 + 0x18),0,0,3,0xff000000,0x3f800000,0);
  puVar1 = (undefined4 *)FUN_00891268(0xbd5c);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_004add50();
    *puVar1 = Scene::CLogin::vftable;
    puVar1[0x2f55] = 0;
    puVar1[0x2f56] = 0;
    DAT_00d6a674 = 0x4c4f4749;
    FUN_004c3220();
  }
  if ((_DAT_00fd2cf4 & 1) == 0) {
    _DAT_00fd2cf4 = _DAT_00fd2cf4 | 1;
    DAT_00fd2cf8 = CSceneManager::vftable;
    DAT_00fd8ba4 = 0;
    FUN_004b7dc0();
    _atexit((_func_4879 *)&LAB_00bcdcf0);
  }
  FUN_004b7d50();
  return 0;
}

