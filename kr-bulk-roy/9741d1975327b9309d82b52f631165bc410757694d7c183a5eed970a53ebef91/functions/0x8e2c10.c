
void FUN_008e2c10(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  char cVar4;
  char *pcVar5;
  int iVar6;
  char unaff_BL;
  int *unaff_ESI;
  
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  pcVar5 = (char *)FUN_008e22e0();
  iVar1 = *(int *)(pcVar5 + 8);
  iVar2 = *(int *)(pcVar5 + 4);
  iVar6 = iVar1 - iVar2;
  if (iVar6 == -0x150000) {
    if (unaff_BL == '\0') {
LAB_008e2c56:
      *unaff_ESI = 0;
      goto LAB_008e2c9c;
    }
    *unaff_ESI = 1;
  }
  else {
    if (iVar6 == -0x140000) {
      if (unaff_BL == '\0') {
        unaff_ESI[2] = iVar2;
        *unaff_ESI = 2;
        goto LAB_008e2c9c;
      }
      goto LAB_008e2c56;
    }
    if (iVar6 < 0) {
      if (unaff_BL == '\0') {
        unaff_ESI[2] = iVar2;
        *unaff_ESI = 8;
        goto LAB_008e2c9c;
      }
      *unaff_ESI = 4;
    }
    else {
      if (unaff_BL != '\0') {
        unaff_ESI[2] = iVar2;
        *unaff_ESI = 4;
        goto LAB_008e2c9c;
      }
      *unaff_ESI = 8;
    }
  }
  unaff_ESI[2] = iVar1;
LAB_008e2c9c:
  cVar4 = FUN_008e0ee0();
  if (cVar4 != '\0') {
    unaff_ESI[2] = unaff_ESI[2] + *(int *)(param_2 + 0xbc) * 2;
  }
  unaff_ESI[2] = unaff_ESI[2] + param_3;
  unaff_ESI[4] = param_4;
  unaff_ESI[1] = param_1;
  if ((*unaff_ESI != 0) && (*pcVar5 != '\0')) {
    cVar4 = FUN_008e0ee0();
    if (cVar4 != '\0') {
      unaff_ESI[3] = *(int *)(pcVar5 + 0x10);
      FUN_008e0f20();
      return;
    }
    unaff_ESI[3] = *(int *)(pcVar5 + 0xc);
    FUN_008e0f20();
    return;
  }
  lVar3 = (longlong)unaff_ESI[2] * (longlong)param_4 +
          (ulonglong)((int)((longlong)unaff_ESI[2] * (longlong)param_4 >> 0x3f) + 0x8000);
  unaff_ESI[3] = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
  return;
}

