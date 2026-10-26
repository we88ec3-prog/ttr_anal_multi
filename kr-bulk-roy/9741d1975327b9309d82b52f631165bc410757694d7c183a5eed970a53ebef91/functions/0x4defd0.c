
void FUN_004defd0(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = DAT_00fab1d0;
  puStack_c = &LAB_00917620;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 5;
  if (DAT_00fab1d0 != 0) {
    FUN_0082cd30(DAT_00fab1d0);
    FUN_0089120c(iVar1);
    DAT_00fab1d0 = 0;
  }
  iVar1 = DAT_00fab1d4;
  if (DAT_00fab1d4 != 0) {
    FUN_0082cf90(DAT_00fab1d4);
    FUN_0089120c(iVar1);
    DAT_00fab1d4 = 0;
  }
  iVar1 = DAT_00fab134;
  if (DAT_00fab134 != 0) {
    FUN_0053d590(uVar3);
    FUN_0089120c(iVar1);
    DAT_00fab134 = 0;
  }
  if (DAT_00fab130 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fab130)(1);
    DAT_00fab130 = (undefined4 *)0x0;
  }
  local_8._0_1_ = 4;
  FUN_006d6ce0(&DAT_00fab200);
  piVar2 = DAT_00fab1cc;
  local_8._0_1_ = 3;
  if (DAT_00fab1cc != (int *)0x0) {
    LOCK();
    iVar1 = DAT_00fab1cc[1] + -1;
    DAT_00fab1cc[1] = iVar1;
    UNLOCK();
    if (iVar1 == 0) {
      (**(code **)*piVar2)();
      LOCK();
      iVar1 = piVar2[2] + -1;
      piVar2[2] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        (**(code **)(*piVar2 + 4))();
      }
    }
  }
  local_8._0_1_ = 6;
  FUN_005540c0(*DAT_00fab16c,DAT_00fab16c);
  FUN_0089120c(DAT_00fab16c);
  local_8._0_1_ = 7;
  FUN_005540c0(*DAT_00fab15c,DAT_00fab15c);
  FUN_0089120c(DAT_00fab15c);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_005540c0(*DAT_00fab14c,DAT_00fab14c);
  FUN_0089120c(DAT_00fab14c);
  local_8 = 9;
  FUN_005540c0(*DAT_00fab13c,DAT_00fab13c);
  FUN_0089120c(DAT_00fab13c);
  ExceptionList = local_10;
  return;
}

