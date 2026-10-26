
undefined4 FUN_00541f10(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x10);
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    piVar2 = (int *)FUN_00542210();
    if ((int *)*piVar2 == (int *)0x0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)*piVar2;
    }
    uVar3 = (uint)piVar2[2] >> 2;
    if (*(uint *)(iVar5 + 8) <= uVar3) {
      uVar3 = uVar3 - *(uint *)(iVar5 + 8);
    }
    uVar4 = *(undefined4 *)(*(int *)(*(int *)(iVar5 + 4) + uVar3 * 4) + (piVar2[2] & 3U) * 4);
    *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + 1;
    if ((uint)(*(int *)(unaff_ESI + 8) * 4) <= *(uint *)(unaff_ESI + 0xc)) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
    iVar1 = iVar1 + -1;
    *(int *)(unaff_ESI + 0x10) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
      return uVar4;
    }
  }
  return uVar4;
}

