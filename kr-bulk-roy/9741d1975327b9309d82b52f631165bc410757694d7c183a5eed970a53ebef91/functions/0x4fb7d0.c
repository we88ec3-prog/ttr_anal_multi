
void FUN_004fb7d0(void)

{
  undefined4 *unaff_ESI;
  
  if ((HANDLE)*unaff_ESI != (HANDLE)0xffffffff) {
    WaitForSingleObject((HANDLE)*unaff_ESI,0xffffffff);
    CloseHandle((HANDLE)*unaff_ESI);
    *unaff_ESI = 0xffffffff;
    if ((undefined4 *)unaff_ESI[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)unaff_ESI[2])(1);
    }
    unaff_ESI[2] = 0;
  }
  FUN_0089120c();
  return;
}

