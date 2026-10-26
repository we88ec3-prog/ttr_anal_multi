
void FUN_0081b720(void)

{
  void *pvVar1;
  undefined4 *unaff_ESI;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x11));
  *unaff_ESI = 0xf;
  pvVar1 = (void *)unaff_ESI[1];
  if (pvVar1 != (void *)unaff_ESI[2]) {
    FID_conflict__memcpy(pvVar1,(void *)unaff_ESI[2],0);
    unaff_ESI[2] = pvVar1;
  }
  pvVar1 = (void *)unaff_ESI[5];
  if (pvVar1 != (void *)unaff_ESI[6]) {
    FID_conflict__memcpy(pvVar1,(void *)unaff_ESI[6],0);
    unaff_ESI[6] = pvVar1;
  }
  pvVar1 = (void *)unaff_ESI[9];
  if (pvVar1 != (void *)unaff_ESI[10]) {
    FID_conflict__memcpy(pvVar1,(void *)unaff_ESI[10],0);
    unaff_ESI[10] = pvVar1;
  }
  pvVar1 = (void *)unaff_ESI[0xd];
  if (pvVar1 != (void *)unaff_ESI[0xe]) {
    FID_conflict__memcpy(pvVar1,(void *)unaff_ESI[0xe],0);
    unaff_ESI[0xe] = pvVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0x11));
  return;
}

