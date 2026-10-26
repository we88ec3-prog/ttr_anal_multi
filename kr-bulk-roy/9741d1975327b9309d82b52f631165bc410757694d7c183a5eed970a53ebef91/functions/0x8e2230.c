
undefined4 FUN_008e2230(void)

{
  undefined4 uVar1;
  uint unaff_EBX;
  undefined4 *unaff_ESI;
  int iVar2;
  int local_8;
  
  iVar2 = unaff_ESI[2] * unaff_EBX;
  local_8 = 0;
  if (unaff_EBX <= (uint)(0x7fffffff / (ulonglong)(uint)unaff_ESI[2])) {
    uVar1 = FUN_008bc7d0(*unaff_ESI,1,unaff_ESI[6],iVar2,unaff_ESI[7],&local_8);
    unaff_ESI[7] = uVar1;
    if (local_8 == 0) {
      unaff_ESI[3] = unaff_EBX;
      unaff_ESI[6] = iVar2;
      if (unaff_EBX < (uint)unaff_ESI[5]) {
        FUN_008e0760();
        unaff_ESI[5] = unaff_EBX;
        return 0;
      }
      return 1;
    }
  }
  FUN_008e0760();
  return 0;
}

