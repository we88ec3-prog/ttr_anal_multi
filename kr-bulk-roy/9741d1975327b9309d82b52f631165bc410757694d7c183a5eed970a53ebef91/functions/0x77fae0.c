
void FUN_0077fae0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  uint uVar6;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907c00;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar6 = param_3 - param_2 >> 2;
  if (uVar6 != 0) {
    iVar3 = in_ECX[1] - *in_ECX >> 2;
    if (0x3fffffffU - iVar3 < uVar6) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    uVar1 = iVar3 + uVar6;
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
      iVar4 = FUN_007d01e0();
      local_8 = 0;
      uVar5 = FUN_0077fa30(param_1,iVar4,param_3);
      uVar5 = FUN_0077fca0(param_2,param_3,uVar5,param_3);
      FUN_0077fa30(in_ECX[1],uVar5,param_3);
      local_8 = 0xffffffff;
      iVar3 = in_ECX[1];
      iVar2 = *in_ECX;
      if (iVar2 != 0) {
        FUN_00872f80();
        FUN_0089120c(*in_ECX);
      }
      in_ECX[2] = iVar4 + local_18 * 4;
      in_ECX[1] = iVar4 + (uVar6 + (iVar3 - iVar2 >> 2)) * 4;
      *in_ECX = iVar4;
      ExceptionList = local_10;
      return;
    }
    FUN_0077fca0(param_2,param_3,in_ECX[1],param_3);
    iVar2 = in_ECX[1];
    iVar3 = uVar6 * 4 + iVar2;
    if ((param_1 != iVar2) && (iVar2 != iVar3)) {
      FUN_00860950(param_1,iVar3);
    }
    in_ECX[1] = in_ECX[1] + uVar6 * 4;
  }
  ExceptionList = local_10;
  return;
}

