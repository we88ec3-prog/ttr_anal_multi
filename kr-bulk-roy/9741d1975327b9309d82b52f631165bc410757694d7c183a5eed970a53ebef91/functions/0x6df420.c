
undefined4 FUN_006df420(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  uVar1 = *param_1;
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return uVar1;
}

