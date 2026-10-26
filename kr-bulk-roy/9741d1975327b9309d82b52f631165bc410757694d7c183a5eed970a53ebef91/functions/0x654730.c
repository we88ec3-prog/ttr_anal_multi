
undefined4 FUN_00654730(void)

{
  int iVar1;
  float fVar2;
  byte bVar3;
  int unaff_ESI;
  
  if ((uint)*(byte *)(unaff_ESI + 0x31) == *(byte *)(unaff_ESI + 2) - 1) {
    return 0;
  }
  fVar2 = *(float *)(unaff_ESI + 8) + *(float *)(unaff_ESI + 0xc);
  *(float *)(unaff_ESI + 0xc) = fVar2;
  if (fVar2 < 1.0) {
    return 1;
  }
  iVar1 = *(int *)(unaff_ESI + 0x34);
  if (iVar1 == 0) {
    bVar3 = *(byte *)(unaff_ESI + 0x31) + 1;
    *(byte *)(unaff_ESI + 0x31) = bVar3;
    *(undefined4 *)(unaff_ESI + 0x34) =
         *(undefined4 *)
          (*(int *)(*(int *)(unaff_ESI + 4) + (uint)*(byte *)(unaff_ESI + 0x30) * 4) +
          (uint)bVar3 * 4);
  }
  else {
    if (iVar1 == 1) {
      *(char *)(unaff_ESI + 0x30) = *(char *)(unaff_ESI + 0x30) + -1;
    }
    else {
      if (iVar1 != 2) goto LAB_00654798;
      *(char *)(unaff_ESI + 0x30) = *(char *)(unaff_ESI + 0x30) + '\x01';
    }
    *(undefined4 *)(unaff_ESI + 0x34) = 0;
  }
LAB_00654798:
  FUN_00443d10();
  if ((uint)*(byte *)(unaff_ESI + 0x31) == *(byte *)(unaff_ESI + 2) - 1) {
    *(undefined4 *)(unaff_ESI + 0xc) = 0;
    return 0;
  }
  *(float *)(unaff_ESI + 0xc) = *(float *)(unaff_ESI + 0xc) - 1.0;
  return 1;
}

