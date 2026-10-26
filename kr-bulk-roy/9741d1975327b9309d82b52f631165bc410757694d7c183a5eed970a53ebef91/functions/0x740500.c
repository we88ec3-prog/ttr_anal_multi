
uint FUN_00740500(void)

{
  longlong lVar1;
  uint in_EAX;
  undefined4 uVar2;
  uint uVar3;
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0x14) != 0) && (*(int *)(unaff_ESI + 0x2c) == 0)) {
    lVar1 = (ulonglong)(uint)(*(int *)(unaff_ESI + 8) * *(int *)(unaff_ESI + 0xc)) * 4;
    uVar2 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
    *(undefined4 *)(unaff_ESI + 0x2c) = uVar2;
    *(int *)(unaff_ESI + 0x30) = *(int *)(unaff_ESI + 0xc) * 4;
    uVar3 = FUN_007403e0(unaff_ESI);
    return uVar3;
  }
  return in_EAX & 0xffffff00;
}

