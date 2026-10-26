
uint FUN_00649250(void)

{
  int in_EAX;
  uint uVar1;
  uint uVar2;
  int unaff_EDI;
  int local_14;
  int local_10;
  
  FUN_007e8a90(&local_14,*(int *)(in_EAX + 0xa8) + 0x114);
  uVar1 = local_10 - local_14 >> 2;
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      if (**(int **)(local_14 + uVar2 * 4) == unaff_EDI) {
        if (local_14 != 0) {
          FUN_0089120c(local_14);
        }
        return uVar2;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  if (local_14 != 0) {
    FUN_0089120c(local_14);
  }
  return 0xffffffff;
}

