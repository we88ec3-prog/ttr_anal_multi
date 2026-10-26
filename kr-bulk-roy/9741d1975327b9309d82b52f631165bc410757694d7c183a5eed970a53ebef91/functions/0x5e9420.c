
int * FUN_005e9420(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,int param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9,undefined4 param_10)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = param_2;
  puVar2 = param_1;
  puStack_c = &LAB_0090f7d3;
  local_10 = ExceptionList;
  if (param_2 == -1) {
    return (int *)0x0;
  }
  ExceptionList = &local_10;
  if ((DAT_00f8d9a8 & 1) == 0) {
    DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
    local_8 = 0;
    FUN_00523540(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00521080(&DAT_00f8d9bc);
    _atexit((_func_4879 *)&LAB_00bccc50);
  }
  local_8 = 0xffffffff;
  param_1 = (undefined4 *)iVar1;
  FUN_008438c0(&param_1);
  if (in_ECX == DAT_00f8d9b0) {
    ExceptionList = local_10;
    return (int *)0x0;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if (iVar1 == 0) {
    ExceptionList = local_10;
    return (int *)0x0;
  }
  if ((char)param_6 == '\0') {
    if ((*(int *)(iVar1 + 8) == 0x10) || (*(int *)(iVar1 + 8) == 0x1c)) {
      param_6 = *(int *)(iVar1 + 0x60);
      iVar3 = FUN_004034e0();
      FUN_008438c0(&param_6);
      if ((param_1 == (undefined4 *)*(int *)(iVar3 + 4)) || (*(int *)((int)param_1 + 0x10) == 0))
      goto LAB_005e95df;
    }
    param_6 = FUN_005e9e90();
    if (param_6 != 0) {
      switch(*(undefined4 *)(iVar1 + 8)) {
      case 1:
        piVar6 = (int *)puVar2[9];
        break;
      case 2:
        piVar6 = (int *)puVar2[10];
        break;
      case 3:
      case 4:
      case 0x1b:
        piVar6 = (int *)puVar2[0xb];
        break;
      case 5:
      case 0xd:
      case 0x1a:
        piVar6 = (int *)puVar2[0xc];
        break;
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xe:
      case 0xf:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x1d:
      case 0x1e:
      case 0x1f:
      case 0x21:
      case 0x26:
      case 0x27:
      case 0x2c:
      case 0x2d:
      case 0x2e:
        piVar6 = (int *)puVar2[0xd];
        break;
      case 0xc:
        piVar6 = (int *)puVar2[0x11];
        break;
      case 0x10:
      case 0x19:
      case 0x1c:
        piVar6 = (int *)puVar2[0x10];
        break;
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x20:
      case 0x24:
      case 0x25:
        piVar6 = (int *)puVar2[0xe];
        break;
      default:
        piVar6 = (int *)0x0;
        break;
      case 0x28:
      case 0x29:
      case 0x2a:
      case 0x2b:
        piVar6 = (int *)puVar2[0xf];
      }
      piVar4 = puVar2 + 9;
      param_1 = (undefined4 *)0x9;
      do {
        (**(code **)(*(int *)*piVar4 + 0x94))((int *)*piVar4 == piVar6);
        piVar4 = piVar4 + 1;
        param_1 = (undefined4 *)((int)param_1 + -1);
      } while (param_1 != (undefined4 *)0x0);
      puVar5 = puVar2 + 0x12;
      param_1 = (undefined4 *)0x5;
      do {
        (**(code **)(*(int *)*puVar5 + 0x94))(puVar5[-9] == param_6);
        puVar5 = puVar5 + 1;
        param_1 = (undefined4 *)((int)param_1 + -1);
      } while (param_1 != (undefined4 *)0x0);
      iVar1 = puVar2[0x17];
      *(int **)(iVar1 + 0x15c) = piVar6;
      *(int *)(iVar1 + 0x160) = param_6;
      piVar6 = (int *)puVar2[0x17];
      param_1 = (undefined4 *)0x0;
      goto LAB_005e9626;
    }
  }
LAB_005e95df:
  switch(*(undefined4 *)(iVar1 + 8)) {
  case 1:
    piVar6 = (int *)*puVar2;
    break;
  case 2:
    piVar6 = (int *)puVar2[1];
    break;
  case 3:
  case 4:
  case 0x1b:
    piVar6 = (int *)puVar2[2];
    break;
  case 5:
  case 0xd:
  case 0x1a:
    piVar6 = (int *)puVar2[3];
    break;
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xe:
  case 0xf:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x21:
  case 0x26:
  case 0x27:
  case 0x2c:
  case 0x2d:
  case 0x2e:
    piVar6 = (int *)puVar2[4];
    break;
  case 0xc:
    piVar6 = (int *)puVar2[8];
    break;
  case 0x10:
  case 0x19:
  case 0x1c:
    piVar6 = (int *)puVar2[7];
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x20:
  case 0x24:
  case 0x25:
    piVar6 = (int *)puVar2[5];
    break;
  default:
    piVar6 = (int *)0x0;
    break;
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
    piVar6 = (int *)puVar2[6];
  }
LAB_005e9626:
  if (piVar6 != (int *)0x0) {
    (**(code **)(*piVar6 + 0x184))(param_2,param_3,param_4,param_5,param_7,param_8,param_9,param_10)
    ;
  }
  ExceptionList = local_10;
  return piVar6;
}

