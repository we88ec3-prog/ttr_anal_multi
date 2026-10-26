
void FUN_005633b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_14;
  uint local_10;
  undefined4 local_c;
  
  local_14 = param_1;
  FUN_0082ef00(&local_14);
  if ((local_10 != *(int *)(in_ECX + 0x1c)) &&
     (piVar1 = *(int **)(local_10 + 0x10), piVar1 != (int *)0x0)) {
    iVar3 = piVar1[0x39];
    local_10 = piVar1[0x38] & 0x7fffffff;
    local_c = CONCAT31(local_c._1_3_,(char)iVar3);
    (**(code **)(*DAT_00fba7a4 + 0x20))();
    pcVar2 = *(code **)(*piVar1 + 0x58);
    piVar1[0x38] = local_10;
    *(char *)(piVar1 + 0x39) = (char)iVar3;
    (*pcVar2)(local_c);
    local_14 = param_2;
    local_10 = param_3;
    (**(code **)(*piVar1 + 0x44))(&local_14,1);
    (**(code **)(*piVar1 + 0x58))(param_4);
    if ((piVar1[0xea] == 0) &&
       ((*(char *)(piVar1 + 0xe9) = (char)piVar1[0x2c], piVar1[0xdc] != 0 && (piVar1[0x57] != 0))))
    {
      iVar3 = *(int *)(piVar1[0x57] + 4);
      FUN_00444a90((char)piVar1[0x2c]);
      (**(code **)(iVar3 + 0xc))(param_3);
    }
    if (param_5 != 0) {
      (**(code **)(*piVar1 + 0x68))(param_6,0x3f800000);
    }
  }
  return;
}

