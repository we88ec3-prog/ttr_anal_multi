
void FUN_0071cfe0(void *param_1)

{
  uint uVar1;
  size_t _Size;
  uint uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int unaff_ESI;
  int iVar5;
  
  iVar3 = *(int *)(unaff_ESI + 4);
  iVar4 = in_ECX - (int)param_1 >> 3;
  iVar5 = *(int *)(unaff_ESI + 8) - iVar3 >> 3;
  uVar2 = *(int *)(unaff_ESI + 0xc) - iVar3 >> 3;
  uVar1 = iVar4 + iVar5;
  if (uVar2 < uVar1) {
    iVar3 = FUN_0071be00(iVar3,uVar2 * 8);
    *(uint *)(unaff_ESI + 0xc) = uVar1 * 8 + iVar3;
    *(int *)(unaff_ESI + 4) = iVar3;
    *(int *)(unaff_ESI + 8) = iVar3 + iVar5 * 8;
  }
  _Size = iVar4 * 8;
  FID_conflict__memcpy(*(void **)(unaff_ESI + 8),param_1,_Size);
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + _Size;
  return;
}

