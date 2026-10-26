
int FUN_008bded0(undefined4 param_1,undefined4 param_2)

{
  int *in_EAX;
  int *piVar1;
  undefined4 *puVar2;
  undefined4 unaff_EBX;
  int local_8;
  
  piVar1 = (int *)FUN_008bdd10();
  local_8 = 0;
  if (*piVar1 != 0) {
    *(undefined4 *)(*piVar1 + 4) = param_1;
    return 0;
  }
  puVar2 = (undefined4 *)FUN_008baee0(param_2,8,&local_8);
  if (local_8 == 0) {
    *piVar1 = (int)puVar2;
    *puVar2 = unaff_EBX;
    puVar2[1] = param_1;
    if (in_EAX[2] < *in_EAX) {
      in_EAX[2] = in_EAX[2] + 1;
      return 0;
    }
    local_8 = FUN_008bddb0(param_2);
    if (local_8 == 0) {
      in_EAX[2] = in_EAX[2] + 1;
      return 0;
    }
  }
  return local_8;
}

