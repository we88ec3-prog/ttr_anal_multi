
void FUN_006d9970(void)

{
  float fVar1;
  int in_EAX;
  int iVar2;
  int unaff_EDI;
  
  if (0.0 < *(float *)(in_EAX + 0x34)) {
    if (DAT_00fba7cc == 0) {
      iVar2 = FUN_00891268(0x1380);
      if (iVar2 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    fVar1 = *(float *)(in_EAX + 0x34) - 1.0 / (float)*(int *)(DAT_00fba7cc + 0x1360);
    *(float *)(in_EAX + 0x34) = fVar1;
    if (fVar1 <= 0.0) {
      *(undefined4 *)(in_EAX + 0x34) = 0;
      FUN_006d9e10(unaff_EDI,in_EAX);
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0xb4));
    *(undefined4 *)(unaff_EDI + 0xa8) = 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_EDI + 0xb4));
  }
  return;
}

