
void FUN_006492c0(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  size_t _Size;
  int *piVar3;
  uint in_EAX;
  int iVar4;
  uint uVar5;
  void *pvVar6;
  uint uVar7;
  void *pvVar8;
  undefined4 *puVar9;
  void *_Src;
  
  piVar3 = param_1;
  if (in_EAX != 0) {
    pvVar6 = (void *)param_1[1];
    iVar4 = (int)pvVar6 - *param_1 >> 2;
    if (0x3fffffffU - iVar4 < in_EAX) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    uVar7 = iVar4 + in_EAX;
    uVar5 = param_1[2] - *param_1 >> 2;
    if (uVar5 < uVar7) {
      if (0x3fffffff - (uVar5 >> 1) < uVar5) {
        param_1 = (int *)0x0;
      }
      else {
        param_1 = (int *)(uVar5 + (uVar5 >> 1));
      }
      if (param_1 < uVar7) {
        param_1 = (int *)uVar7;
      }
      pvVar6 = (void *)FUN_007d01e0();
      iVar4 = *piVar3;
      FUN_0041bd80();
      FID_conflict__memcpy(pvVar6,(void *)*piVar3,((int)param_2 - *piVar3 >> 2) * 4);
      FID_conflict__memcpy
                ((void *)((int)pvVar6 + (((int)param_2 - iVar4 >> 2) + in_EAX) * 4),param_2,
                 (piVar3[1] - (int)param_2 >> 2) * 4);
      iVar4 = *piVar3;
      iVar1 = piVar3[1];
      if (iVar4 != 0) {
        FUN_0089120c(iVar4);
      }
      *piVar3 = (int)pvVar6;
      piVar3[2] = (int)((int)pvVar6 + (int)param_1 * 4);
      piVar3[1] = (int)((int)pvVar6 + (in_EAX + (iVar1 - iVar4 >> 2)) * 4);
      return;
    }
    uVar7 = (int)pvVar6 - (int)param_2 >> 2;
    if (uVar7 < in_EAX) {
      uVar2 = *param_3;
      FID_conflict__memcpy(param_2 + in_EAX,param_2,uVar7 * 4);
      FUN_0041bd80();
      param_1[1] = param_1[1] + in_EAX * 4;
      puVar9 = (undefined4 *)(param_1[1] + in_EAX * -4);
      if (param_2 != puVar9) {
        do {
          *param_2 = uVar2;
          param_2 = param_2 + 1;
        } while (param_2 != puVar9);
        return;
      }
    }
    else {
      uVar2 = *param_3;
      _Src = (void *)((int)pvVar6 + in_EAX * -4);
      _Size = ((int)pvVar6 - (int)_Src >> 2) * 4;
      pvVar8 = FID_conflict__memcpy(pvVar6,_Src,_Size);
      param_1[1] = (int)((int)pvVar8 + _Size);
      iVar4 = (int)_Src - (int)param_2 >> 2;
      FID_conflict__memcpy((void *)((int)pvVar6 + iVar4 * -4),param_2,iVar4 * 4);
      puVar9 = param_2;
      if (param_2 != param_2 + in_EAX) {
        do {
          *puVar9 = uVar2;
          puVar9 = puVar9 + 1;
        } while (puVar9 != param_2 + in_EAX);
      }
    }
  }
  return;
}

