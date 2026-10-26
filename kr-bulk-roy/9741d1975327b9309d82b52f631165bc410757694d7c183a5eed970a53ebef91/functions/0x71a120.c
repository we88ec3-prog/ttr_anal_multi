
void FUN_0071a120(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  uint uVar5;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009059a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar5 = param_3 - param_2 >> 3;
  if (uVar5 != 0) {
    iVar4 = in_ECX[1] - *in_ECX >> 3;
    if (0x1fffffffU - iVar4 < uVar5) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    uVar1 = iVar4 + uVar5;
    local_18 = in_ECX[2] - *in_ECX >> 3;
    if (local_18 < uVar1) {
      if (0x1fffffff - (local_18 >> 1) < local_18) {
        local_18 = 0;
      }
      else {
        local_18 = local_18 + (local_18 >> 1);
      }
      if (local_18 < uVar1) {
        local_18 = uVar1;
      }
      iVar3 = FUN_0071a0c0();
      local_8 = 0;
      FUN_006d1d70(*in_ECX,param_3);
      FUN_0071a2b0(param_3);
      FUN_006d1d70(param_1,param_3);
      iVar4 = *in_ECX;
      iVar2 = in_ECX[1];
      if (iVar4 != 0) {
        FUN_0089120c(iVar4);
      }
      in_ECX[2] = iVar3 + local_18 * 8;
      in_ECX[1] = iVar3 + (uVar5 + (iVar2 - iVar4 >> 3)) * 8;
      *in_ECX = iVar3;
      ExceptionList = local_10;
      return;
    }
    FUN_0071a2b0(param_3);
    iVar2 = in_ECX[1];
    iVar4 = uVar5 * 8 + iVar2;
    if ((param_1 != iVar2) && (iVar2 != iVar4)) {
      FUN_0071a2d0(param_1,iVar2,iVar4);
    }
    in_ECX[1] = in_ECX[1] + uVar5 * 8;
  }
  ExceptionList = local_10;
  return;
}

