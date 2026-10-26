
undefined4 FUN_006d9a10(void)

{
  float fVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  switch(unaff_ESI[10]) {
  case 0:
    unaff_ESI[0xb] = 0x3f800000;
    return 0;
  case 1:
    fVar1 = (float)unaff_ESI[0xb];
    iVar2 = FUN_006df1b0();
    fVar1 = fVar1 - (1.0 / (float)iVar2) / (float)unaff_ESI[0xc];
    unaff_ESI[0xb] = (int)fVar1;
    if (*(char *)(unaff_EDI + 0x25) != '\0') {
      unaff_ESI[0xb] = (int)(fVar1 * 0.0);
    }
    iVar2 = 0;
    if ((float)unaff_ESI[0xb] <= 0.0) {
      unaff_ESI[10] = 2;
LAB_006d9a89:
      unaff_ESI[0xb] = iVar2;
    }
    break;
  case 2:
    unaff_ESI[0xb] = 0;
    if (*unaff_ESI == 0) {
      return 0;
    }
    unaff_ESI[0xd] = 0;
    return 0;
  case 3:
    iVar2 = FUN_006df1b0();
    fVar1 = (1.0 / (float)iVar2) / (float)unaff_ESI[0xc] + (float)unaff_ESI[0xb];
    unaff_ESI[0xb] = (int)fVar1;
    if (*(char *)(unaff_EDI + 0x25) != '\0') {
      unaff_ESI[0xb] = (int)(fVar1 * 0.0);
    }
    iVar2 = 0x3f800000;
    if (1.0 <= (float)unaff_ESI[0xb]) {
      unaff_ESI[10] = 0;
      goto LAB_006d9a89;
    }
    break;
  default:
    goto switchD_006d9a22_default;
  }
  if ((int *)*unaff_ESI != (int *)0x0) {
    (**(code **)(*(int *)*unaff_ESI + 0x4c))(unaff_ESI[0xb]);
    return 0;
  }
switchD_006d9a22_default:
  return 0;
}

