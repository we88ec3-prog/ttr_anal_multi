
void FUN_007e9bf0(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 in_EAX;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 *unaff_ESI;
  
  unaff_ESI[0x1c] = 0x4b7fffff;
  *unaff_ESI = IS3D::CEffectElement::vftable;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 1;
  unaff_ESI[3] = in_EAX;
  puVar3 = (undefined4 *)FUN_00891268(0x2c);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0x3f800000;
    puVar3[7] = 0x3f800000;
    puVar3[8] = 0x3f800000;
    puVar3[9] = 0x3f800000;
    puVar3[10] = 1;
  }
  unaff_ESI[0x1d] = puVar3;
  puVar3 = (undefined4 *)FUN_00891268(0x2c);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0x3f800000;
    puVar3[7] = 0x3f800000;
    puVar3[8] = 0x3f800000;
    puVar3[9] = 0x3f800000;
    puVar3[10] = 1;
  }
  unaff_ESI[0x1e] = puVar3;
  pcVar4 = "Effect/Object/";
  unaff_ESI[0x1f] = 0;
  unaff_ESI[0x20] = 0;
  do {
    cVar1 = *pcVar4;
    *(char *)((int)(unaff_ESI + -0x31428a) + (int)pcVar4) = cVar1;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar2 = 0x30 - (int)param_1;
  do {
    cVar1 = *param_1;
    param_1[(int)unaff_ESI + iVar2] = cVar1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}

