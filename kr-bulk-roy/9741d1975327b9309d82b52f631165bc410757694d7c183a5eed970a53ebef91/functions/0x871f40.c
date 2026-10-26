
undefined4 FUN_00871f40(void)

{
  undefined4 uVar1;
  int *unaff_ESI;
  undefined4 local_28;
  
  (**(code **)(*unaff_ESI + 0x10))();
  if (local_28 == 1) {
    (**(code **)(*unaff_ESI + 0x5c))();
    return 0;
  }
  if (local_28 != 2) {
    if (local_28 == 3) {
      (**(code **)(*unaff_ESI + 0x7c))();
      uVar1 = FUN_008fed10();
      return uVar1;
    }
    return 0;
  }
  (**(code **)(*unaff_ESI + 0x6c))();
  return 0;
}

