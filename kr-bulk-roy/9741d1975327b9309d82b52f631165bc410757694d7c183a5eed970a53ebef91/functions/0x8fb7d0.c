
undefined4 FUN_008fb7d0(int *param_1)

{
  int *piVar1;
  size_t _Size;
  
  piVar1 = (int *)*param_1;
  if ((code *)piVar1[5] == (code *)0x0) {
    _Size = piVar1[1] - piVar1[2];
    if (_Size < 0x1001) {
      if (_Size == 0) {
        return 0x55;
      }
    }
    else {
      _Size = 0x1000;
    }
    FID_conflict__memcpy(param_1 + 0x12,(void *)(*piVar1 + piVar1[2]),_Size);
  }
  else {
    _Size = (*(code *)piVar1[5])(piVar1,piVar1[2],param_1 + 0x12,0x1000);
    if (_Size == 0) {
      return 0x55;
    }
  }
  piVar1[2] = piVar1[2] + _Size;
  param_1[4] = _Size;
  param_1[3] = (int)(param_1 + 0x12);
  return 0;
}

