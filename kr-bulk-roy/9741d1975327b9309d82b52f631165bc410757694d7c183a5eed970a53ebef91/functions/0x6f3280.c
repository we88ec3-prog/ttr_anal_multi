
void FUN_006f3280(undefined4 *param_1,undefined2 *param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  undefined2 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090cb40;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = param_1[4];
  uVar3 = (int)param_2 - (int)in_ECX >> 1;
  if (((uVar1 <= uVar3) && (param_1[5] != uVar3)) && (cVar2 = FUN_00402610(uVar3,1), cVar2 != '\0'))
  {
    param_1[4] = uVar1;
    if (7 < (uint)param_1[5]) {
      param_1 = (undefined4 *)*param_1;
    }
    *(undefined2 *)((int)param_1 + uVar1 * 2) = 0;
  }
  local_8 = 0;
  for (; in_ECX != param_2; in_ECX = in_ECX + 1) {
    FUN_00440010(1,*in_ECX);
  }
  ExceptionList = local_10;
  return;
}

