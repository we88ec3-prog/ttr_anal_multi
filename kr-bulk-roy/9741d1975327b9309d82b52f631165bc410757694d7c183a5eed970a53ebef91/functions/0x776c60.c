
uint FUN_00776c60(void)

{
  uint uVar1;
  int *unaff_ESI;
  uint local_8;
  
  local_8 = 0;
  FUN_00429860(&local_8);
  uVar1 = (**(code **)(*unaff_ESI + 4))();
  if (local_8 == uVar1) {
    uVar1 = (**(code **)(*unaff_ESI + 0x14))();
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}

