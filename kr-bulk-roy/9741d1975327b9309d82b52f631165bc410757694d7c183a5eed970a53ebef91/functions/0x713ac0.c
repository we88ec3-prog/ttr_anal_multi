
undefined4 FUN_00713ac0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  iVar1 = in_ECX[5];
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x2c));
    if (((*(int *)(iVar1 + 0x54) != 0) &&
        (iVar2 = *(int *)(iVar1 + 0x54) + -1, *(int *)(iVar1 + 0x54) = iVar2, iVar2 == 0)) &&
       (*(int *)(iVar1 + 0x50) != 0)) {
      FUN_00717ae0();
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x2c));
  }
  (**(code **)*in_ECX)(1);
  return 1;
}

