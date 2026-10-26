
undefined4 FUN_008b9860(int *param_1,uint param_2,void *param_3,uint param_4)

{
  uint _Size;
  undefined4 uVar1;
  
  if ((uint)param_1[1] <= param_2) {
    return 0x55;
  }
  if ((code *)param_1[5] == (code *)0x0) {
    _Size = param_1[1] - param_2;
    if (param_4 < _Size) {
      _Size = param_4;
    }
    FID_conflict__memcpy(param_3,(void *)(*param_1 + param_2),_Size);
  }
  else {
    _Size = (*(code *)param_1[5])(param_1,param_2,param_3,param_4);
  }
  param_1[2] = _Size + param_2;
  uVar1 = 0x55;
  if (param_4 <= _Size) {
    uVar1 = 0;
  }
  return uVar1;
}

