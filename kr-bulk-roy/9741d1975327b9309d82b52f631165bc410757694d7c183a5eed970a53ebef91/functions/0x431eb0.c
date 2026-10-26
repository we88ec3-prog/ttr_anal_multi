
short FUN_00431eb0(short param_1)

{
  void *pvVar1;
  int *piVar2;
  short *psVar3;
  void *_Src;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *_Dst;
  int in_ECX;
  uint uVar7;
  
  if ((*(byte *)(in_ECX + 0x40) & 8) != 0) {
    uVar7 = **(uint **)(in_ECX + 0x24);
    if ((uVar7 != 0) && (uVar5 = *(uint *)(in_ECX + 0x3c), uVar7 < uVar5)) {
      iVar6 = **(int **)(in_ECX + 0x34);
      **(uint **)(in_ECX + 0x24) = uVar5;
      **(int **)(in_ECX + 0x34) = (int)((uVar7 + iVar6 * 2) - uVar5) >> 1;
    }
  }
  if (param_1 == -1) {
    return 0;
  }
  uVar7 = **(uint **)(in_ECX + 0x24);
  if ((uVar7 != 0) && (piVar2 = *(int **)(in_ECX + 0x34), uVar7 < uVar7 + *piVar2 * 2)) {
    *piVar2 = *piVar2 + -1;
    psVar3 = (short *)**(int **)(in_ECX + 0x24);
    **(int **)(in_ECX + 0x24) = (int)(psVar3 + 1);
    *psVar3 = param_1;
    return param_1;
  }
  if ((*(byte *)(in_ECX + 0x40) & 2) != 0) {
    return -1;
  }
  if (uVar7 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = (int)((**(int **)(in_ECX + 0x34) * 2 - **(int **)(in_ECX + 0x10)) + uVar7) >> 1;
  }
  uVar5 = uVar7 >> 1;
  if (uVar5 < 0x20) {
    uVar5 = 0x20;
  }
  else if (uVar5 == 0) {
    return -1;
  }
  do {
    if (uVar7 <= 0x7fffffff - uVar5) break;
    uVar5 = uVar5 >> 1;
  } while (uVar5 != 0);
  if (uVar5 == 0) {
    return -1;
  }
  iVar6 = uVar5 + uVar7;
  _Dst = (void *)FUN_0044b7d0(iVar6);
  _Src = (void *)**(undefined4 **)(in_ECX + 0x10);
  if ((uVar7 == 0) || (FID_conflict__memcpy(_Dst,_Src,uVar7 * 2), uVar7 == 0)) {
    *(void **)(in_ECX + 0x3c) = _Dst;
    **(undefined4 **)(in_ECX + 0x14) = _Dst;
    **(undefined4 **)(in_ECX + 0x24) = _Dst;
    **(int **)(in_ECX + 0x34) = iVar6 * 2 >> 1;
    if ((*(byte *)(in_ECX + 0x40) & 4) == 0) {
      **(undefined4 **)(in_ECX + 0x10) = _Dst;
      **(undefined4 **)(in_ECX + 0x20) = _Dst;
      **(undefined4 **)(in_ECX + 0x30) = 1;
      goto LAB_0043206a;
    }
  }
  else {
    *(void **)(in_ECX + 0x3c) = (void *)((int)_Dst + (*(int *)(in_ECX + 0x3c) - (int)_Src >> 1) * 2)
    ;
    iVar4 = **(int **)(in_ECX + 0x24);
    **(int **)(in_ECX + 0x14) = (int)((int)_Dst + (**(int **)(in_ECX + 0x14) - (int)_Src >> 1) * 2);
    pvVar1 = (void *)((int)_Dst + (iVar4 - (int)_Src >> 1) * 2);
    **(int **)(in_ECX + 0x24) = (int)pvVar1;
    **(int **)(in_ECX + 0x34) = (iVar6 * 2 - (int)pvVar1) + (int)_Dst >> 1;
    if ((*(byte *)(in_ECX + 0x40) & 4) == 0) {
      iVar6 = **(int **)(in_ECX + 0x24);
      pvVar1 = (void *)((int)_Dst + (**(int **)(in_ECX + 0x20) - (int)_Src >> 1) * 2);
      **(undefined4 **)(in_ECX + 0x10) = _Dst;
      **(int **)(in_ECX + 0x20) = (int)pvVar1;
      **(int **)(in_ECX + 0x30) = (iVar6 - (int)pvVar1) + 2 >> 1;
      goto LAB_0043206a;
    }
  }
  **(undefined4 **)(in_ECX + 0x10) = _Dst;
  **(undefined4 **)(in_ECX + 0x20) = 0;
  **(int **)(in_ECX + 0x30) = (int)_Dst >> 1;
LAB_0043206a:
  if ((*(byte *)(in_ECX + 0x40) & 1) != 0) {
    FUN_0089120c(_Src);
  }
  *(uint *)(in_ECX + 0x40) = *(uint *)(in_ECX + 0x40) | 1;
  **(int **)(in_ECX + 0x34) = **(int **)(in_ECX + 0x34) + -1;
  psVar3 = (short *)**(int **)(in_ECX + 0x24);
  **(int **)(in_ECX + 0x24) = (int)(psVar3 + 1);
  *psVar3 = param_1;
  return param_1;
}

