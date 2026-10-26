
void FUN_00704b40(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  puVar4 = (undefined1 *)FUN_006f6210();
  if ((param_1 + 0x83 <= (int *)*param_1) && (iVar5 = FUN_006f6af0(), iVar5 != 0)) {
    FUN_006f6b60(param_1);
  }
  *(undefined1 *)*param_1 = 0x22;
  *param_1 = *param_1 + 1;
  piVar1 = param_1;
  do {
    if (piVar1 == (int *)0x0) {
      if ((param_1 + 0x83 <= (int *)*param_1) && (iVar5 = FUN_006f6af0(), iVar5 != 0)) {
        FUN_006f6b60(param_1);
      }
      *(undefined1 *)*param_1 = 0x22;
      *param_1 = *param_1 + 1;
      return;
    }
    piVar1 = (int *)((int)piVar1 + -1);
    switch(*puVar4) {
    case 0:
      FUN_006f6c40(&DAT_00c43354,4);
      break;
    default:
      if ((param_1 + 0x83 <= (int *)*param_1) &&
         (iVar5 = *param_1 + (-0xc - (int)param_1), iVar5 != 0)) {
        iVar2 = param_1[2];
        if (*(uint *)(*(int *)(iVar2 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar2 + 0x10) + 0x44)) {
          FUN_006fb3a0();
        }
        puVar3 = *(undefined4 **)(iVar2 + 8);
        uVar6 = FUN_006fec70(iVar2,param_1 + 3,iVar5);
        *puVar3 = uVar6;
        puVar3[2] = 4;
        *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 0x10;
        param_1[1] = param_1[1] + 1;
        *param_1 = (int)(param_1 + 3);
        FUN_006f6b60(param_1);
      }
      *(undefined1 *)*param_1 = *puVar4;
      goto LAB_00704c79;
    case 10:
    case 0x22:
    case 0x5c:
      if ((param_1 + 0x83 <= (int *)*param_1) && (iVar5 = FUN_006f6af0(), iVar5 != 0)) {
        FUN_006f6b60(param_1);
      }
      *(undefined1 *)*param_1 = 0x5c;
      *param_1 = *param_1 + 1;
      if ((param_1 + 0x83 <= (int *)*param_1) && (iVar5 = FUN_006f6af0(), iVar5 != 0)) {
        FUN_006f6b60(param_1);
      }
      *(undefined1 *)*param_1 = *puVar4;
LAB_00704c79:
      *param_1 = *param_1 + 1;
      break;
    case 0xd:
      FUN_006f6c40(&DAT_00c43350,2);
    }
    puVar4 = puVar4 + 1;
  } while( true );
}

