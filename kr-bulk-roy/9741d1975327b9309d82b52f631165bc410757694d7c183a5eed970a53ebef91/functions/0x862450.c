
void FUN_00862450(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  char cVar2;
  int in_ECX;
  undefined4 *unaff_EDI;
  undefined1 local_ac [4];
  undefined4 *local_a8;
  int local_a4;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009224db;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00fba922 == '\0') {
    FUN_00861f50(local_14);
    DAT_00fba922 = '\x01';
  }
  *unaff_EDI = 0;
  if ((in_ECX != 0) && (0 < param_2)) {
    FUN_00781a00(local_ac,param_1);
    local_8 = 0;
    cVar2 = FUN_00781c40(in_ECX,param_2);
    if (cVar2 == '\0') {
      local_8 = 0xffffffff;
      FUN_00781b20();
    }
    else {
      if (local_a4 - (int)local_a8 >> 2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      (**(code **)(*(int *)*local_a8 + 4))();
      if (local_a4 - (int)local_a8 >> 2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      uVar1 = *local_a8;
      *local_a8 = 0;
      *unaff_EDI = uVar1;
      local_8 = 0xffffffff;
      FUN_00781b20();
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

