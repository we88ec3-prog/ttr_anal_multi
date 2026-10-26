
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0048c170(int param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0094a07a;
  local_14 = ExceptionList;
  pvVar1 = (void *)(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  ExceptionList = &local_14;
  iVar2 = *(int *)(param_1 + 0xbfe0);
  if (iVar2 != 0) {
    piVar3 = *(int **)(iVar2 + 0x14);
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    if (piVar3 != (int *)0x0) {
      LOCK();
      iVar2 = piVar3[1] + -1;
      piVar3[1] = iVar2;
      UNLOCK();
      if (iVar2 == 0) {
        (**(code **)*piVar3)();
        LOCK();
        iVar2 = piVar3[2] + -1;
        piVar3[2] = iVar2;
        UNLOCK();
        if (iVar2 == 0) {
          (**(code **)(*piVar3 + 4))();
        }
      }
    }
    iVar2 = *(int *)(param_1 + 0xbfe0);
    if (iVar2 != 0) {
      FUN_006dbca0();
      FUN_0089120c(iVar2);
      *(undefined4 *)(param_1 + 0xbfe0) = 0;
    }
  }
  if ((_DAT_00fd8bf8 & 1) == 0) {
    _DAT_00fd8bf8 = _DAT_00fd8bf8 | 1;
    _DAT_00fd8bfc = 0;
    _atexit((_func_4879 *)&DAT_00bce310);
  }
  DAT_00fd8c00 = 0;
  _DAT_00fd8bfc = 0;
  iVar2 = FUN_00489ee0();
  *(undefined4 *)(iVar2 + 0x3c) = 1;
  WaitForSingleObject(*(HANDLE *)(iVar2 + 0x44),0xffffffff);
  FUN_004e7ec0(iVar2 + 0x10);
  FUN_004e7ec0(iVar2);
  (**(code **)(*DAT_00fba854 + 0x20))(0,1);
  (**(code **)(*DAT_00fba854 + 0x20))(1,1);
  (**(code **)(*DAT_00fba854 + 0x20))(2,1);
  if ((DAT_00fc1ac0 & 1) == 0) {
    DAT_00fc1ac0 = DAT_00fc1ac0 | 1;
    FUN_00558100();
    _atexit((_func_4879 *)&LAB_00bcdea0);
  }
  FUN_005585f0();
  if ((DAT_00fd8ea8 & 1) == 0) {
    DAT_00fd8ea8 = DAT_00fd8ea8 | 1;
    FUN_0055ac10();
    _atexit((_func_4879 *)&LAB_00bcdfe0);
  }
  FUN_0055ad50(&DAT_00fd8eb0);
  if ((DAT_00fc1bf4 & 1) == 0) {
    DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
    FUN_0057ef90();
    _atexit((_func_4879 *)&LAB_00bcdfb0);
  }
  if (DAT_00fc1c04 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fc1c04)(1);
    DAT_00fc1c04 = (undefined4 *)0x0;
  }
  if (DAT_00fc1c00 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fc1c00)(1);
    DAT_00fc1c00 = (undefined4 *)0x0;
  }
  if ((_DAT_00fdf3c0 & 1) == 0) {
    _DAT_00fdf3c0 = _DAT_00fdf3c0 | 1;
    DAT_00fdf3c4 = 0;
    _atexit((_func_4879 *)&DAT_00bcdf50);
  }
  iVar2 = DAT_00fdf3c4;
  if (DAT_00fdf3c4 != 0) {
    FUN_0056e0b0(DAT_00fdf3c4);
    FUN_0089120c(iVar2);
    DAT_00fdf3c4 = 0;
  }
  piVar3 = (int *)FUN_0048a2e0();
  (**(code **)(*piVar3 + 0xc))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  FUN_004e3050();
  FUN_00507340();
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  FUN_006ee240(&DAT_00fb9050);
  if ((_DAT_00fd2cf4 & 1) == 0) {
    _DAT_00fd2cf4 = _DAT_00fd2cf4 | 1;
    DAT_00fd2cf8 = CSceneManager::vftable;
    DAT_00fd8ba4 = (int *)0x0;
    FUN_004b7dc0();
    _atexit((_func_4879 *)&LAB_00bcdcf0);
  }
  if ((DAT_00fd8ba4 != (int *)0x0) &&
     ((**(code **)(*DAT_00fd8ba4 + 0x14))(), DAT_00fd8ba4 != (int *)0x0)) {
    (**(code **)*DAT_00fd8ba4)(1);
    DAT_00fd8ba4 = (int *)0x0;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  if (DAT_00fba7a4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fba7a4)(1);
  }
  DAT_00fab228 = 0;
  FUN_004e0fc0(&DAT_00fab158);
  FUN_004e0fc0(&DAT_00fab168);
  FUN_0044e720(&DAT_00fab138);
  FUN_004e1070(&DAT_00fab148);
  if (DAT_00fba82c != (int *)0x0) {
    (**(code **)(*DAT_00fba82c + 8))();
    DAT_00fba82c = (int *)0x0;
  }
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = 0;
    DAT_00fb79f8 = 0;
    DAT_00fb79fc = 0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  FUN_005448e0(&DAT_00fb79f0);
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    FUN_00550820();
    _atexit((_func_4879 *)&LAB_00bce6b0);
  }
  FUN_00550b50(&DAT_00fdf680);
  if ((DAT_00fab0d4 & 1) == 0) {
    DAT_00fab0d4 = DAT_00fab0d4 | 1;
    FUN_0080a3a0();
    _atexit((_func_4879 *)&LAB_00bccdd0);
  }
  FUN_0080b070(&DAT_00fab028);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  FUN_0044e720(&DAT_00fb73d8);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar2 = DAT_00fb76e8;
  if (DAT_00fb76e8 != 0) {
    FUN_00797b20();
    FUN_0089120c(iVar2);
  }
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  DAT_00fb76e8 = 0;
  FUN_007aab90();
  if ((_DAT_00fdf3d8 & 1) == 0) {
    _DAT_00fdf3d8 = _DAT_00fdf3d8 | 1;
    DAT_00fdf3dc = 0;
    DAT_00fdf3e0 = 0;
    _DAT_00fdf3e4 = 0;
    _atexit((_func_4879 *)&LAB_00bce280);
  }
  FUN_0049ebe0();
  FUN_00495460();
  ExceptionList = pvVar1;
  return 0;
}

