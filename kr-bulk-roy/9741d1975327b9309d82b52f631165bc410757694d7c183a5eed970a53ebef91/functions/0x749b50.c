
void FUN_00749b50(int param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int *in_ECX;
  
  bVar1 = false;
  if ((in_ECX[2] != param_1) || (in_ECX[3] != param_2)) {
    bVar1 = true;
  }
  if ((in_ECX[4] - in_ECX[2] == param_3 - param_1) && (in_ECX[5] - in_ECX[3] == param_4 - param_2))
  {
    if (bVar1) {
      FUN_00745b80();
      in_ECX[2] = param_1;
      in_ECX[3] = param_2;
      in_ECX[4] = param_3;
      in_ECX[5] = param_4;
      FUN_00746f70();
      FUN_00745b80();
    }
  }
  else {
    FUN_00745b80();
    in_ECX[2] = param_1;
    in_ECX[3] = param_2;
    in_ECX[4] = param_3;
    in_ECX[5] = param_4;
    FUN_00746f70();
    FUN_00749920(in_ECX);
    if ((*(byte *)((int)in_ECX + 0x2a) & 1) == 0) {
      FUN_00745b80();
    }
    else {
      (**(code **)(*in_ECX + 0x11c))();
      (**(code **)(*in_ECX + 0x118))();
      (**(code **)(*in_ECX + 0xcc))();
    }
    if (((uint)in_ECX[10] >> 0xf & 1) != 0) {
      (**(code **)(*in_ECX + 0x120))();
      (**(code **)(*in_ECX + 0x124))();
      return;
    }
  }
  return;
}

