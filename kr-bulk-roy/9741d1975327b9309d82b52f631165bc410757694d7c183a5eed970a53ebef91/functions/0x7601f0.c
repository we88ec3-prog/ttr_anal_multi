
void FUN_007601f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,undefined4 param_7)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x174))();
  in_ECX[0x29] = (int)piVar1;
  uVar2 = FUN_008fed10();
  (**(code **)(*piVar1 + 0x38))(0,0xc3,0,uVar2,(param_5 - param_3) / 2,param_6 - param_4);
  (**(code **)(*in_ECX + 0x74))(in_ECX[0x29]);
  return;
}

