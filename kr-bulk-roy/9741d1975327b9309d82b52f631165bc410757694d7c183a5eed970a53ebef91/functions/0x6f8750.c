
char * FUN_006f8750(int param_1,int param_2,uint param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(*(int *)(param_2 + 4) + 8) == 6) {
    while( true ) {
      piVar1 = *(int **)(param_2 + 4);
      if (*(char *)(*piVar1 + 6) != '\0') break;
      iVar4 = *(int *)(*piVar1 + 0x10);
      if (piVar1[2] == 6) {
        if (param_2 == *(int *)(param_1 + 0x14)) {
          *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x18);
        }
        iVar5 = (*(int *)(param_2 + 0xc) - *(int *)(*(int *)(*piVar1 + 0x10) + 0xc) >> 2) + -1;
      }
      else {
        iVar5 = -1;
      }
      iVar2 = FUN_006fda20(param_3 + 1);
      *param_4 = iVar2;
      if (iVar2 != 0) {
        return "local";
      }
      uVar3 = FUN_006f82d0(iVar4,iVar5,param_3);
      switch(uVar3 & 0x3f) {
      case 0:
        param_3 = uVar3 >> 0x17;
        if ((uVar3 >> 6 & 0xff) <= param_3) {
          return (char *)0x0;
        }
        if (*(int *)(*(int *)(param_2 + 4) + 8) != 6) {
          return (char *)0x0;
        }
        break;
      default:
        goto switchD_006f87db_caseD_1;
      case 4:
        if (*(int *)(iVar4 + 0x1c) == 0) {
          *param_4 = (int)&DAT_00c42700;
          return "upvalue";
        }
        *param_4 = *(int *)(*(int *)(iVar4 + 0x1c) + (uVar3 >> 0x17) * 4) + 0x10;
        return "upvalue";
      case 5:
        *param_4 = *(int *)(*(int *)(iVar4 + 8) + (uVar3 >> 0xe) * 0x10) + 0x10;
        return "global";
      case 6:
        iVar4 = FUN_006f8720();
        *param_4 = iVar4;
        return "field";
      case 0xb:
        iVar4 = FUN_006f8720();
        *param_4 = iVar4;
        return "method";
      }
    }
  }
switchD_006f87db_caseD_1:
  return (char *)0x0;
}

