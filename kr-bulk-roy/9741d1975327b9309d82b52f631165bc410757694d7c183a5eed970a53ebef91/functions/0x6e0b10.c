
undefined1 FUN_006e0b10(int param_1)

{
  undefined1 uVar1;
  
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  uVar1 = *(undefined1 *)(param_1 + 0x2d1);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return uVar1;
}

