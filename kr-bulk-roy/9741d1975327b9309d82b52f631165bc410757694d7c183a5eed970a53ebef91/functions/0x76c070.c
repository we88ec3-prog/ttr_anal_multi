
void FUN_0076c070(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int *in_ECX;
  
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x180))();
  in_ECX[0x29] = (int)piVar1;
  (**(code **)(*piVar1 + 0x38))(0,0xc3,param_3,param_4,param_5,param_6);
  (**(code **)(*in_ECX + 0x74))(in_ECX[0x29]);
  return;
}

