
void FUN_006e0480(int param_1,undefined4 param_2)

{
  bool bVar1;
  
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar1 = DAT_00d63d09 != '\0';
  *(undefined4 *)(param_1 + 0x168) = param_2;
  if (bVar1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return;
}

