
void FUN_00563660(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 in_XMM0_Da;
  
  FUN_0082ef00(&param_1);
  if ((in_ECX != *(int *)(in_ECX + 0x1c)) &&
     (piVar1 = *(int **)(in_ECX + 0x10), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x58))(param_2);
    if (param_3 == 0) {
      param_1 = CONCAT31(param_1._1_3_,(char)piVar1[0x2c]);
      if (((piVar1[0xea] == 0) && (*(char *)(piVar1 + 0xe9) = (char)piVar1[0x2c], piVar1[0xdc] != 0)
          ) && (piVar1[0x57] != 0)) {
        iVar2 = *(int *)(piVar1[0x57] + 4);
        FUN_00444a90(param_1);
        (**(code **)(iVar2 + 0xc))(in_XMM0_Da);
      }
    }
  }
  return;
}

