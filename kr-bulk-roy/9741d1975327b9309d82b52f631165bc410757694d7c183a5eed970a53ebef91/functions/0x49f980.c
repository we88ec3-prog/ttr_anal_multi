
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049f980(void)

{
  int *piVar1;
  int *piVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908980;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_004e0fc0(&DAT_00fb72b8,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar2 = (int *)*DAT_00fb72c8;
  *DAT_00fb72c8 = (int)DAT_00fb72c8;
  DAT_00fb72c8[1] = (int)DAT_00fb72c8;
  _DAT_00fb72cc = 0;
  if (piVar2 != DAT_00fb72c8) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != DAT_00fb72c8);
  }
  FUN_0089120c(DAT_00fb72c8);
  local_8 = 2;
  FUN_005540c0(*DAT_00fb72bc,DAT_00fb72bc);
  FUN_0089120c(DAT_00fb72bc);
  ExceptionList = local_10;
  return;
}

