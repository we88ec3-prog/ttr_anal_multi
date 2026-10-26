
void FUN_00770090(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = param_4;
  uVar1 = param_3;
  (**(code **)(*in_ECX + 0x10))(&param_4,&param_3,param_3,param_4);
  if (param_2 < param_4) {
    (**(code **)(*in_ECX + 0x18))(param_1,(in_ECX[0xb] - param_2) + param_4,uVar1,iVar2);
    return;
  }
  *param_1 = 0;
  return;
}

