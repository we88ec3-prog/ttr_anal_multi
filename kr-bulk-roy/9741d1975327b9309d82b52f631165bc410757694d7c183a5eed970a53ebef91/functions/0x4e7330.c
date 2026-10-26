
void FUN_004e7330(uint param_1)

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
  puStack_c = &LAB_00906540;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  if (0x1fffffff < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)(in_ECX[2] - *in_ECX >> 3) < param_1) {
    iVar3 = FUN_0071a0c0();
    local_8 = 0;
    FUN_006d1d70(*in_ECX,param_1);
    iVar1 = *in_ECX;
    iVar2 = in_ECX[1];
    if (iVar1 != 0) {
      FUN_0089120c(iVar1);
    }
    in_ECX[2] = iVar3 + param_1 * 8;
    in_ECX[1] = iVar3 + (iVar2 - iVar1 >> 3) * 8;
    *in_ECX = iVar3;
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

