
void FUN_007890b0(void)

{
  uint uVar1;
  uint in_EAX;
  uint *unaff_ESI;
  
  uVar1 = unaff_ESI[1];
  if ((in_EAX < uVar1) && (*unaff_ESI <= in_EAX)) {
    if (uVar1 == unaff_ESI[2]) {
      FUN_00788180(1);
    }
    FUN_0078af80();
    unaff_ESI[1] = unaff_ESI[1] + 0x2c;
    return;
  }
  if (uVar1 == unaff_ESI[2]) {
    FUN_00788180(1);
  }
  FUN_0078af80();
  unaff_ESI[1] = unaff_ESI[1] + 0x2c;
  return;
}

