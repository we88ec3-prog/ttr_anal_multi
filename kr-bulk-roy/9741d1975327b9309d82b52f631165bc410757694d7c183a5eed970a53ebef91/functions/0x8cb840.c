
bool FUN_008cb840(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int unaff_ESI;
  int iVar5;
  bool bVar6;
  int local_8;
  
  *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x20) + -0x20;
  iVar5 = *(int *)(unaff_ESI + 0x28);
  *(int *)(unaff_ESI + 0x58) = iVar5;
  *(undefined4 *)(unaff_ESI + 0x5c) = 0;
  *(undefined2 *)(unaff_ESI + 0x56) = 0;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(int *)(iVar5 + 8) = iVar5;
  iVar5 = 0;
  *(undefined2 *)(unaff_ESI + 0x54) = 0;
  local_8 = 0;
  if (0 < *(short *)(unaff_ESI + 0x80)) {
    do {
      *(undefined4 *)(unaff_ESI + 100) = 0;
      *(undefined4 *)(unaff_ESI + 0x60) = 0;
      cVar3 = FUN_008cb500(iVar5,*(undefined2 *)(*(int *)(unaff_ESI + 0x8c) + local_8 * 2),param_1);
      if (cVar3 != '\0') {
        return true;
      }
      iVar4 = *(int *)(unaff_ESI + 4);
      uVar1 = *(uint *)(unaff_ESI + 0x48);
      iVar5 = *(short *)(*(int *)(unaff_ESI + 0x8c) + local_8 * 2) + 1;
      if (((((uVar1 & iVar4 - 1U) == 0) && (*(int *)(unaff_ESI + 0x4c) <= (int)uVar1)) &&
          ((int)uVar1 <= *(int *)(unaff_ESI + 0x50))) &&
         ((*(int *)(unaff_ESI + 0x60) != 0 &&
          (((*(uint *)(*(int *)(unaff_ESI + 0x58) + 0xc) ^
            *(uint *)(*(int *)(unaff_ESI + 0x60) + 0xc)) & 8) == 0)))) {
        *(int *)(unaff_ESI + 0x28) = *(int *)(unaff_ESI + 0x28) + -4;
      }
      iVar2 = *(int *)(unaff_ESI + 0x58);
      if ((*(byte *)(iVar2 + 0xc) & 8) == 0) {
        iVar4 = ((uVar1 - 1) + iVar4 & -iVar4) - uVar1;
        bVar6 = SBORROW4(iVar4,*(int *)(unaff_ESI + 8));
        iVar4 = iVar4 - *(int *)(unaff_ESI + 8);
      }
      else {
        iVar4 = uVar1 - (-iVar4 & uVar1);
        bVar6 = SBORROW4(iVar4,*(int *)(unaff_ESI + 8));
        iVar4 = iVar4 - *(int *)(unaff_ESI + 8);
      }
      cVar3 = FUN_008caa50(bVar6 == iVar4 < 0);
      if (cVar3 != '\0') {
        return true;
      }
      if (*(int *)(unaff_ESI + 0x60) != 0) {
        *(int *)(iVar2 + 0x1c) = *(int *)(unaff_ESI + 0x60);
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(short *)(unaff_ESI + 0x80));
  }
  cVar3 = FUN_008cab50();
  if (cVar3 != '\0') {
    return true;
  }
  return *(uint *)(unaff_ESI + 0x24) <= *(uint *)(unaff_ESI + 0x28);
}

