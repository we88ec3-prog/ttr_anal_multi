
undefined4 FUN_008c1fd0(int param_1)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = __setjmp3(param_1 + 0x4e8,0);
  if (iVar1 == 0) {
    local_8 = FUN_008b9060(param_1 + 0x3d4,&PTR_FUN_00bd7cb0,param_1);
    if (*(int *)(param_1 + 0x28) == 0) {
      FUN_008c13d0();
      return local_8;
    }
  }
  else {
    local_8 = 0x40;
  }
  return local_8;
}

