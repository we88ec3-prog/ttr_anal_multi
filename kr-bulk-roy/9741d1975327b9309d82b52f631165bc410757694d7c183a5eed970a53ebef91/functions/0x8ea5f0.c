
undefined4 FUN_008ea5f0(int param_1,byte *param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  
  pcVar3 = "interpreter-version";
  do {
    bVar1 = *param_2;
    bVar4 = bVar1 < (byte)*pcVar3;
    if (bVar1 != *pcVar3) {
LAB_008ea620:
      iVar2 = (1 - (uint)bVar4) - (uint)(bVar4 != 0);
      goto LAB_008ea625;
    }
    if (bVar1 == 0) break;
    bVar1 = param_2[1];
    bVar4 = bVar1 < (byte)pcVar3[1];
    if (bVar1 != pcVar3[1]) goto LAB_008ea620;
    param_2 = param_2 + 2;
    pcVar3 = pcVar3 + 2;
  } while (bVar1 != 0);
  iVar2 = 0;
LAB_008ea625:
  if (iVar2 != 0) {
    return 0xc;
  }
  if (*param_3 != 0x23) {
    return 7;
  }
  *(undefined4 *)(param_1 + 0x44) = 0x23;
  return 0;
}

