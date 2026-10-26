
undefined4
FUN_00769400(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if ((*(char *)((int)in_ECX + 0xc9) != '\0') && (param_2 == 0x100)) {
    uVar1 = (**(code **)(*in_ECX + 0x184))(param_1,0x100,param_3,param_4,param_5);
    return uVar1;
  }
  *param_5 = 0;
  return 1;
}

