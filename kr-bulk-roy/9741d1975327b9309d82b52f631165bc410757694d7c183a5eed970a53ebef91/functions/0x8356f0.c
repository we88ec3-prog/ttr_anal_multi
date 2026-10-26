
void FUN_008356f0(int *param_1)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009050d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  uVar1 = (param_1[1] - *param_1) / 0xc;
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  if (uVar1 != 0) {
    if (0x15555555 < uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    iVar2 = FUN_0085e740();
    in_ECX[2] = iVar2 + uVar1 * 0xc;
    local_8 = 0;
    *in_ECX = iVar2;
    in_ECX[1] = iVar2;
    iVar2 = FUN_00825d90(*param_1,param_1[1],param_1);
    in_ECX[1] = iVar2;
  }
  ExceptionList = local_10;
  return;
}

