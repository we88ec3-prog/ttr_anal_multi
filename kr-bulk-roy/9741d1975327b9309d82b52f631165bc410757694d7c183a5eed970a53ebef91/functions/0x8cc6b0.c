
undefined4 FUN_008cc6b0(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  if (*(int *)(param_2 + 0x48) != *(int *)(param_1 + 0x10)) {
    return 6;
  }
  if (param_3 != 0) {
    FUN_008b9570(param_2 + 0x6c,param_3);
  }
  if (param_4 != (undefined4 *)0x0) {
    FUN_008b94d0(param_2 + 0x6c,*param_4,param_4[1]);
  }
  return 0;
}

