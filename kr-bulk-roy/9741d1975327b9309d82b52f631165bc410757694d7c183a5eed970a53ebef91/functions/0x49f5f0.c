
void FUN_0049f5f0(void)

{
  int iVar1;
  uint in_ECX;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910a10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (0x3ffffff < in_ECX) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  if ((uint)(DAT_00fb72f4 - DAT_00fb72ec >> 6) < in_ECX) {
    iVar1 = FUN_0046f090();
    local_8 = 0;
    FUN_0049f770(DAT_00fb72f0,iVar1,iVar1);
    uVar2 = DAT_00fb72f0 - DAT_00fb72ec;
    if (DAT_00fb72ec != 0) {
      FUN_0041f320(DAT_00fb72f0,iVar1);
      FUN_0089120c(DAT_00fb72ec);
    }
    DAT_00fb72f4 = in_ECX * 0x40 + iVar1;
    DAT_00fb72f0 = (uVar2 & 0xffffffc0) + iVar1;
    DAT_00fb72ec = iVar1;
  }
  ExceptionList = local_10;
  return;
}

