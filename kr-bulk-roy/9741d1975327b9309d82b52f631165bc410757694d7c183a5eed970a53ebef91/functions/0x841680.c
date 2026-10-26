
void FUN_00841680(undefined *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090bd00;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (&DAT_00e6c2b4 < param_1) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((undefined *)((in_ECX[2] - *in_ECX) / 0x11c) < param_1) {
    iVar3 = FUN_00841820();
    local_8 = 0;
    FUN_00842b90(in_ECX[1],iVar3,param_1);
    local_8 = 0xffffffff;
    iVar1 = *in_ECX;
    iVar2 = in_ECX[1];
    if (iVar1 != 0) {
      FUN_00842540(iVar1,in_ECX[1],param_1);
      FUN_0089120c(*in_ECX);
    }
    in_ECX[2] = (int)param_1 * 0x11c + iVar3;
    in_ECX[1] = ((iVar2 - iVar1) / 0x11c) * 0x11c + iVar3;
    *in_ECX = iVar3;
  }
  ExceptionList = local_10;
  return;
}

