
uint FUN_00538820(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint in_EAX;
  undefined4 uVar1;
  uint uVar2;
  int in_ECX;
  
  if (in_ECX == 0) {
    return in_EAX & 0xffffff00;
  }
  uVar1 = FUN_00537df0(param_1,param_3);
  FUN_00538270(in_ECX,uVar1);
  uVar2 = FUN_005387c0(in_EAX,param_2);
  return uVar2;
}

