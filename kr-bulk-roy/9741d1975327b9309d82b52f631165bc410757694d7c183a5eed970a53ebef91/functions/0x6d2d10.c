
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d2d10(void)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091611a;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (DAT_00fdf66c != 0) {
    FUN_0089120c(DAT_00fdf66c,uVar2);
  }
  DAT_00fdf66c = 0;
  _DAT_00fdf670 = 0;
  _DAT_00fdf674 = 0;
  local_8._0_1_ = 4;
  FUN_005540c0(*DAT_00fdf654,DAT_00fdf654);
  FUN_0089120c(DAT_00fdf654,uVar2);
  local_8._0_1_ = 5;
  FUN_005540c0(*DAT_00fdf644,DAT_00fdf644);
  FUN_0089120c(DAT_00fdf644);
  local_8 = CONCAT31(local_8._1_3_,6);
  FUN_005540c0(*DAT_00fdf634,DAT_00fdf634);
  FUN_0089120c(DAT_00fdf634);
  piVar3 = (int *)*DAT_00fdf624;
  *DAT_00fdf624 = (int)DAT_00fdf624;
  DAT_00fdf624[1] = (int)DAT_00fdf624;
  _DAT_00fdf628 = 0;
  if (piVar3 != DAT_00fdf624) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != DAT_00fdf624);
  }
  FUN_0089120c(DAT_00fdf624);
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(&DAT_00fdf3f4,0x10,3,FUN_006d2cb0);
  ExceptionList = local_10;
  return;
}

