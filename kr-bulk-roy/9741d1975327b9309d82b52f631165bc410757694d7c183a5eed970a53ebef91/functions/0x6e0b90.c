
void FUN_006e0b90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int unaff_ESI;
  bool bVar1;
  
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar1 = DAT_00d63d09 != '\0';
  *(undefined4 *)(unaff_ESI + 0x2e4) = param_1;
  *(undefined4 *)(unaff_ESI + 0x2e8) = param_2;
  *(undefined4 *)(unaff_ESI + 0x2ec) = param_3;
  *(undefined4 *)(unaff_ESI + 0x2f0) = param_4;
  *(undefined4 *)(unaff_ESI + 0x2f4) = param_5;
  *(undefined4 *)(unaff_ESI + 0x2f8) = param_6;
  if (bVar1) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return;
}

