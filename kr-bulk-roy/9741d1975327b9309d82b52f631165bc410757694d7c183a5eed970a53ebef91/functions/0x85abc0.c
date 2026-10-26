
undefined4 FUN_0085abc0(int param_1)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  iVar3 = *(int *)(param_1 + 0x24);
  iVar8 = *(int *)(param_1 + 0x20);
  do {
    if (iVar8 == iVar3) {
      return 1;
    }
    iVar4 = FUN_00855c20();
    if (iVar4 == 0) {
      switch(*(undefined4 *)(iVar8 + 4)) {
      case 1:
        iVar6 = 1;
        break;
      case 2:
      case 3:
      case 0xb:
      case 0xc:
      case 0xd:
        iVar6 = 4;
        break;
      case 4:
        pcVar5 = *(char **)(iVar8 + 0xc);
        pcVar1 = pcVar5 + 1;
        do {
          cVar2 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        iVar6 = (int)pcVar5 - (int)pcVar1;
        break;
      case 5:
      case 10:
        iVar6 = 8;
        break;
      case 6:
        iVar6 = 0xc;
        break;
      case 7:
        iVar6 = 0x10;
        break;
      case 8:
        iVar6 = 0x30;
        break;
      case 9:
        iVar6 = 0x40;
        break;
      default:
        iVar6 = 0;
      }
      piVar9 = *(int **)(param_1 + 4);
      uVar11 = *(undefined4 *)(iVar8 + 8);
      uVar10 = *(undefined4 *)(iVar8 + 0xc);
      pcVar7 = *(code **)(*piVar9 + 0x50);
LAB_0085accb:
      (*pcVar7)(piVar9,uVar10,uVar11,iVar6);
    }
    else if (*(int *)(iVar8 + 4) == *(int *)(iVar4 + 4)) {
      switch(*(int *)(iVar4 + 4)) {
      case 1:
        iVar6 = 1;
        break;
      case 2:
      case 3:
      case 0xb:
      case 0xc:
      case 0xd:
        iVar6 = 4;
        break;
      case 4:
        pcVar5 = *(char **)(iVar4 + 0xc);
        pcVar1 = pcVar5 + 1;
        do {
          cVar2 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar2 != '\0');
        iVar6 = (int)pcVar5 - (int)pcVar1;
        break;
      case 5:
      case 10:
        iVar6 = 8;
        break;
      case 6:
        iVar6 = 0xc;
        break;
      case 7:
        iVar6 = 0x10;
        break;
      case 8:
        iVar6 = 0x30;
        break;
      case 9:
        iVar6 = 0x40;
        break;
      default:
        iVar6 = 0;
      }
      piVar9 = *(int **)(param_1 + 4);
      uVar11 = *(undefined4 *)(iVar4 + 8);
      uVar10 = *(undefined4 *)(iVar4 + 0xc);
      pcVar7 = *(code **)(*piVar9 + 0x50);
      goto LAB_0085accb;
    }
    iVar8 = iVar8 + 0x10;
  } while( true );
}

