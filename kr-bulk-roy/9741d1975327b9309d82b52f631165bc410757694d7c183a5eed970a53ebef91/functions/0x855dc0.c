
void FUN_00855dc0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  cVar1 = *(char *)((int)param_1 + 0x39);
  do {
    if (cVar1 != '\0') {
      return;
    }
    FUN_00855dc0(param_1[2]);
    piVar2 = (int *)*param_1;
    param_1[10] = (int)gbParam::vftable;
    switch(param_1[0xb]) {
    case 1:
    case 6:
    case 9:
    case 10:
    case 0xd:
      iVar3 = param_1[0xc];
      break;
    case 2:
    case 7:
    case 0xb:
      iVar3 = param_1[0xc];
      break;
    case 3:
    case 5:
    case 8:
    case 0xc:
      iVar3 = param_1[0xc];
      break;
    case 4:
      FUN_00891d3d(param_1[0xc]);
    default:
      goto switchD_00855df4_default;
    }
    FUN_0089120c(iVar3);
switchD_00855df4_default:
    param_1[0xc] = 0;
    if (param_1[0xd] != 0) {
      FUN_00891d3d(param_1[0xd]);
      param_1[0xd] = 0;
    }
    if (0xf < (uint)param_1[8]) {
      FUN_0089120c(param_1[3]);
    }
    param_1[8] = 0xf;
    param_1[7] = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    FUN_0089120c(param_1);
    cVar1 = *(char *)((int)piVar2 + 0x39);
    param_1 = piVar2;
  } while( true );
}

