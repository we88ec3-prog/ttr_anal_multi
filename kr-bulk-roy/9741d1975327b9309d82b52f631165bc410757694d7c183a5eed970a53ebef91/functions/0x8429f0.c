
int * FUN_008429f0(int *param_1,int *param_2)

{
  int *piVar1;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00904ef1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0xd) {
    local_8 = 1;
    if (param_2 != (int *)0x0) {
      param_2[0xb] = 0;
      param_2[0xc] = 0;
      piVar1 = (int *)*in_ECX;
      *param_2 = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      param_2[1] = in_ECX[1];
      param_2[2] = in_ECX[2];
      param_2[3] = in_ECX[3];
      param_2[4] = in_ECX[4];
      param_2[5] = in_ECX[5];
      param_2[6] = in_ECX[6];
      param_2[7] = in_ECX[7];
      param_2[8] = in_ECX[8];
      param_2[10] = in_ECX[10];
      param_2[0xb] = in_ECX[0xb];
      param_2[0xc] = in_ECX[0xc];
    }
    param_2 = param_2 + 0xd;
  }
  ExceptionList = local_10;
  return param_2;
}

