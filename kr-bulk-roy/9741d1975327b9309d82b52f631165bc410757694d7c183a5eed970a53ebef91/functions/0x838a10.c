
void FUN_00838a10(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00905078;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbDxDynamicVB::vftable;
  local_8 = 0;
  if ((in_ECX[5] != 0) && (piVar1 = (int *)in_ECX[2], piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x30))(piVar1,uVar2);
    in_ECX[5] = 0;
  }
  piVar1 = (int *)in_ECX[2];
  in_ECX[4] = 0;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[2] = 0;
  }
  local_8 = 0xffffffff;
  *in_ECX = gbDxVB::vftable;
  if ((in_ECX[5] != 0) && (piVar1 = (int *)in_ECX[2], piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x30))(piVar1);
    in_ECX[5] = 0;
  }
  piVar1 = (int *)in_ECX[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  piVar1 = (int *)in_ECX[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  ExceptionList = local_10;
  return;
}

