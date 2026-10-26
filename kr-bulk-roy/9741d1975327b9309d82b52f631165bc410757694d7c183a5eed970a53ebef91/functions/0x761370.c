
void FUN_00761370(undefined4 param_1,short *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  short sVar1;
  short *psVar2;
  int *in_ECX;
  
  FUN_00745a50(param_1,param_3,param_4,param_5,param_6,param_7,param_8);
  (**(code **)(*in_ECX + 0x180))();
  psVar2 = param_2;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00761550(in_ECX,param_2,(int)psVar2 - (int)(param_2 + 1) >> 1);
  return;
}

