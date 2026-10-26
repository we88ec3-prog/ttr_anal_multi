
undefined4
FUN_00766bc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int *piVar1;
  char cVar2;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x24) != 0) &&
      (piVar1 = *(int **)(*(int *)(in_ECX + 0x24) + 0x165b4), piVar1 != (int *)0x0)) &&
     (cVar2 = (**(code **)(*piVar1 + 0x1c))(), cVar2 != '\0')) {
    switch(param_3) {
    case 8:
      FUN_00767400();
      *param_5 = 1;
      return 0;
    case 0x21:
      FUN_00767160();
      *param_5 = 1;
      return 0;
    case 0x22:
      FUN_00767220();
      *param_5 = 1;
      return 0;
    case 0x23:
      FUN_00766d50();
      *param_5 = 1;
      return 0;
    case 0x24:
      FUN_00766dd0();
      *param_5 = 1;
      return 0;
    case 0x25:
      FUN_00766e10();
      *param_5 = 1;
      return 0;
    case 0x26:
      FUN_00766fd0();
      *param_5 = 1;
      return 0;
    case 0x27:
      FUN_00766ed0();
      *param_5 = 1;
      return 0;
    case 0x28:
      FUN_00767070();
      *param_5 = 1;
      return 0;
    case 0x2e:
      FUN_00767320();
    }
  }
  *param_5 = 1;
  return 0;
}

