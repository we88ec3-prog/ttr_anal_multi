
void FUN_0046e070(void *param_1,void *param_2)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  int in_ECX;
  uint uVar7;
  int *unaff_ESI;
  uint local_8;
  
  uVar7 = in_ECX - (int)param_2 >> 2;
  if (uVar7 != 0) {
    iVar4 = unaff_ESI[1] - *unaff_ESI >> 2;
    if (0x3fffffffU - iVar4 < uVar7) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    uVar1 = iVar4 + uVar7;
    local_8 = unaff_ESI[2] - *unaff_ESI >> 2;
    if (local_8 < uVar1) {
      if (0x3fffffff - (local_8 >> 1) < local_8) {
        local_8 = 0;
      }
      else {
        local_8 = local_8 + (local_8 >> 1);
      }
      if (local_8 < uVar1) {
        local_8 = uVar1;
      }
      pvVar5 = (void *)FUN_007d01e0();
      sVar2 = ((int)param_1 - *unaff_ESI >> 2) * 4;
      pvVar6 = FID_conflict__memcpy(pvVar5,(void *)*unaff_ESI,sVar2);
      pvVar6 = FID_conflict__memcpy((void *)((int)pvVar6 + sVar2),param_2,uVar7 * 4);
      FID_conflict__memcpy
                ((void *)((int)pvVar6 + uVar7 * 4),param_1,(unaff_ESI[1] - (int)param_1 >> 2) * 4);
      iVar4 = *unaff_ESI;
      iVar3 = unaff_ESI[1];
      if (iVar4 != 0) {
        FUN_0089120c(iVar4);
      }
      *unaff_ESI = (int)pvVar5;
      unaff_ESI[2] = (int)((int)pvVar5 + local_8 * 4);
      unaff_ESI[1] = (int)((int)pvVar5 + (uVar7 + (iVar3 - iVar4 >> 2)) * 4);
      return;
    }
    sVar2 = uVar7 * 4;
    FID_conflict__memcpy((void *)unaff_ESI[1],param_2,sVar2);
    pvVar5 = (void *)unaff_ESI[1];
    if ((param_1 != pvVar5) && (pvVar5 != (void *)(sVar2 + (int)pvVar5))) {
      FUN_00474630(param_1,(void *)(sVar2 + (int)pvVar5));
    }
    unaff_ESI[1] = unaff_ESI[1] + sVar2;
  }
  return;
}

