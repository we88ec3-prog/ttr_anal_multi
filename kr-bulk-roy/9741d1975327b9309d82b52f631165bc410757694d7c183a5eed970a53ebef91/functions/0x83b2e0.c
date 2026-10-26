
undefined4 FUN_0083b2e0(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_0083b440();
  if (piVar2 != (int *)0x0) {
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *piVar2 = 0;
    }
    return 1;
  }
  return 0;
}

