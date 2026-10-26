
uint FUN_0057d820(void)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  
  uVar1 = in_EAX - 1;
  iVar4 = 1;
  *(undefined4 *)(unaff_ESI + 0x74) = 1;
  switch(uVar1) {
  case 0:
    *(undefined4 *)(unaff_ESI + 0x14) = 0;
    *(undefined4 *)(unaff_ESI + 0x30) = 0;
    *(undefined4 *)(unaff_ESI + 0x4c) = 0;
    return uVar1;
  case 1:
    *(undefined4 *)(unaff_ESI + 0x14) = 1;
    *(undefined4 *)(unaff_ESI + 0x4c) = 1;
    *(undefined4 *)(unaff_ESI + 0x30) = 1;
    return uVar1;
  case 2:
    *(undefined4 *)(unaff_ESI + 0x14) = 2;
    *(undefined4 *)(unaff_ESI + 0x30) = 2;
    *(undefined4 *)(unaff_ESI + 0x4c) = 2;
    return uVar1;
  case 3:
    uVar1 = FUN_0089289d();
    uVar1 = uVar1 & 0x80000001;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    *(undefined4 *)(unaff_ESI + 0x14) = 0;
    *(undefined4 *)(unaff_ESI + 0x30) = 0;
    *(uint *)(unaff_ESI + 0x4c) = uVar1;
    return uVar1;
  case 4:
    uVar1 = FUN_0089289d();
    uVar1 = uVar1 & 0x80000001;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    break;
  case 5:
    uVar1 = FUN_0089289d();
    uVar1 = uVar1 & 0x80000001;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
    }
    *(undefined4 *)(unaff_ESI + 0x14) = 2;
    *(undefined4 *)(unaff_ESI + 0x30) = 2;
    *(uint *)(unaff_ESI + 0x4c) = -(uint)(uVar1 != 2) & uVar1;
    return uVar1;
  default:
    *(undefined4 *)(unaff_ESI + 0xf4) = 0;
    *(undefined4 *)(unaff_ESI + 0x74) = 0;
    iVar2 = FUN_0089289d();
    iVar2 = iVar2 % 3;
    if (iVar2 != 2) {
      iVar4 = iVar2 + 1;
    }
    iVar3 = FUN_0089289d();
    *(int *)(unaff_ESI + 0x14) = iVar2;
    *(int *)(unaff_ESI + 0x30) = iVar4;
    *(int *)(unaff_ESI + 0x4c) = iVar3 % 3;
    return iVar3 / 3;
  }
  if (uVar1 == 1) {
    uVar1 = 2;
  }
  *(undefined4 *)(unaff_ESI + 0x14) = 1;
  *(undefined4 *)(unaff_ESI + 0x30) = 1;
  *(uint *)(unaff_ESI + 0x4c) = uVar1;
  return uVar1;
}

