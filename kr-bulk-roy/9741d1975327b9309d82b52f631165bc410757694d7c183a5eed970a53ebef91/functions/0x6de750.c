
void FUN_006de750(uint param_1)

{
  size_t sVar1;
  int iVar2;
  undefined4 *_Dst;
  void *pvVar3;
  uint uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  
  iVar2 = param_1;
  uVar6 = *(uint *)(param_1 + 8);
  param_1 = 1;
  if (uVar6 == 0xfffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("deque<T> too long");
  }
  uVar4 = uVar6 >> 1;
  if (uVar4 < 8) {
    uVar4 = 8;
  }
  else if (uVar4 < 2) goto LAB_006de7a0;
  if (uVar6 <= 0xfffffff - uVar4) {
    param_1 = uVar4;
  }
LAB_006de7a0:
  uVar6 = *(uint *)(iVar2 + 0xc) >> 2;
  _Dst = (undefined4 *)FUN_006de8b0();
  iVar7 = uVar6 * 4;
  pvVar3 = (void *)(iVar7 + *(int *)(iVar2 + 4));
  sVar1 = ((*(int *)(iVar2 + 8) * 4 - (int)pvVar3) + *(int *)(iVar2 + 4) >> 2) * 4;
  pvVar3 = FID_conflict__memcpy(_Dst + uVar6,pvVar3,sVar1);
  pvVar3 = (void *)((int)pvVar3 + sVar1);
  if (param_1 < uVar6) {
    FID_conflict__memcpy(pvVar3,*(void **)(iVar2 + 4),((int)(param_1 * 4) >> 2) * 4);
    pvVar3 = (void *)(*(int *)(iVar2 + 4) + param_1 * 4);
    sVar1 = ((iVar7 - (int)pvVar3) + *(int *)(iVar2 + 4) >> 2) * 4;
    pvVar3 = FID_conflict__memcpy(_Dst,pvVar3,sVar1);
    puVar8 = (undefined4 *)(sVar1 + (int)pvVar3);
    uVar6 = param_1;
  }
  else {
    sVar1 = (iVar7 >> 2) * 4;
    pvVar3 = FID_conflict__memcpy(pvVar3,*(void **)(iVar2 + 4),sVar1);
    puVar5 = (undefined4 *)((int)pvVar3 + sVar1);
    iVar7 = param_1 - uVar6;
    puVar8 = _Dst;
    if (iVar7 != 0) {
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
    }
  }
  if (uVar6 != 0) {
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
  }
  if (*(int *)(iVar2 + 4) != 0) {
    FUN_0089120c(*(int *)(iVar2 + 4));
  }
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + param_1;
  *(undefined4 **)(iVar2 + 4) = _Dst;
  return;
}

