
int * FUN_0077fa30(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009057d1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 1) {
    local_8 = 1;
    if (param_2 != (int *)0x0) {
      piVar1 = (int *)*in_ECX;
      *param_2 = (int)piVar1;
      if (piVar1 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar1 + 8))();
        if (iVar2 == 0) {
          iVar2 = (**(code **)(*(int *)*param_2 + 0xc))();
          *param_2 = iVar2;
        }
        *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
      }
    }
    param_2 = param_2 + 1;
  }
  ExceptionList = local_10;
  return param_2;
}

