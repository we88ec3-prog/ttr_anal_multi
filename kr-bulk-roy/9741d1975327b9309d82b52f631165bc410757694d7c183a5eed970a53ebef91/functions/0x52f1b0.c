
void FUN_0052f1b0(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00904ac0;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  if (0x15555555 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)((in_ECX[2] - *in_ECX) / 0xc) < param_1) {
    iVar3 = FUN_0085e740();
    local_8 = 0;
    FUN_006ee5a0(*in_ECX,param_1);
    iVar1 = *in_ECX;
    iVar2 = in_ECX[1];
    if (iVar1 != 0) {
      FUN_0089120c(iVar1);
    }
    in_ECX[2] = iVar3 + param_1 * 0xc;
    in_ECX[1] = iVar3 + ((iVar2 - iVar1) / 0xc) * 0xc;
    *in_ECX = iVar3;
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

