
size_t FUN_008b98e0(int *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  uint _Size;
  size_t sVar2;
  
  uVar1 = param_1[2];
  _Size = 0;
  if (uVar1 < (uint)param_1[1]) {
    if ((code *)param_1[5] != (code *)0x0) {
      sVar2 = (*(code *)param_1[5])(param_1,uVar1,param_2,param_3);
      param_1[2] = param_1[2] + sVar2;
      return sVar2;
    }
    _Size = param_1[1] - uVar1;
    if (param_3 < _Size) {
      _Size = param_3;
    }
    FID_conflict__memcpy(param_2,(void *)(*param_1 + uVar1),_Size);
    param_1[2] = param_1[2] + _Size;
  }
  return _Size;
}

