
/* WARNING: Removing unreachable block (ram,0x0084bdbc) */
/* WARNING: Removing unreachable block (ram,0x0084bdc0) */

void FUN_0084bd30(void)

{
  void *pvVar1;
  int iVar2;
  int *unaff_ESI;
  
  unaff_ESI[0x14] = 0;
  if (*unaff_ESI != unaff_ESI[1]) {
    iVar2 = FUN_00858240(unaff_ESI[1]);
    FUN_00516210(unaff_ESI[1]);
    unaff_ESI[1] = iVar2;
  }
  FUN_008509c0(*(undefined4 *)(unaff_ESI[5] + 4));
  *(int *)(unaff_ESI[5] + 4) = unaff_ESI[5];
  *(int *)unaff_ESI[5] = unaff_ESI[5];
  *(int *)(unaff_ESI[5] + 8) = unaff_ESI[5];
  unaff_ESI[6] = 0;
  pvVar1 = (void *)unaff_ESI[8];
  if (pvVar1 != (void *)unaff_ESI[9]) {
    FID_conflict__memcpy(pvVar1,(void *)unaff_ESI[9],0);
    unaff_ESI[9] = (int)pvVar1;
  }
  if (unaff_ESI[0xc] != unaff_ESI[0xd]) {
    unaff_ESI[0xd] = unaff_ESI[0xc];
  }
  pvVar1 = (void *)unaff_ESI[0x10];
  if (pvVar1 != (void *)unaff_ESI[0x11]) {
    FID_conflict__memcpy(pvVar1,(void *)unaff_ESI[0x11],0);
    unaff_ESI[0x11] = (int)pvVar1;
  }
  return;
}

