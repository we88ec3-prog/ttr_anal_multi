
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00799570(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a332;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 6;
  if (DAT_00fb7740 != 0) {
    FUN_0089120c(DAT_00fb7740,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fb7740 = 0;
  }
  iVar2 = DAT_00fb7744;
  if (DAT_00fb7744 != 0) {
    FUN_007b30f0(DAT_00fb7744);
    FUN_0089120c(iVar2);
    DAT_00fb7744 = 0;
  }
  if (DAT_00fb7748 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fb7748)(1);
    DAT_00fb7748 = (undefined4 *)0x0;
  }
  uVar4 = 0;
  DAT_00fb79ac = 1;
  if (DAT_00fb79e0 != 0) {
    do {
      SetEvent(*(HANDLE *)(DAT_00fb79b0 + uVar4 * 4));
      uVar4 = uVar4 + 1;
    } while (uVar4 < DAT_00fb79e0);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fb771c);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fb7704);
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
  if (DAT_00fb76b0 != 0) {
    FUN_0089120c(DAT_00fb76b0);
    DAT_00fb76b0 = 0;
  }
  if (DAT_00fb76ac != 0) {
    FUN_0089120c(DAT_00fb76ac);
    DAT_00fb76ac = 0;
  }
  FUN_006ee330();
  if (DAT_00fb7974 != 0) {
    FUN_0089120c(DAT_00fb7974);
  }
  DAT_00fb7974 = 0;
  DAT_00fb7978 = 0;
  _DAT_00fb797c = 0;
  local_8._0_1_ = 3;
  _eh_vector_destructor_iterator_(&DAT_00fb7774,0x10,0x20,FUN_00418290);
  local_8._0_1_ = 7;
  FUN_0079c020(*DAT_00fb7768,DAT_00fb7768);
  FUN_0089120c(DAT_00fb7768);
  local_8 = CONCAT31(local_8._1_3_,8);
  FUN_0079c020(*DAT_00fb7758,DAT_00fb7758);
  FUN_0089120c(DAT_00fb7758);
  piVar3 = (int *)*DAT_00fb76d0;
  *DAT_00fb76d0 = (int)DAT_00fb76d0;
  DAT_00fb76d0[1] = (int)DAT_00fb76d0;
  _DAT_00fb76d4 = 0;
  if (piVar3 != DAT_00fb76d0) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != DAT_00fb76d0);
  }
  FUN_0089120c(DAT_00fb76d0);
  local_8 = 9;
  FUN_0057ffd0(*DAT_00fb76c4,DAT_00fb76c4);
  FUN_0089120c(DAT_00fb76c4);
  ExceptionList = local_10;
  return;
}

