
void FUN_008c1da0(int param_1,int param_2,short param_3)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  short *psVar3;
  int unaff_ESI;
  
  uVar2 = in_EAX >> 9;
  if ((int)uVar2 < 0) {
    uVar2 = -uVar2;
  }
  if ((*(byte *)(unaff_ESI + 0x3e4) & 2) == 0) {
    if (0xff < (int)uVar2) {
LAB_008c1de4:
      uVar2 = 0xff;
    }
  }
  else {
    uVar2 = uVar2 & 0x1ff;
    if (uVar2 < 0x101) {
      if (uVar2 == 0x100) goto LAB_008c1de4;
    }
    else {
      uVar2 = 0x200 - uVar2;
    }
  }
  param_1 = param_1 + *(int *)(unaff_ESI + 8);
  param_2 = param_2 + *(int *)(unaff_ESI + 0x10);
  if (0x7ffe < param_1) {
    param_1 = 0x7fff;
  }
  if (0x7ffffffe < param_2) {
    param_2 = 0x7fffffff;
  }
  if (uVar2 == 0) {
    return;
  }
  iVar1 = *(int *)(unaff_ESI + 0x4d0);
  psVar3 = (short *)(unaff_ESI + 0x40a + iVar1 * 6);
  if (iVar1 < 1) {
LAB_008c1e60:
    if ((*(int *)(unaff_ESI + 0x4dc) == param_2) && (iVar1 < 0x20)) {
      psVar3 = psVar3 + 3;
      goto LAB_008c1eb1;
    }
  }
  else if (*(int *)(unaff_ESI + 0x4dc) == param_2) {
    if (((uint)(ushort)psVar3[1] + (int)*psVar3 == param_1) && (*(byte *)(psVar3 + 2) == uVar2)) {
      psVar3[1] = psVar3[1] + param_3;
      return;
    }
    goto LAB_008c1e60;
  }
  if ((*(code **)(unaff_ESI + 0x4d4) != (code *)0x0) && (0 < iVar1)) {
    (**(code **)(unaff_ESI + 0x4d4))
              (*(undefined4 *)(unaff_ESI + 0x4dc),iVar1,unaff_ESI + 0x410,
               *(undefined4 *)(unaff_ESI + 0x4d8));
  }
  *(undefined4 *)(unaff_ESI + 0x4d0) = 0;
  *(int *)(unaff_ESI + 0x4dc) = param_2;
  psVar3 = (short *)(unaff_ESI + 0x410);
LAB_008c1eb1:
  *psVar3 = (short)param_1;
  psVar3[1] = param_3;
  *(char *)(psVar3 + 2) = (char)uVar2;
  *(int *)(unaff_ESI + 0x4d0) = *(int *)(unaff_ESI + 0x4d0) + 1;
  return;
}

