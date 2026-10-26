
void FUN_00474490(void *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  int *in_ECX;
  int iVar5;
  uint uVar6;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009066d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar6 = param_3 - param_2 >> 2;
  if (uVar6 != 0) {
    iVar5 = in_ECX[1] - *in_ECX >> 2;
    if (0x3fffffffU - iVar5 < uVar6) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    uVar1 = iVar5 + uVar6;
    local_18 = in_ECX[2] - *in_ECX >> 2;
    if (local_18 < uVar1) {
      if (0x3fffffff - (local_18 >> 1) < local_18) {
        local_18 = 0;
      }
      else {
        local_18 = local_18 + (local_18 >> 1);
      }
      if (local_18 < uVar1) {
        local_18 = uVar1;
      }
      pvVar3 = (void *)FUN_007d01e0();
      local_8 = 0;
      FID_conflict__memcpy(pvVar3,(void *)*in_ECX,((int)param_1 - *in_ECX >> 2) * 4);
      pvVar4 = (void *)FUN_00412d40(param_2,param_3,param_3);
      FID_conflict__memcpy(pvVar4,param_1,(in_ECX[1] - (int)param_1 >> 2) * 4);
      iVar5 = *in_ECX;
      iVar2 = in_ECX[1];
      if (iVar5 != 0) {
        FUN_0089120c(iVar5);
      }
      in_ECX[2] = (int)((int)pvVar3 + local_18 * 4);
      in_ECX[1] = (int)((int)pvVar3 + (uVar6 + (iVar2 - iVar5 >> 2)) * 4);
      *in_ECX = (int)pvVar3;
      ExceptionList = local_10;
      return;
    }
    FUN_00412d40(param_2,param_3,param_3);
    pvVar4 = (void *)in_ECX[1];
    pvVar3 = (void *)(uVar6 * 4 + (int)pvVar4);
    if ((param_1 != pvVar4) && (pvVar4 != pvVar3)) {
      FUN_00474630(param_1,pvVar3);
    }
    in_ECX[1] = in_ECX[1] + uVar6 * 4;
  }
  ExceptionList = local_10;
  return;
}

