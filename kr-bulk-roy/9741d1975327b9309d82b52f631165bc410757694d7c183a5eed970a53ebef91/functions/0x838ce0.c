
void FUN_00838ce0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  void *_Dst;
  uint uVar3;
  undefined4 *in_ECX;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  puStack_c = &LAB_00905051;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbDxDynamicVBPool::vftable;
  local_8 = 2;
  piVar1 = (int *)in_ECX[2];
  piVar4 = (int *)in_ECX[1];
  while (piVar4 != piVar1) {
    puVar2 = (undefined4 *)*piVar4;
    piVar4 = piVar4 + 1;
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1,uVar3);
    }
  }
  _Dst = (void *)in_ECX[1];
  if (_Dst != (void *)in_ECX[2]) {
    FID_conflict__memcpy(_Dst,(void *)in_ECX[2],0);
    in_ECX[2] = _Dst;
  }
  piVar1 = (int *)in_ECX[0x16];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  FUN_0053d590();
  if (in_ECX[6] != 0) {
    FUN_0089120c(in_ECX[6]);
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if (in_ECX[1] != 0) {
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  ExceptionList = local_10;
  return;
}

