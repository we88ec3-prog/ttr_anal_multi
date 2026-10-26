
undefined4 FUN_005cafc0(void)

{
  undefined4 uVar1;
  uint in_EAX;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  *(uint *)(unaff_ESI + 0x1c) = in_EAX;
  *(short *)(unaff_ESI + 0x20) = (short)in_EAX;
  if ((in_EAX & 0x3ff) == 0x12) {
    local_c = 0;
    FUN_0082ef00(&local_c);
    if (local_8 != *(int *)(unaff_ESI + 0x4c)) {
      uVar1 = *(undefined4 *)(local_8 + 0x10);
      *(undefined4 *)(unaff_ESI + 0x24) = uVar1;
      return CONCAT31((int3)((uint)uVar1 >> 8),1);
    }
  }
  else {
    local_8 = 1;
    FUN_0082ef00(&local_8);
    if (local_c != *(int *)(unaff_ESI + 0x4c)) {
      uVar1 = *(undefined4 *)(local_c + 0x10);
      *(undefined4 *)(unaff_ESI + 0x24) = uVar1;
      return CONCAT31((int3)((uint)uVar1 >> 8),1);
    }
  }
  *(undefined4 *)(unaff_ESI + 0x24) = 0;
  return 1;
}

