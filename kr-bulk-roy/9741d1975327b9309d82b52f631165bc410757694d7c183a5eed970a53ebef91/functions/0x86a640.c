
void FUN_0086a640(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917ee1;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbParticle::vftable;
  local_8 = 2;
  if ((undefined4 *)in_ECX[0xd7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd7])(1,uVar1);
    in_ECX[0xd7] = 0;
  }
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  FUN_00878e90();
  *in_ECX = gbBase::vftable;
  if (0xf < (uint)in_ECX[7]) {
    FUN_0089120c(in_ECX[2]);
  }
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *in_ECX = gbRefCount::vftable;
  ExceptionList = local_10;
  return;
}

