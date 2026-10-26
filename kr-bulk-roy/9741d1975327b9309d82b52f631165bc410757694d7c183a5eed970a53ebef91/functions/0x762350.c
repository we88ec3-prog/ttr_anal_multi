
undefined4
FUN_00762350(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x24) != 0) &&
      (piVar1 = *(int **)(*(int *)(in_ECX + 0x24) + 0x165b4), piVar1 != (int *)0x0)) &&
     (cVar2 = (**(code **)(*piVar1 + 0x1c))(), cVar2 != '\0')) {
    switch(param_3) {
    case 8:
      FUN_00761db0(in_ECX);
      *param_5 = 1;
      return 0;
    default:
      goto switchD_00762399_caseD_9;
    case 0x21:
      puVar3 = (undefined4 *)FUN_00891268(0x14);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = FoxUI::FXUIEvent::vftable;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0x3ee;
      }
      break;
    case 0x22:
      puVar3 = (undefined4 *)FUN_00891268(0x14);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = FoxUI::FXUIEvent::vftable;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0x3ef;
      }
      break;
    case 0x23:
      FUN_00761f60();
      *param_5 = 1;
      return 0;
    case 0x24:
      FUN_00761ef0();
      *param_5 = 1;
      return 0;
    case 0x25:
      FUN_00761a20();
      *param_5 = 1;
      return 0;
    case 0x27:
      FUN_00761b00();
      *param_5 = 1;
      return 0;
    case 0x2e:
      FUN_00761c70(in_ECX);
      *param_5 = 1;
      return 0;
    }
    FUN_00748900();
  }
switchD_00762399_caseD_9:
  *param_5 = 1;
  return 0;
}

