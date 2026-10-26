
void FUN_0075afd0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                 int param_6,undefined4 param_7)

{
  int *piVar1;
  int *in_ECX;
  
  FUN_00745a50(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  in_ECX[0x36] = param_5 - param_3;
  in_ECX[0x38] = param_5 - param_3;
  in_ECX[0x37] = param_6 - param_4;
  in_ECX[0x39] = param_6 - param_4;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x180))();
  in_ECX[0x20] = (int)piVar1;
  (**(code **)(*piVar1 + 0x38))(0xb,0x1c3,0,0,in_ECX[4] - in_ECX[2],in_ECX[5] - in_ECX[3]);
  return;
}

