
void FUN_0044a480(int *param_1,undefined4 *param_2)

{
  uint uVar1;
  void *_Src;
  int iVar2;
  undefined4 uVar3;
  size_t _Size;
  int *piVar4;
  undefined4 *in_EAX;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  void *pvVar8;
  undefined4 *puVar9;
  
  piVar4 = param_1;
  pvVar7 = (void *)param_1[1];
  iVar5 = (int)pvVar7 - *param_1 >> 2;
  if (iVar5 == 0x3fffffff) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  uVar1 = iVar5 + 1;
  uVar6 = param_1[2] - *param_1 >> 2;
  if (uVar1 <= uVar6) {
    if ((int)pvVar7 - (int)param_2 >> 2 == 0) {
      uVar3 = *in_EAX;
      FID_conflict__memcpy(param_2 + 1,param_2,0);
      FUN_0041bd80();
      param_1[1] = param_1[1] + 4;
      iVar5 = param_1[1];
      if (param_2 != (undefined4 *)(iVar5 + -4)) {
        do {
          *param_2 = uVar3;
          param_2 = param_2 + 1;
        } while (param_2 != (undefined4 *)(iVar5 + -4));
        return;
      }
    }
    else {
      uVar3 = *in_EAX;
      _Src = (void *)((int)pvVar7 + -4);
      _Size = ((int)pvVar7 - (int)_Src >> 2) * 4;
      pvVar8 = FID_conflict__memcpy(pvVar7,_Src,_Size);
      param_1[1] = (int)((int)pvVar8 + _Size);
      iVar5 = (int)_Src - (int)param_2 >> 2;
      FID_conflict__memcpy((void *)((int)pvVar7 + iVar5 * -4),param_2,iVar5 * 4);
      puVar9 = param_2;
      if (param_2 != param_2 + 1) {
        do {
          *puVar9 = uVar3;
          puVar9 = puVar9 + 1;
        } while (puVar9 != param_2 + 1);
      }
    }
    return;
  }
  if (0x3fffffff - (uVar6 >> 1) < uVar6) {
    param_1 = (int *)0x0;
  }
  else {
    param_1 = (int *)(uVar6 + (uVar6 >> 1));
  }
  if (param_1 < uVar1) {
    param_1 = (int *)uVar1;
  }
  pvVar7 = (void *)FUN_007d01e0();
  iVar5 = *piVar4;
  FUN_0041bd80();
  FID_conflict__memcpy(pvVar7,(void *)*piVar4,((int)param_2 - *piVar4 >> 2) * 4);
  FID_conflict__memcpy
            ((void *)((int)pvVar7 + ((int)param_2 - iVar5 >> 2) * 4 + 4),param_2,
             (piVar4[1] - (int)param_2 >> 2) * 4);
  iVar5 = *piVar4;
  iVar2 = piVar4[1];
  if (iVar5 != 0) {
    FUN_0089120c(iVar5);
  }
  *piVar4 = (int)pvVar7;
  piVar4[2] = (int)((int)pvVar7 + (int)param_1 * 4);
  piVar4[1] = (int)pvVar7 + (iVar2 - iVar5 >> 2) * 4 + 4;
  return;
}

