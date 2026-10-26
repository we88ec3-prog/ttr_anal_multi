
undefined4 * FUN_00830630(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907000;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  *param_1 = GameData::CRouteSourceBnd::vftable;
  param_1[1] = 0;
  param_1[2] = 0;
  if ((param_3 != (int *)0x0) && (cVar2 = FUN_0047c250(uVar3), cVar2 != '\0')) {
    FUN_007a31c0(param_2,param_3);
  }
  local_8 = 0xffffffff;
  if (param_3 != (int *)0x0) {
    LOCK();
    iVar1 = param_3[1] + -1;
    param_3[1] = iVar1;
    UNLOCK();
    if (iVar1 == 0) {
      (**(code **)*param_3)();
      LOCK();
      iVar1 = param_3[2] + -1;
      param_3[2] = iVar1;
      UNLOCK();
      if (iVar1 == 0) {
        (**(code **)(*param_3 + 4))();
      }
    }
  }
  ExceptionList = local_10;
  return param_1;
}

